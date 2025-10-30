#include "musicdbmanager.h"
#include "qdir.h"
#include<QBuffer>
MusicDBManager::MusicDBManager() {
    qDebug()<<"999";
    QString dbPath = "music_favorites.db";  // 直接放在程序运行目录下
    // 打开或创建 SQLite 数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);  // 数据库文件就在程序当前目录

    // 打开数据库
    if (!db.open()) {
        qDebug() << u8"数据库连接失败：" << db.lastError().text();
        return;
    }
    qDebug() << u8"SQLite 数据库连接成功，文件：" << db.databaseName();

    // 创建表（包含所有 MusicInfo 字段）
    QSqlQuery query;
    QString createTableSQL =
        "CREATE TABLE IF NOT EXISTS favorite_songs ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "  /* 自增主键，表内唯一 */
        "song_id INTEGER NOT NULL UNIQUE, "       /* 歌曲唯一标识，确保不重复收藏 */
        "wangyiyun_id INTEGER, "                  /* 网易云歌曲ID（可选） */
        "wangyiyun_url TEXT, "                    /* 网易云歌曲链接 */
        "local_url TEXT, "                        /* 本地音乐文件路径 */
        "title TEXT, "                            /* 歌曲标题 */
        "composer TEXT, "                         /* 作者/作曲 */
        "album TEXT, "                            /* 专辑名称 */
        "image_url TEXT, "                        /* 封面图片的URL或本地路径 */
        "duration INTEGER, "                      /* 歌曲时长（毫秒） */
        "size TEXT, "                             /* 文件大小，如 '3.2MB' */
        "add_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP"  /* 收藏时间 */
        ")";
    if (!query.exec(createTableSQL)) {
        qDebug() << u8"创建表失败：" << query.lastError().text();
        return;
    } else {
        qDebug() << u8"表已创建或已存在：favorite_songs";
    }
}
bool MusicDBManager::addLikedSong(const MusicInfo &info)
{
    // 1. 检查数据库连接状态
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << u8"添加失败：数据库未打开";
        return false;
    }

    QSqlQuery query;

    // 2. 检查歌曲是否已存在（通过 song_id 唯一判断）
    query.prepare("SELECT song_id FROM favorite_songs WHERE song_id = :song_id");
    query.bindValue(":song_id", info.getsongId());
    if (query.exec() && query.next()) {
        qDebug() << u8"歌曲已存在（ID:" << info.getsongId() << u8"），无需重复添加";
        return true;
    }
    // 检查查询是否执行失败（非“不存在”的情况）
    if (query.lastError().type() != QSqlError::NoError) {
        qDebug() << u8"检查歌曲是否存在失败：" << query.lastError().text();
        return false;
    }

    // 3. 插入数据（适配最新表结构，移除 image 字段）
    query.prepare(R"(
        INSERT INTO favorite_songs (
            song_id, wangyiyun_id, wangyiyun_url, local_url, title, composer,
            album, image_url, duration, size
        ) VALUES (
            :song_id, :wangyiyun_id, :wangyiyun_url, :local_url, :title, :composer,
            :album, :image_url, :duration, :size
        )
    )");

    // 4. 绑定参数（与表结构字段一一对应）
    query.bindValue(":song_id", info.getsongId());
    query.bindValue(":wangyiyun_id", info.getwangyiyun_id());
    query.bindValue(":wangyiyun_url", info.geturl().toString());
    query.bindValue(":local_url", info.geturl().toString());
    query.bindValue(":title", info.gettitle());
    query.bindValue(":composer", info.getcomposer());
    query.bindValue(":album", info.getalbum());
    query.bindValue(":image_url", info.getm_image_url().toString());
    query.bindValue(":duration", info.getduration());
    query.bindValue(":size", info.getsize());

    // 5. 执行插入并处理结果
    if (!query.exec()) {
        qDebug() << u8"添加歌曲失败（ID:" << info.getsongId() << u8"）：" << query.lastError().text();
        return false;
    }

    qDebug() << u8"歌曲添加成功（ID:" << info.getsongId() << u8"）";
    return true;
}

// 从数据库移除歌曲
bool MusicDBManager::removeLikedSong(qint64 songId) {
    // 1. 检查数据库连接状态（若未打开则尝试重新打开）
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen() && !db.open()) {
        qDebug() << u8"移除失败：数据库无法打开";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM favorite_songs WHERE song_id = :song_id");
    query.bindValue(":song_id", songId);

    // 2. 执行删除并检查结果
    if (!query.exec()) {
        qDebug() << u8"移除歌曲失败（ID:" << songId << u8"）：" << query.lastError().text();
        return false;
    }

    // 3. 检查是否真的删除了记录（处理“删除不存在的歌曲”的情况）
    if (query.numRowsAffected() == 0) {
        qDebug() << u8"歌曲ID" << songId << u8"不在喜欢列表中，无需删除";
        return true; // 视为成功（逻辑上无错误）
    }

    qDebug() << u8"歌曲移除成功（ID:" << songId << u8"）";
    return true;
}

// 从数据库加载所有喜欢的歌曲
QList<MusicInfo> MusicDBManager::getAllFavoriteSongs() {
    QList<MusicInfo> list;
    // 1. 检查数据库连接状态
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen() && !db.open()) {
        qDebug() << u8"加载失败：数据库无法打开";
        return list;
    }

    // 2. 执行查询（按添加时间倒序，最新的在前面）
    QSqlQuery query("SELECT * FROM favorite_songs ORDER BY add_time DESC");
    if (query.lastError().type() != QSqlError::NoError) {
        qDebug() << u8"查询喜欢歌曲失败：" << query.lastError().text();
        return list;
    }

    // 3. 遍历结果，映射到 MusicInfo
    while (query.next()) {
        MusicInfo info;
        // 基础字段映射
        info.setsongId(query.value("song_id").toLongLong());
        info.setwangyiyun_id(query.value("wangyiyun_id").toLongLong());
        info.setwangyiyun_url(QUrl(query.value("wangyiyun_url").toString()));
        info.setlocal_url(QUrl(query.value("local_url").toString()));
        info.setTitle(query.value("title").toString());
        info.setcomposer(query.value("composer").toString());
        info.setAlbum(query.value("album").toString());

        // 封面图片通过 image_url 后续加载（如从网络或本地路径）
        info.setm_image_url(QUrl(query.value("image_url").toString()));

        // 其他字段映射
        info.setDuration(query.value("duration").toLongLong());
        info.setSize(query.value("size").toString());
        info.setLike(true);//全部为喜欢
        list.append(info);
         qDebug() << u8"[加载中] 歌曲：" << info.gettitle();
    }

    qDebug() << u8"从数据库加载喜欢的歌曲共" << list.size() << u8"首";
    return list;
}

void MusicDBManager::setUrl(qint64 songId, QUrl url)
{
    // 1. 检查 URL 有效性和数据库连接状态
    if (url.isEmpty()) {
        qDebug() << u8"补全URL失败：传入的URL为空（歌曲ID:" << songId << u8"）";
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen() && !db.open()) {
        qDebug() << u8"补全URL失败：数据库无法打开（歌曲ID:" << songId << u8"）";
        return;
    }

    QSqlQuery query;

    // 2. 先检查歌曲是否存在（避免更新不存在的记录）
    query.prepare("SELECT song_id FROM favorite_songs WHERE song_id = :song_id");
    query.bindValue(":song_id", songId);
    if (!query.exec() || !query.next()) {
        qDebug() << u8"补全URL失败：歌曲ID" << songId << u8"不在数据库中";
        return;
    }

    // 3. 补全 URL（默认更新 local_url，如需更新 wangyiyun_url 可修改字段名）
    query.prepare(R"(
        UPDATE favorite_songs
        SET local_url = :local_url
        WHERE song_id = :song_id
    )");
    query.bindValue(":local_url", url.toString()); // 将 QUrl 转为字符串存入数据库
    query.bindValue(":song_id", songId);

    // 4. 执行更新并检查结果
    if (!query.exec()) {
        qDebug() << u8"补全URL失败（歌曲ID:" << songId << u8"）：" << query.lastError().text();
    } else if (query.numRowsAffected() > 0) {
        qDebug() << u8"歌曲ID" << songId << u8"补全URL成功，路径：" << url.toString();
    } else {
        qDebug() << u8"歌曲ID" << songId << u8"URL未更新（与现有值相同）";
    }
}
