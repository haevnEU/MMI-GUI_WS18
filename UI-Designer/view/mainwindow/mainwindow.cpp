#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 *
 +--------------------------------------+
 | TODO                                 |
 +--------------------------------------+
 | [ ] Implement method contentChanged  |
 | [ ] Implement save method            |
 | [ ] Implement load method            |
 |                                      |
 +--------------------------------------+
 *
 */

haevn::view::MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    m_applicationModel = new haevn::core::models::Model();
    m_scene = new haevn::core::visual::Scene(m_applicationModel);
    // Set canvas center to the topleft point
    ui->canvas->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    // Apply scene to canvas
    ui->canvas->setScene(m_scene);


    tools = new haevn::core::visual::HTreeView();

    // Add data to the trreview
    tools->addRootHeader("Control");
    tools->insertData(0, haevn::core::enums::e_widget::control_Button);
    tools->insertData(0, haevn::core::enums::e_widget::control_RadioButton);
    tools->insertData(0, haevn::core::enums::e_widget::control_CheckBox);

    tools->addRootHeader("Input");
    tools->insertData(1, haevn::core::enums::e_widget::input_TextField);
    tools->insertData(1, haevn::core::enums::e_widget::input_ComboBox);
    tools->insertData(1, haevn::core::enums::e_widget::input_Slider);
    tools->insertData(1, haevn::core::enums::e_widget::input_SpinBox);
    tools->insertData(1, haevn::core::enums::e_widget::input_Date);
    tools->insertData(1, haevn::core::enums::e_widget::input_Time);

    tools->addRootHeader("Display");
    tools->insertData(2,  haevn::core::enums::e_widget::display_Label);
    tools->insertData(2,  haevn::core::enums::e_widget::display_ProgressBar);
    tools->insertData(2,  haevn::core::enums::e_widget::display_WebView);

    tools->addRootHeader("Grouping");
    tools->insertData(3, haevn::core::enums::e_widget::grouping_GroupBox);
    tools->insertData(3, haevn::core::enums::e_widget::grouping_RadioButtonGroup);

    tools->addRootHeader("Items");
    tools->insertData(4, haevn::core::enums::e_widget::dataVisualization_ListView);
    tools->insertData(4, haevn::core::enums::e_widget::dataVisualization_TableView);
    tools->insertData(4, haevn::core::enums::e_widget::dataVisualization_TreeView);

    tools->addRootHeader("Layout");
    tools->insertData(5, haevn::core::enums::e_widget::layout_Grid);
    tools->insertData(5, haevn::core::enums::e_widget::layout_Canvas);
    tools->insertData(5, haevn::core::enums::e_widget::layout_HBox);
    tools->insertData(5, haevn::core::enums::e_widget::layout_VBox);

    // end add data to treeview
    tools->setDragEnabled(true);
    layout()->addWidget(tools);

    // UI Signal-Slot
    connect(ui->spPosX, SIGNAL(valueChanged(int)), this, SLOT(posXChanged(int)));
    connect(ui->spPosY, SIGNAL(valueChanged(int)), this, SLOT(posYChanged(int)));

    connect(ui->sbObjectWidth, SIGNAL(valueChanged(int)), this, SLOT(widthChanged(int)));
    connect(ui->sbObjectMaxWidth, SIGNAL(valueChanged(int)), this, SLOT(maxWidthChanged(int)));
    connect(ui->sbObjectMinWidth, SIGNAL(valueChanged(int)), this, SLOT(minWidthChanged(int)));

    connect(ui->sbObjectHeight, SIGNAL(valueChanged(int)), this, SLOT(heightChanged(int)));
    connect(ui->sbObjectMaxWidth, SIGNAL(valueChanged(int)), this, SLOT(minWidthChanged(int)));
    connect(ui->sbObjectMinHeight, SIGNAL(valueChanged(int)), this, SLOT(minHeightChanged(int)));

    connect(ui->leContent, SIGNAL(textChanged(QString)), this, SLOT(contentChanged(QString)));
    connect(ui->leTooltip, SIGNAL(textChanged(QString)), this, SLOT(tooltipChanged(QString)));
    connect(ui->leName, SIGNAL(textChanged(QString)), this, SLOT(nameChanged(QString)));

    connect(ui->cbEnabled, SIGNAL(stateChanged(int)), this, SLOT(enabledChanged(int)));

    connect(ui->actionNewScene, SIGNAL(triggered(bool)), this, SLOT(newSceneTriggered(bool)));

    connect(ui->actionBuild, SIGNAL(triggered(bool)), this, SLOT(buildTriggered(bool)));

    connect(ui->actionHelp, SIGNAL(triggered(bool)), this, SLOT(helpTriggered(bool)));
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(aboutTriggered(bool)));
    connect(ui->actionAbout_Qt, SIGNAL(triggered(bool)), this, SLOT(aboutQtTriggered(bool)));
    connect(ui->actionAbout_LUA, SIGNAL(triggered(bool)), this, SLOT(aboutLuaTriggered(bool)));

    connect(m_scene->getSelectionModel(), SIGNAL(positionChanged(int, int)), this, SLOT(positionChanged(int, int)));
    connect(m_scene->getSelectionModel(), SIGNAL(selectedWidgetChanged(QWidget*)), this, SLOT(selectedWidgetChanged(QWidget*)));
}

haevn::view::MainWindow::~MainWindow(){
    delete m_scene;
    delete m_applicationModel;
    delete ui;

    m_scene = nullptr;
    m_applicationModel = nullptr;
}

// Events

void haevn::view::MainWindow::resizeEvent(QResizeEvent* t_event){


    // The height equals the window height without the size of the menubar, a small space(10px) below the menubar and at the bottom
    // and a small space at the bottom (20px)
    int height = t_event->size().height() - ui->menuBar->height() - 2 * 10;


    // First handle the tools
    // The toolview has a fixed width(300px) and a dynamic calculated height
    tools->resize(300, height);
    // Also a fixed x position(10px) but a dynamic y position
    tools->move(10, ui->menuBar->height() + 10);

    // Next the canvas (scene)
    // The width of the canvas ist 97% of the window width without
    // the size of the tools(300px), details(300px) and a small space(20px) at booth sides
    int canvasWidth = static_cast<int>((t_event->size().width() * 0.97) - 620);

    // Booth width and height are dynamicaly calculated
    ui->canvas->resize(canvasWidth, height);

    // The X position of the canvas is the tool width(300px), the y position is fix
    ui->canvas->move(tools->width() + 20, ui->canvas->pos().y());

    // Next the details
    // The details are the same as the tools exept the positionX
    // The position equals canvas width + toolwidth + little space(20)
    int detailsPosX = (canvasWidth) + tools->width() + 20;


    ui->details->resize(300, height);
    ui->details->move(detailsPosX, ui->details->pos().y());

}

//End events

// Slots

void haevn::view::MainWindow::widthChanged(int t_width){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setWidth(t_width);
    }
    if(ui->sbObjectWidth->value() != t_width){
        ui->sbObjectWidth->setValue(t_width);
    }
}

void haevn::view::MainWindow::maxWidthChanged(int t_width){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setMaxWidth(t_width);
    }
    if(ui->sbObjectMaxWidth->value() != t_width){
        ui->sbObjectMaxWidth->setValue(t_width);
    }
}

void haevn::view::MainWindow::minWidthChanged(int t_width){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setMinWidth(t_width);
    }
    if(ui->sbObjectMinWidth->value() != t_width){
        ui->sbObjectMinWidth->setValue(t_width);
    }
}

void haevn::view::MainWindow::heightChanged(int t_height){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setHeight(t_height);
    }
    if(ui->sbObjectHeight->value() != t_height){
        ui->sbObjectHeight->setValue(t_height);
    }
}

void haevn::view::MainWindow::maxHeightChanged(int t_height){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setMaxHeight(t_height);
    }
    if(ui->sbObjectMaxHeight->value() != t_height){
        ui->sbObjectMaxHeight->setValue(t_height);
    }
}

void haevn::view::MainWindow::minHeightChanged(int t_height){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setMinHeight(t_height);
    }
    if(ui->sbObjectMinHeight->value() != t_height){
        ui->sbObjectMinHeight->setValue(t_height);
    }
}

void haevn::view::MainWindow::positionChanged(int t_x, int t_y){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setPosition(t_x, t_y);
    }
    if(ui->spPosX->value() != t_x){
        ui->spPosX->setValue(t_x);
    }
    if(ui->spPosY->value() != t_y){
        ui->spPosY->setValue(t_y);
    }
}

void haevn::view::MainWindow::posXChanged(int t_x){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setPosition(t_x, ui->spPosY->value());
    }
    if(ui->spPosX->value() != t_x){
        ui->spPosX->setValue(t_x);
    }
}

void haevn::view::MainWindow::posYChanged(int t_y){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setPosition(ui->spPosX->value(), t_y);
    }
    if(ui->spPosY->value() != t_y){
        ui->spPosX->setValue(t_y);
    }
}

void haevn::view::MainWindow::nameChanged(QString t_name){
    if(m_scene != nullptr){
        m_scene->getSelectionModel()->setName(t_name);
    }
    if(ui->leName->text() != t_name){
        ui->leName->setText(t_name);
    }
}

void haevn::view::MainWindow::tooltipChanged(QString t_tooltip){
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setTooltip(t_tooltip);
    }
    if(ui->leTooltip->text() != t_tooltip){
        ui->leTooltip->setText(t_tooltip);
    }
}

void haevn::view::MainWindow::enabledChanged(int t_visibility){
    bool state = t_visibility == Qt::CheckState::Unchecked ? false : true;
    if(m_scene != nullptr) {
        m_scene->getSelectionModel()->setEnabled(state);
        if(t_visibility == Qt::CheckState::Checked){
            ui->cbEnabled->setText("Enabled");
        } else if(t_visibility == Qt::CheckState::Unchecked){
            ui->cbEnabled->setText("Disbaled");
        } else {
            ui->cbEnabled->setText("State unknown");
        }
    }

}

void haevn::view::MainWindow::selectedWidgetChanged(QWidget* widget){

    // Set default properties
    if(nullptr == widget){
        ui->spPosX->setValue(0);
        ui->spPosY->setValue(0);

        ui->sbObjectWidth->setValue(0);
        ui->sbObjectMaxWidth->setValue(0);
        ui->sbObjectMinWidth->setValue(0);

        ui->sbObjectHeight->setValue(0);
        ui->sbObjectMaxHeight->setValue(0);
        ui->sbObjectMinHeight->setValue(0);

        ui->cbEnabled->setCheckState(Qt::CheckState::Unchecked);
        ui->leTooltip->setText("");
        ui->leName->setText("Nothing selected");
    }
    // Set the properties to the widget properties
    else{
        m_scene->getSelectionModel()->selectWidget(widget);
        ui->spPosX->setValue(widget->pos().x());
        ui->spPosY->setValue(widget->pos().y());

        ui->sbObjectWidth->setValue(widget->width());
        ui->sbObjectMaxWidth->setValue(widget->maximumWidth());
        ui->sbObjectMinWidth->setValue(widget->minimumWidth());

        ui->sbObjectHeight->setValue(widget->height());
        ui->sbObjectMaxHeight->setValue(widget->maximumHeight());
        ui->sbObjectMinHeight->setValue(widget->minimumHeight());

        ui->cbEnabled->setCheckState(widget->isEnabled() == true ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
        ui->leTooltip->setText(widget->toolTip());
        ui->leName->setText(widget->whatsThis());
    }
}


void haevn::view::MainWindow::newSceneTriggered(bool checked){
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Question, "GUI Designer", "Are you sure to reset the scene?"
                                        "\nThis cannot be undone.", QMessageBox::Yes|QMessageBox::No).exec()){

        m_scene->clear();
    }
}

void haevn::view::MainWindow::buildTriggered(bool checked){
    // The size of the wizard is 80% of the window size
    int width = static_cast<int>(size().width() * 0.8);
    int height = static_cast<int>(size().height() * 0.8);
    haevn::view::RunScriptWizard wizzard(width, height, m_applicationModel);
    wizzard.exec();

}

void haevn::view::MainWindow::aboutTriggered(bool checked){

    // Ask user to open the browser
    if (QMessageBox::Yes == QMessageBox(QMessageBox::
                                        Information, "GUI Designer", "This application is develop and maintained by Nils Milewski"
                                        "\n\nLast update: Jan 20 2019"
                                        "\n\nAt GitHub you can find more details.\nOpen GitHub website?", QMessageBox::Yes|QMessageBox::No).exec()){
        // Open the browser with the github repo
        QDesktopServices::openUrl(QUrl("https://github.com/nimile/MMI-GUI", QUrl::TolerantMode));
    }
}

void haevn::view::MainWindow::aboutQtTriggered(bool checked){
    QMessageBox::aboutQt(this, "GUI Designer");
}


void haevn::view::MainWindow::aboutLuaTriggered(bool checked){
    /*Copyright © 1994–2018 Lua.org, PUC-Rio.
     *
     * Permission is hereby granted, free of charge, to any person obtaining
     * a copy of this software and associated documentation files (the
     * "Software"), to deal in the Software without restriction, including
     * without limitation the rights to use, copy, modify, merge, publish,
     * distribute, sublicense, and/or sell copies of the Software, and to permit
     * persons to whom the Software is furnished to do so, subject to the
     * following conditions:
     *
     * The above copyright notice and this permission notice shall be
     * included in all copies or substantial portions of the Software.
     *
     * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
     * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
     * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
     * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
     * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
     * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
     * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
     * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
     * OTHER DEALINGS IN THE SOFTWARE.
    */

    // Ask the user to review the LUA license
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Open LUA license?", "You can find the LUA license at the official LUA website"
                                        "\nOpen default browser?", QMessageBox::Yes|QMessageBox::No).exec()){
        // Open the license inside the browser
        QDesktopServices::openUrl(QUrl("https://www.lua.org/license.html", QUrl::TolerantMode));
    }
}

void haevn::view::MainWindow::helpTriggered(bool checked){
    // Ask the user to view the online help
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Open GitHub repo?", "You can find the help inside the GitHub repo."
                                        "\nOpen Now?", QMessageBox::Yes|QMessageBox::No).exec()){
        // Open the help page inside the GitHub repo
        QDesktopServices::openUrl(QUrl("https://github.com/nimile/MMI-GUI", QUrl::TolerantMode));
    }
}

// End slots
