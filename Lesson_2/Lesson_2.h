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
    QStandardItemModel* model;

};
