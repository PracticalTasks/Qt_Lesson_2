#include "Lesson_2.h"

Lesson_2::Lesson_2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QStringList lst;
    lst << "C++" << "Python" << "C" << "JavaScript" << "C#" << "Kotlin" << "Ruby";;

    model = new QStandardItemModel(lst.size(), 1);
    for (int i = 0; i < model->rowCount(); ++i)
    {
        QModelIndex index = model->index(i, 0);
        model->setData(index, lst.at(i), Qt::DisplayRole);
        model->setData(index, QIcon("icon/"+lst.at(i)+".png"), Qt::DecorationRole);
    }

    ui.listView->setViewMode(QListView::IconMode);
    ui.listView->setModel(model);

}
