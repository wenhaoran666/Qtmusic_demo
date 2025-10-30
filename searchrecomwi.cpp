#include "searchrecomwi.h"
#include "qgraphicseffect.h"
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QFont>

SearchRecomwi::SearchRecomwi(QWidget *parent) : QWidget(parent)
    , m_suggestList(new QListWidget(this))
{
    // 窗口基础设置（仅保留必要属性）
    setWindowFlags(Qt::FramelessWindowHint | Qt::ToolTip);
    setAttribute(Qt::WA_TranslucentBackground);  // 关键：窗口背景透明，才能显示圆角
    setAttribute(Qt::WA_ShowWithoutActivating);

    // 布局（无内边距，确保列表完全填充窗口）
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);  // 布局无内边距
    layout->setSpacing(0);                   // 布局内控件无间距
    layout->addWidget(m_suggestList);

    // 列表配置（完全填充窗口）
    m_suggestList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_suggestList->setSelectionMode(QAbstractItemView::SingleSelection);
    m_suggestList->setFocusPolicy(Qt::NoFocus);

    m_suggestList->setContentsMargins(0, 0, 0, 0);  // 列表自身无内边距
    m_suggestList->setSpacing(0);                   // 列表项之间无间距

    // 配置字体（微软雅黑，12号字）
    QFont itemFont;
    itemFont.setFamily("Microsoft YaHei");
    itemFont.setPointSize(12);
    itemFont.setBold(false);
    m_suggestList->setFont(itemFont);  // 列表统一设置字体（所有项生效）

    // 样式表：窗口圆角 + 列表无内边距 + 隐藏滚动条
    m_suggestList->setStyleSheet(R"(
        /* 列表整体样式（与窗口同大小，随窗口呈现圆角） */
        QListWidget {
             border: 1px solid #cccccc;  /* 仅列表有边框（灰色示例） */
            background-color: #ffffff;  /* 背景色与窗口一致 */
            border-radius: 8px;         /* 圆角（与窗口圆角一致） */
            padding: 0px;               /* 列表内部无内边距 */
        }

        /* 列表项样式（高度50px，无额外边距） */
        QListWidget::item {
            height: 50px;               /* 项固定高度 */
            padding: 0px 12px;          /* 仅左右留12px间距（可选，避免文字贴边） */
            color: #333333;             /* 默认文字颜色 */
            border: none;               /* 项无边框 */
        }

        /* 鼠标悬停效果 */
        QListWidget::item:hover {
            background-color: #F2F3F4;
            color: #165DFF;
        }

        /* 隐藏滚动条（如需保留滚动条，可删除此部分） */
        QListWidget::verticalScrollBar {
            width: 0px;
            background: transparent;
        }
        QListWidget::horizontalScrollBar {
            height: 0px;
            background: transparent;
        }
    )");

    // 连接点击信号
    connect(m_suggestList, &QListWidget::itemClicked, this, &SearchRecomwi::onItemClicked);
}
// 设置建议数据
void SearchRecomwi::setSuggestions(const QStringList &suggestions)
{
    m_suggestList->clear();

    if (suggestions.isEmpty()) {
        emit suggestionsEmpty(); // 通知主窗口：无数据
        return;
    }

    // 添加数据项
    for (const QString &text : suggestions) {
        QListWidgetItem *item = new QListWidgetItem(text);
        item->setIcon(QIcon(":/res/btn_search_100.png"));
        item->setFont(itemFont); // 应用字体
        m_suggestList->addItem(item);
    }

    // 自适应高度（主窗口可覆盖此设置）
    int itemHeight = m_suggestList->sizeHintForRow(0);
    setFixedHeight(qMin(suggestions.count(), 8) * itemHeight + 8);
}

// 点击项时触发信号（由主窗口处理后续逻辑）
void SearchRecomwi::onItemClicked(QListWidgetItem *item)
{
    if (item) {
        emit suggestionSelected(item->text());
    }
}
