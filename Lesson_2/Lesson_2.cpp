#include "Lesson_2.h"

Lesson_2::Lesson_2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    model = new QStandardItemModel(this);
    model->appendRow(new QStandardItem(QIcon("icon/C++.png"), "C++"));
    model->appendRow(new QStandardItem(QIcon("icon/Python.png"), "Python"));
    model->appendRow(new QStandardItem(QIcon("icon/C.png"), "C"));
    model->appendRow(new QStandardItem(QIcon("icon/JavaScript.png"), "JavaScript"));
    model->appendRow(new QStandardItem(QIcon("icon/C#.png"), "C#"));
    model->appendRow(new QStandardItem(QIcon("icon/Kotlin.png"), "Kotlin"));
    model->appendRow(new QStandardItem(QIcon("icon/Ruby.png"), "Ruby"));
    ui.listView->setModel(model);
}
