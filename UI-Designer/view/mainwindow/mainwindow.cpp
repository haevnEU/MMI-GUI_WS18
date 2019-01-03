#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QMouseEvent>
#include "core/scene.h"

#include "core/objects/buttons/hbutton.h"
#include "core/enumerations.h"

using namespace haevn::view;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    haevn::core::objects::buttons::HButton* bt = new haevn::core::objects::buttons::HButton();


    // Create custom scene//
    m_scene = new core::Scene(m_model);
    // Set canvas center to the topleft point
    ui->canvas->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    // Apply scene to canvas
    ui->canvas->setScene(m_scene);

    tools = new haevn::core::custom_objects::HTreeView();

    tools->addRootHeader("Control");
    tools->insertData(0, core::e_haevn_objects::control_Button);
    tools->insertData(0, core::e_haevn_objects::control_RadioButton);
    tools->insertData(0, core::e_haevn_objects::control_CheckBox);

    tools->addRootHeader("Input");
    tools->insertData(1, core::e_haevn_objects::input_TextField);
    tools->insertData(1, core::e_haevn_objects::input_ComboBox);
    tools->insertData(1, core::e_haevn_objects::input_Slider);
    tools->insertData(1, core::e_haevn_objects::input_SpinBox);
    tools->insertData(1, core::e_haevn_objects::input_Date);
    tools->insertData(1, core::e_haevn_objects::input_Time);

    tools->addRootHeader("Display");
    tools->insertData(2,  core::e_haevn_objects::display_Label);
    tools->insertData(2,  core::e_haevn_objects::display_ProgressBar);
    tools->insertData(2,  core::e_haevn_objects::display_WebView);

    tools->addRootHeader("Grouping");
    tools->insertData(3, core::e_haevn_objects::grouping_GroupBox);
    tools->insertData(3, core::e_haevn_objects::grouping_RadioButtonGroup);

    tools->addRootHeader("Items");
    tools->insertData(4, core::e_haevn_objects::dataVisualization_ListView);
    tools->insertData(4, core::e_haevn_objects::dataVisualization_TableView);
    tools->insertData(4, core::e_haevn_objects::dataVisualization_TreeView);

    tools->addRootHeader("Layout");
    tools->insertData(5, core::e_haevn_objects::layout_Grid);
    tools->insertData(5, core::e_haevn_objects::layout_Canvas);
    tools->insertData(5, core::e_haevn_objects::layout_HBox);
    tools->insertData(5, core::e_haevn_objects::layout_VBox);

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
