#ifndef SEARCHRECOMWI_H
#define SEARCHRECOMWI_H

#include "qwidget.h"
#include<QListView>
#include <QWidget>
#include <QListWidget>
#include <QStringList>
//搜索框下方展示的推荐窗口
//显示逻辑由主窗口控制
class SearchRecomwi : public QWidget
{
    Q_OBJECT
public:
    explicit SearchRecomwi(QWidget *parent = nullptr);

    // 设置搜索建议数据
    void setSuggestions(const QStringList &suggestions);
    // 获取当前建议项数量
    int suggestionCount() const { return m_suggestList->count(); }

signals:
    // 选中建议项时发出信号（传递选中的文本）
    void suggestionSelected(const QString &text);
    // 建议项为空时发出信号（主窗口可据此隐藏）
    void suggestionsEmpty();

private slots:
    // 列表项点击处理
    void onItemClicked(QListWidgetItem *item);

private:
    QFont itemFont;//字体
    QListWidget *m_suggestList; // 建议列表（仅做数据展示）
};

#endif // SEARCHRECOMWI_H
