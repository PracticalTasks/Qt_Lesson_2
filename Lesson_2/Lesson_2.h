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
    //Task 2
    QStandardItemModel* model = nullptr;
    QItemSelectionModel* select = nullptr;
    int mode = 0;   //IconMode
    
    //Task 3
    QStandardItemModel* tableModel = nullptr;
    QItemSelectionModel* selectTable = nullptr;

private slots:
    void onAddButton();
    void onRemoveButton();
    void onUpButton();
    void onDownButton();
    void on_pushButton_5();
    void iconMode(int state);
};
