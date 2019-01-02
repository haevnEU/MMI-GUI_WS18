#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QMouseEvent>
#include "core/scene.h"

#include "core/objects/buttons/hbutton.h"


using namespace haevn::view;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    haevn::core::objects::buttons::HButton* bt = new haevn::core::objects::buttons::HButton();


    // Create custom scene//
    m_scene = new core::Scene();
    // Set canvas center to the topleft point
    ui->canvas->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    // Apply scene to canvas
    ui->canvas->setScene(m_scene);

    tools = new haevn::core::custom_objects::HTreeView();

    tools->addRootHeader("Control");
    tools->insertData(0, "Button");
    tools->insertData(0, "RadioButton");
    tools->insertData(0, "CheckBox");

    tools->addRootHeader("Input");
    tools->insertData(1, "ComboBox");
    tools->insertData(1, "TextField");
    tools->insertData(1, "SpinBox");
    tools->insertData(1, "Date");
    tools->insertData(1, "Time");
    tools->insertData(1, "Slider");

    tools->addRootHeader("Display");
    tools->insertData(2, "Label");
    tools->insertData(2, "ProgressBar");
    tools->insertData(2, "WebView");

    tools->addRootHeader("Grouping");
    tools->insertData(3, "GroupBox");
    tools->insertData(3, "RadioButtonGroup");

    tools->addRootHeader("Items");
    tools->insertData(4, "ListView");
    tools->insertData(4, "TableView");
    tools->insertData(4, "TreeView");

    tools->addRootHeader("Layout");
    tools->insertData(5, "Grid");
    tools->insertData(5, "Canvas");
    tools->insertData(5, "HBox");
    tools->insertData(5, "VBox");

    tools->setDragEnabled(true);
    layout()->addWidget(tools);

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


    tools->resize(300, height);
    tools->move(10, posY);

    ui->canvas->resize(canvasWidth, height);
    ui->canvas->move(canvasPosX, posY);

    ui->details->resize(300, height);
    ui->details->move(detailsPosX, posY);


}
