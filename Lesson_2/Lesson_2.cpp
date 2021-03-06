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

    //Task 3
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
    ui.tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Task 2
    QObject::connect(ui.addButton, SIGNAL(clicked()), SLOT(onAddButton()));
    QObject::connect(ui.iconMode, SIGNAL(stateChanged(int)), SLOT(iconMode(int)));
    QObject::connect(ui.removeButton, SIGNAL(clicked()), SLOT(onRemoveButton()));
    QObject::connect(ui.upButton, SIGNAL(clicked()), SLOT(onUpButton()));
    QObject::connect(ui.downButton, SIGNAL(clicked()), SLOT(onDownButton()));

    //Task 3
    QObject::connect(ui.changeColor, SIGNAL(clicked()), SLOT(onChangeColor()));
    
}

//Task 2
void Lesson_2::onAddButton()
{
    if (!ui.lineEdit->text().isEmpty())
    {
        model->appendRow(new QStandardItem(QIcon("icon/default.png"), ui.lineEdit->text()));
        ui.lineEdit->clear();
    }
    
}

void Lesson_2::iconMode(int)
{
    ui.listView->setViewMode(static_cast<QListView::ViewMode>(mode ^= 1));
}


void Lesson_2::onRemoveButton()
{
    if (select->hasSelection())

    {
        auto currentIdx = select->currentIndex();
        model->removeRow(currentIdx.row());

    }
}

void Lesson_2::onUpButton()
{
    if (select->hasSelection())
    {
        auto currentIdx = select->currentIndex();
        int row = currentIdx.row();

        if (row > 0)
        {
            auto item = model->takeRow(currentIdx.row());
            model->insertRow(--row, item);
        }
        ui.listView->setCurrentIndex(model->index(row, 0));
    }
    
}

void Lesson_2::onDownButton()
{
    if (select->hasSelection())
    {
        auto currentIdx = select->currentIndex();
        int row = currentIdx.row();

        if (row < (model->rowCount() - 1))
        {
            auto item = model->takeRow(currentIdx.row());
            model->insertRow(++row, item);            
        }
        ui.listView->setCurrentIndex(model->index(row, 0));
    }
}

//Task 3
void Lesson_2::onChangeColor()
{
    if (selectTable->hasSelection())
    {
        auto selRows = selectTable->selectedRows();
        for (const auto& index : selRows)
        {
            int i = 0;
            while (true)
            {
                auto idx = tableModel->index(index.row(), i++);
                if (idx.isValid())
                {
                    auto item = tableModel->itemFromIndex(idx);
                    item->setData(QColor(Qt::red), Qt::BackgroundRole);
                }
                else           
                    break;                                    
            }
        }

    }
}