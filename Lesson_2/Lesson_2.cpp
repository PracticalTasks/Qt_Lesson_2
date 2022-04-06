#include "Lesson_2.h"

Lesson_2::Lesson_2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //Task 2
    QStringList lst;
    lst << "C++" << "Python" << "C" << "JavaScript" << "C#" << "Kotlin" << "Ruby"<<"Golang";;
    int rowCount = lst.size();

    model = new QStandardItemModel(this);
    for (int i = 0; i < rowCount; ++i)
        model->appendRow(new QStandardItem(QIcon("icon/" + lst.at(i) + ".png"), lst.at(i)));

    ui.listView->setModel(model);
    select = new QItemSelectionModel(model);
    ui.listView->setSelectionModel(select);

    //Task 2
    tableModel = new QStandardItemModel(this);
    tableModel->appendRow({ new QStandardItem("PC1"), new QStandardItem("192.168.1.100"), new QStandardItem("F0:98:9D:00:00:00") });
    tableModel->appendRow({ new QStandardItem("PC2"), new QStandardItem("192.168.45.121"), new QStandardItem("F0:98:9D:FF:80:00") });
    tableModel->appendRow({ new QStandardItem("PC3"), new QStandardItem("192.168.59.201"), new QStandardItem("F0:98:9D:00:AD:32") });
  
    lst.clear();
    lst << "PC name" << "IP-adress" << "MAC-adress";
    for (int i = 0; i < tableModel->rowCount(); i++)
        tableModel->setHeaderData(i, Qt::Horizontal, lst.at(i));
    
    ui.tableView->setModel(tableModel);
    selectTable = new QItemSelectionModel(tableModel);
    ui.tableView->setSelectionModel(selectTable);
    ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    QObject::connect(ui.pushButton, SIGNAL(clicked()), SLOT(on_pushButton()));
    QObject::connect(ui.checkBox, SIGNAL(stateChanged(int)), SLOT(on_checkBox(int)));
    QObject::connect(select, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(selChanged(const QItemSelection&, const QItemSelection&)));
    QObject::connect(selectTable, SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), SLOT(selChangedOfTable(const QItemSelection&, const QItemSelection&)));
    QObject::connect(ui.pushButton_2, SIGNAL(clicked()), SLOT(on_pushButton_2()));
    QObject::connect(ui.pushButton_3, SIGNAL(clicked()), SLOT(on_pushButton_3()));
    QObject::connect(ui.pushButton_4, SIGNAL(clicked()), SLOT(on_pushButton_4()));
    QObject::connect(ui.pushButton_5, SIGNAL(clicked()), SLOT(on_pushButton_5()));
}

void Lesson_2::on_pushButton()
{
    model->appendRow(new QStandardItem(QIcon("icon/default.png"), ui.lineEdit->text()));
}

void Lesson_2::on_checkBox(int state)
{
    
    ui.listView->setViewMode(static_cast<QListView::ViewMode>(mode ^= 1));
}

void Lesson_2::selChanged(const QItemSelection &selected , const QItemSelection &)
{
    currentIdx = select->selectedIndexes();
}

void Lesson_2::selChangedOfTable(const QItemSelection& sel, const QItemSelection& desel)
{
    idxList = sel.indexes();

}

void Lesson_2::on_pushButton_2()
{
    model->removeRow(currentIdx.at(0).row());

}

void Lesson_2::on_pushButton_3()
{
    int row = currentIdx.at(0).row();
    if (row >= 1)
    {
        QList<QStandardItem*> lstItem;
        lstItem = model->takeRow(currentIdx.at(0).row());
        model->insertRow(--row, lstItem.at(0));
    }
    
}

void Lesson_2::on_pushButton_4()
{
    int row = currentIdx.at(0).row();
   
    if (row < (model->rowCount()-1))
    {
        QList<QStandardItem*> lstItem;
        lstItem = model->takeRow(currentIdx.at(0).row());
        model->insertRow(++row, lstItem.at(0));
    }

}


void Lesson_2::on_pushButton_5()
{
    QStandardItem *item;
    QModelIndex idx;
    int i = 0;
    while(idxList.count() != 0)
    {
        idx = tableModel->index(idxList.at(0).row(), i++);
        if (idx.isValid())
        {
            item = tableModel->itemFromIndex(idx);
            item->setData(QColor(Qt::red), Qt::BackgroundRole);
        }
        else
            break;
    } 

}