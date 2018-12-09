#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "app/app.h"
#include "app/appstate.h"
#include "app/tool.h"
#include "core/objects/button.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    connect(ui->m_buttonProperties, SIGNAL (clicked()), this, SLOT (handlePropertiesClicked()));
    connect(ui->btAddButton, SIGNAL (clicked()), this, SLOT (handleButtonAddClicked()));

    m_app = new app::App();
    ui->m_graphicsViewCanvas->setScene(m_app->scene());

}

void MainWindow::mousePressEvent(QMouseEvent* event){
    std::cout << QCursor::pos().x() << std::endl << QCursor::pos().y() << std::endl;
    m_app->state()->selectPosition(QCursor::pos().x(), QCursor::pos().y());
    m_app->onCanvasClicked();

}

MainWindow::~MainWindow(){

    delete m_app;
    delete ui;
}


void MainWindow::handleButtonAddClicked(){

   m_app->state()->selectTool(app::Tool::BUTTON);

}

void MainWindow::handlePropertiesClicked(){
   /* PropertiesView pv;
    pv.load(m_properties);
    if(pv.exec()){
        std::cout << *m_properties << std::endl;
    }*/
}

void MainWindow::onPropertiesViewClosed(){
}
