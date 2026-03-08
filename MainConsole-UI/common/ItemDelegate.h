#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QTableWidget>

class CustomItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CustomItemDelegate(QTableWidget *tableWidget, QObject *parent = nullptr):
        QStyledItemDelegate(parent),
        m_tableWidget(tableWidget)
    {

    };
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        if(option.state.testFlag(QStyle::State_MouseOver))
        {
            QTableWidgetItem *hoverItem = m_tableWidget->item(index.row(), index.column());
            if(hoverItem != nullptr)
            {
                int row = hoverItem->row();
                int columnCount = m_tableWidget->columnCount();
                for(int i = 0; i < columnCount; i++)
                {
                    QTableWidgetItem *item = m_tableWidget->item(row, i);
                    if(item != nullptr)
                    {
                        QModelIndex index = m_tableWidget->model()->index(row, i);
                        QStyleOptionViewItem op = option;
                        op.index = index;
                        //获取每个item对应的可视矩形
                        op.rect = m_tableWidget->visualItemRect(item);
                        QStyledItemDelegate::paint(painter, op, index);
                    }
                }
            }
            return;
        }
        return QStyledItemDelegate::paint(painter, option, index);
    }

signals:

public slots:
private:
    //指明被代理的tablewidget,方便获取整行的item
    QTableWidget *m_tableWidget;
};


#endif // ITEMDELEGATE_H
