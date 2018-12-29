#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QVBoxLayout>

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

void MainWindow::resizeEvent(QResizeEvent* event){

    double posY = 10;
    double height = size().height() - 20;

    double canvasPosX = 320;
    double canvasWidth = (size().width() * 0.97) - 620;

    double detailsPosX = (canvasWidth) + 320;


    ui->tools->resize(300, height);
    ui->tools->move(10, posY);

    ui->canvas->resize(canvasWidth, height);
    ui->canvas->move(canvasPosX, posY);

    ui->details->resize(300, height);
    ui->details->move(detailsPosX, posY);
}
