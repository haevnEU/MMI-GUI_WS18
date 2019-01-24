#include "scene.h"

haevn::core::visual::Scene::Scene(haevn::core::models::Model* t_applicationModel, QObject *parent) : QGraphicsScene(parent){
    m_selectionModel = haevn::core::models::SelectionModel::getInstance();
    m_applicationModel = t_applicationModel;

    m_scenegraph = new QList<QWidget*>();

    m_buttonCounter = 0;
    m_checkBoxCounter = 0;
    m_radioButtonCounter = 0;
    m_timeCounter = 0;
    m_dateCounter = 0;
    m_spinBoxCounter = 0;
    m_sliderCounter = 0;
    m_comboBoxCounter = 0;
    m_textFieldCounter = 0;

    m_labelCounter = 0;
    m_progressBarCounter = 0;

    m_treeWidgetCounter = 0;
    m_tableWidgetCounter = 0;
    m_listViewCounter = 0;

}

haevn::core::visual::Scene::~Scene(){
    QGraphicsScene::clear();
}

// Events

void haevn::core::visual::Scene::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dragEnterEvent(event);
}

void haevn::core::visual::Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dragMoveEvent(event);
}

void haevn::core::visual::Scene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event){
}

void haevn::core::visual::Scene::dropEvent(QGraphicsSceneDragDropEvent *event){

    // get the type of the dropped widget
    haevn::core::enums::e_widget t_type = static_cast<haevn::core::enums::e_widget>(event->mimeData()->property("type").toInt());

    if(t_type == haevn::core::enums::e_widget::uncat_nothing){
        return;
    }

    // request the position of the mouse
    int x = static_cast<int>(event->scenePos().x());
    int y = static_cast<int>(event->scenePos().y());
    // set defailt parameter
    int width = 100;
    int height = 30;
    QString name = "NAN";
    QWidget* item = nullptr;
    // Switch between diferent types
    // Each type creates a new item based on the selected type
    // It will also reset the width and height, increment the type counter
    // and it will also set the name to a default one
    switch(t_type){
        // Control part
        case haevn::core::enums::e_widget::control_Button:
            item = new QPushButton("Button");
            width = 150;
            height = 30;
            m_buttonCounter++;
            name = "Button" + QString::number(m_buttonCounter);
       break;
        case haevn::core::enums::e_widget::control_CheckBox:
            item = new QCheckBox("CheckBox");
            width = 150;
            height = 30;
            m_checkBoxCounter++;
            name = "CheckBox" + QString::number(m_checkBoxCounter);
            break;
        case haevn::core::enums::e_widget::control_RadioButton:
            item = new QRadioButton("RadioButton");
            width = 150;
            height = 30;
            m_radioButtonCounter++;
            name = "RadioButton" + QString::number(m_radioButtonCounter);
            break;

        // input part
        case haevn::core::enums::e_widget::input_Date:

            break;
        case haevn::core::enums::e_widget::input_Time:
            break;
        case haevn::core::enums::e_widget::input_Slider:
            item = new QSlider();
            width = 160;
            height = 30;
            m_sliderCounter++;
            name = "Slider" + QString::number(m_sliderCounter);
            break;
        case haevn::core::enums::e_widget::input_SpinBox:
            item = new QSpinBox();
            width = 45;
            height = 30;
            m_spinBoxCounter++;
            name = "SpinBox" + QString::number(m_spinBoxCounter);
            break;
        case haevn::core::enums::e_widget::input_ComboBox:
            item = new QComboBox();
            width = 150;
            height = 30;
            m_comboBoxCounter++;
            name = "ComboBox" + QString::number(m_comboBoxCounter);
            break;
        case haevn::core::enums::e_widget::input_TextField:
            item = new QLineEdit();
            width = 150;
            height = 30;
            m_textFieldCounter++;
            name = "LineEdit" + QString::number(m_textFieldCounter);
            break;

        // Display part
        case haevn::core::enums::e_widget::display_Label:
            item = new QLabel("Label");
            width = 150;
            height = 30;

            name = "Label" + QString::number(m_textFieldCounter);
            break;
        case haevn::core::enums::e_widget::display_WebView:
            break;
        case haevn::core::enums::e_widget::display_ProgressBar:
            item = new QProgressBar();
            width = 150;
            height = 30;
            m_progressBarCounter++;
            name = "ProgressBar" + QString::number(m_progressBarCounter);
            break;

        // Layout part
        case haevn::core::enums::e_widget::layout_Grid:
            break;
        case haevn::core::enums::e_widget::layout_Canvas:
            break;
        case haevn::core::enums::e_widget::layout_HBox:
            break;
        case haevn::core::enums::e_widget::layout_VBox:
            break;

        // Grouping part
        case haevn::core::enums::e_widget::grouping_GroupBox:
            item = new QGroupBox();
            break;
        case haevn::core::enums::e_widget::grouping_RadioButtonGroup:
            break;
        // Items part
        case haevn::core::enums::e_widget::dataVisualization_ListView:
            item = new QListWidget();
            width = 250;
            height = 250;
            m_listViewCounter++;
            name = "ListWidget" + QString::number(m_listViewCounter);
            break;
        case haevn::core::enums::e_widget::dataVisualization_TreeView:
            item = new QTreeWidget();
            width = 250;
            height = 250;
            m_treeWidgetCounter++;
            name = "TreeWidget" + QString::number(m_treeWidgetCounter);
            break;
        case haevn::core::enums::e_widget::dataVisualization_TableView:
            item = new QTableWidget();
            width = 250;
            height = 250;
            m_tableWidgetCounter++;
            name = "TableWidget" + QString::number(m_tableWidgetCounter);
            break;
    }

    // If the item was set insert it to the scenegraph
    // and set the selection model
    if(nullptr != item){

        m_applicationModel->addItem(item);
        m_selectionModel->selectWidget(item);
        m_selectionModel->setPosition(x, y);
        m_selectionModel->setName(name);

        item->move(x,y);
        item->setWhatsThis(name);
        item->resize(width, height);
        addWidget(m_selectionModel->getSelectedwidget());
        m_scenegraph->push_back(m_selectionModel->getSelectedwidget());
        emit selectedItemChanged(m_selectionModel->getSelectedwidget());
    }
}

void haevn::core::visual::Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    // Enable moving the items
    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = true;
        // Get the item under mousepointer
        QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
        if(nullptr != item){
            // set the selectionmodel widget
            // The itemAt method returns a graphics item and not a widget
            // So a proxy class must be used.
            QGraphicsProxyWidget* tmp = dynamic_cast<QGraphicsProxyWidget*>(item);
            m_selectionModel->selectWidget(tmp->widget());
            m_selectionModel->setPosition(event->scenePos().x(), event->scenePos().y());
            emit(selectedItemChanged(m_selectionModel->getSelectedwidget()));
        }
    }
    // Right button removes an element, the procedure is the same as moving
    // The m_grab variable is not set instead the item is removed
    else if(event->button() == Qt::MouseButton::RightButton){
        QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
        if(nullptr != item){
            if(QGraphicsProxyWidget* proxyWidget = dynamic_cast<QGraphicsProxyWidget*>(item)){
                m_scenegraph->removeOne(proxyWidget->widget());
                m_applicationModel->removeItem(proxyWidget->widget());
                removeItem(item);
                m_selectionModel->selectWidget(nullptr);
                emit(selectedItemChanged(m_selectionModel->getSelectedwidget()));
            }
        }
    }
}

void haevn::core::visual::Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(m_grab && m_selectionModel->getSelectedwidget() != nullptr){
        int x = static_cast<int>(event->scenePos().x());
        int y = static_cast<int>(event->scenePos().y());
        m_selectionModel->setPosition(x, y);
    }

}

void haevn::core::visual::Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = false;
    }
}

// End events

bool haevn::core::visual::Scene::isGrabbed(){
    return m_grab;
}

haevn::core::models::SelectionModel* haevn::core::visual::Scene::getSelectionModel(){
    return m_selectionModel;
}

QList<QWidget*>* haevn::core::visual::Scene::getScenegraph(){
    return m_scenegraph;
}
