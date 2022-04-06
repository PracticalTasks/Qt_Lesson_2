#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include "ui_Lesson_2.h"

class Lesson_2 : public QMainWindow
{
    Q_OBJECT

public:
    Lesson_2(QWidget *parent = Q_NULLPTR);

private:
    Ui::Lesson_2Class ui;
    QStandardItemModel* model = nullptr;
    QStandardItemModel* tableModel = nullptr;
    QItemSelectionModel* select = nullptr;
    QItemSelectionModel* selectTable = nullptr;
    int mode = 0;   //IconMode
    QModelIndexList currentIdx;
    QModelIndexList idxList;

private slots:
    void on_pushButton();
    void on_pushButton_2();
    void on_pushButton_3();
    void on_pushButton_4();
    void on_pushButton_5();
    void on_checkBox(int state);
    void selChanged(const QItemSelection&, const QItemSelection&);
    void selChangedOfTable(const QItemSelection&, const QItemSelection&);
};
