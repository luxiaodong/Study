#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "src/GTest.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseReleaseEvent(QMouseEvent * event)
{
    GTest test;
    test.test();
}

