#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "app/app.h"
#include "app/appstate.h"
#include "app/tool.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->m_buttonProperties, SIGNAL (clicked()), this, SLOT (handlePropertiesClicked()));
    app::App* m_app = new app::App();
    pv = new PropertiesView();
    m_app->state()->selectPosition(QPoint(-110,-110));
    m_app->state()->selectWidth(100);
    m_app->state()->selectHeight(100);
    m_app->state()->selectColor(Qt::GlobalColor::blue);
    m_app->state()->selectTool(app::Tool::CIRCLE);
    m_app->onCanvasClicked();
    ui->m_graphicsViewCanvas->setScene(m_app->scene());
}

MainWindow::~MainWindow()
{
    delete pv;
    delete ui;
}

void MainWindow::handlePropertiesClicked(){
    pv->show();
}
