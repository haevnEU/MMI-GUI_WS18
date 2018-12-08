#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "app/app.h"
#include "app/appstate.h"
#include "app/tool.h"
#include "core/objects/button.h"

core::objects::IBaseElement* prop = nullptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->m_buttonProperties, SIGNAL (clicked()), this, SLOT (handlePropertiesClicked()));
    connect(ui->btAddButton, SIGNAL (clicked()), this, SLOT (handleButtonAddClicked()));
    m_app = new app::App();
    m_app->state()->selectPosition(QPoint(-110,-110));
    m_app->state()->selectWidth(100);
    m_app->state()->selectHeight(100);
    m_app->state()->selectColor(Qt::GlobalColor::blue);
    m_app->state()->selectTool(app::Tool::CIRCLE);
    m_app->onCanvasClicked();
    ui->m_graphicsViewCanvas->setScene(m_app->scene());
    prop = new core::objects::Button();
}

MainWindow::~MainWindow()
{
    delete m_app;
    delete prop;
    delete ui;
}


void MainWindow::handleButtonAddClicked(){
   m_app->state()->selectTool(app::Tool::RECTANGLE);
   m_app->state()->selectPosition(QPoint(0,-0));
   m_app->state()->selectWidth(100);
   m_app->state()->selectHeight(100);
   m_app->state()->selectColor(Qt::GlobalColor::blue);
   m_app->onCanvasClicked();
}

void MainWindow::handlePropertiesClicked(){
    PropertiesView pv;
    pv.load(prop);
    if(pv.exec()){
        std::cout << *prop << std::endl;
    }
}

void MainWindow::onPropertiesViewClosed(){
    std::cout << *prop << std::endl;
}
