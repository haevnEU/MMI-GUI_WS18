#include "scene.h"
#include "core/export/fileio.h"

haevn::core::visual::Scene::Scene(QObject *parent) : QGraphicsScene(parent){
    m_selectionModel = haevn::core::models::SelectionModel::getInstance();
    m_applicationModel = haevn::core::models::Model::getInstance();
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

void haevn::core::visual::Scene::clear(){
    m_applicationModel->getScenegraph()->clear();

    QList<QGraphicsItem*> all = items();
    for (int i = 0; i < all.size(); i++){
        QGraphicsItem *gi = all[i];
        if(gi->parentItem() == nullptr){
            delete gi;
        }
    }
}

// Events

void haevn::core::visual::Scene::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dragEnterEvent(event);
}

void haevn::core::visual::Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    //qDebug() << event->scenePos();
}

void haevn::core::visual::Scene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event){
}

void haevn::core::visual::Scene::dropEvent(QGraphicsSceneDragDropEvent *event){
    if(nullptr == event){
        return;
    }
    haevn::core::enums::e_Widget t_type = static_cast<haevn::core::enums::e_Widget>(event->mimeData()->property("type").toInt());

    if(t_type == haevn::core::enums::e_Widget::uncat_nothing){
        return;
    }


    int x = static_cast<int>(event->scenePos().x());
    int y = static_cast<int>(event->scenePos().y());
    int width = 100;
    int height = 30;
    QString name = "NAN";
    QWidget* item = nullptr;
    switch(t_type){
        // Control part
        case haevn::core::enums::e_Widget::control_Button:
            item = new QPushButton("Button");
            width = 150;
            height = 30;
            m_buttonCounter++;
            name = "Button" + QString::number(m_buttonCounter);
       break;
        case haevn::core::enums::e_Widget::control_CheckBox:
            item = new QCheckBox("CheckBox");
            width = 150;
            height = 30;
            m_checkBoxCounter++;
            name = "CheckBox" + QString::number(m_checkBoxCounter);
            break;
        case haevn::core::enums::e_Widget::control_RadioButton:
            item = new QRadioButton("RadioButton");
            width = 150;
            height = 30;
            m_radioButtonCounter++;
            name = "RadioButton" + QString::number(m_radioButtonCounter);
            break;

        // input part
        case haevn::core::enums::e_Widget::input_Date:

            break;
        case haevn::core::enums::e_Widget::input_Time:
            break;
        case haevn::core::enums::e_Widget::input_Slider:
            item = new QSlider();
            width = 160;
            height = 30;
            m_sliderCounter++;
            name = "Slider" + QString::number(m_sliderCounter);
            break;
        case haevn::core::enums::e_Widget::input_SpinBox:
            item = new QSpinBox();
            width = 45;
            height = 30;
            m_spinBoxCounter++;
            name = "SpinBox" + QString::number(m_spinBoxCounter);
            break;
        case haevn::core::enums::e_Widget::input_ComboBox:
            item = new QComboBox();
            width = 150;
            height = 30;
            m_comboBoxCounter++;
            name = "ComboBox" + QString::number(m_comboBoxCounter);
            break;
        case haevn::core::enums::e_Widget::input_TextField:
            item = new QLineEdit();
            width = 150;
            height = 30;
            m_textFieldCounter++;
            name = "LineEdit" + QString::number(m_textFieldCounter);
            break;

        // Display part
        case haevn::core::enums::e_Widget::display_Label:
            item = new QLabel("Label");
            width = 150;
            height = 30;

            name = "Label" + QString::number(m_textFieldCounter);
            break;
        case haevn::core::enums::e_Widget::display_WebView:
            break;
        case haevn::core::enums::e_Widget::display_ProgressBar:
            item = new QProgressBar();
            width = 150;
            height = 30;
            m_progressBarCounter++;
            name = "ProgressBar" + QString::number(m_progressBarCounter);
            break;

        // Layout part
        case haevn::core::enums::e_Widget::layout_Grid:
            break;
        case haevn::core::enums::e_Widget::layout_Canvas:
            break;
        case haevn::core::enums::e_Widget::layout_HBox:
            break;
        case haevn::core::enums::e_Widget::layout_VBox:
            break;

        // Grouping part
        case haevn::core::enums::e_Widget::grouping_GroupBox:
            item = new QGroupBox();
            break;
        case haevn::core::enums::e_Widget::grouping_RadioButtonGroup:
            break;
        // Items part
        case haevn::core::enums::e_Widget::dataVisualization_ListView:
            item = new QListWidget();
            width = 250;
            height = 250;
            m_listViewCounter++;
            name = "ListWidget" + QString::number(m_listViewCounter);
            break;
        case haevn::core::enums::e_Widget::dataVisualization_TreeView:
            item = new QTreeWidget();
            width = 250;
            height = 250;
            m_treeWidgetCounter++;
            name = "TreeWidget" + QString::number(m_treeWidgetCounter);
            break;
        case haevn::core::enums::e_Widget::dataVisualization_TableView:
            item = new QTableWidget();
            width = 250;
            height = 250;
            m_tableWidgetCounter++;
            name = "TableWidget" + QString::number(m_tableWidgetCounter);
            break;
    }

    if(nullptr != item){

        qDebug() << x << " " << y;
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

    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = true;
        QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
        if(nullptr != item){
            QGraphicsProxyWidget* tmp = static_cast<QGraphicsProxyWidget*>(item);
            m_selectionModel->selectWidget(tmp->widget());
            m_selectionModel->setPosition(event->scenePos().x(), event->scenePos().y());
            emit(selectedItemChanged(m_selectionModel->getSelectedwidget()));
        }
    }else if(event->button() == Qt::MouseButton::RightButton){
        QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
        if(nullptr != item){
            if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(item)){
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
