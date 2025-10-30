#ifndef LIKEWIDELEGATE_H
#define LIKEWIDELEGATE_H

#include "qstyleditemdelegate.h"
class Likewidelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit Likewidelegate(QObject *parent = nullptr);

    // 重写尺寸提示（设置项高度）
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // 重写绘制函数（自定义项样式）
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    //editor委托专用过滤
    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option, const QModelIndex &index) override;
signals:
    void playButtonClicked(const QModelIndex &index);//播放
private:
    // 封装的播放按钮绘制函数
    void drawPlayButton(QPainter *painter, const QStyleOptionViewItem &option, const QRect &contentRect) const;
    // 计算播放按钮区域（供绘制和点击判断使用）
    QRect getPlayButtonRect(const QRect &contentRect) const;
    // 爱心按钮绘制和区域计算
    void drawLikeButton(QPainter *painter, const QStyleOptionViewItem &option,
                        const QRect &contentRect, const QModelIndex &index) const;
    QRect getLikeButtonRect(const QRect &contentRect) const;
    // 绘制背景
    void drawBackground(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    // 绘制封面
    void drawCover(QPainter *painter, const QRect &rect, const QModelIndex &index) const;
    // 绘制文本信息（标题、歌手、专辑）
    void drawTextInfo(QPainter *painter, const QRect &rect, const QModelIndex &index) const;
    // 绘制时长
    void drawDuration(QPainter *painter, const QRect &rect, const QModelIndex &index) const;

    // 样式参数（对应样式表中的值）
    // 播放按钮常量
    static const int PLAY_BTN_SIZE = 45;       // 按钮大小
    static const int PLAY_BTN_LEFT_OFFSET = 30; // 左侧偏移
    //爱心按钮常量
    static const int LIKE_BTN_SIZE = 40;        // 按钮大小
    static const int LIKE_BTN_RIGHT_OFFSET = 1000; // 右侧偏移（距离项右侧）


    const int m_itemHeight = 100;      // 项高度
    const int m_coverSize = 70;       // 封面尺寸
    const int m_margin = 0;           // 项间距（margin）
    const int m_padding = 8;          // 内边距（padding）
    const int m_borderRadius = 15;    // 圆角半径
    QPixmap m_playBtnNormal;  // 正常状态图片
    QPixmap m_playBtnHover;   // 悬停状态图片
    // 爱心按钮图片（未点击/已点击）
    QPixmap m_likeNormal;       // 未选中 + 未悬浮
    QPixmap m_likeNormalHover;  // 未选中 + 悬浮
    QPixmap m_likeSelected;     // 选中 + 未悬浮
    QPixmap m_likeSelectedHover;// 选中 + 悬浮
};

#endif // LIKEWIDELEGATE_H
