#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QMouseEvent>
#include "core/scene.h"

#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QLabel>

using namespace haevn::view;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Create custom scene//
    m_scene = new core::Scene();
    // Set canvas center to the topleft point
    ui->canvas->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    // Apply scene to canvas
    ui->canvas->setScene(m_scene);

    ui->tools->setDragEnabled(true);


}

MainWindow::~MainWindow(){
    if(m_scene != nullptr){
        delete m_scene;
        m_scene = nullptr;
    }
    delete ui;
}


void MainWindow::link(core::Model* t_model){
    m_model = t_model;
}

void MainWindow::resizeEvent(QResizeEvent* t_event){


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
