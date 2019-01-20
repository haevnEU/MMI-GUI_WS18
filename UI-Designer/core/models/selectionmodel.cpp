#include "selectionmodel.h"
#include <QDebug>

// Singleton pattern

haevn::core::models::SelectionModel* haevn::core::models::SelectionModel::s_instance = nullptr;
haevn::core::models::SelectionModel* haevn::core::models::SelectionModel::getInstance(){
    if(s_instance == nullptr){
        s_instance = new SelectionModel();
    }
    return s_instance;
}

haevn::core::models::SelectionModel::SelectionModel(){
    selectedWidget = nullptr;
}

// end singleton pattern

haevn::core::models::SelectionModel::~SelectionModel(){
    if(nullptr != selectedWidget){
        delete selectedWidget;
        selectedWidget = nullptr;
    }
}

QWidget* haevn::core::models::SelectionModel::getSelectedwidget(){
    return selectedWidget;
}

void haevn::core::models::SelectionModel::selectWidget(QWidget* selection){
    if(selection == nullptr || selectedWidget == selection){
        return;
    }

    m_width = selection->width();
    m_height = selection->height();
    m_posX = selection->pos().x();
    m_posY = selection->pos().y();
    selectedWidget = selection;
    emit selectedWidgetChanged(selectedWidget);
}

void haevn::core::models::SelectionModel::setHeight(int t_height){
    if(m_height == t_height || selectedWidget == nullptr){
        return;
    }
    if(true || t_height <= m_maxHeight && t_height >= m_minHeight){
        m_height = t_height;
        selectedWidget->resize(m_width, m_height);
    }
    emit heightChanged(m_height);
}

void haevn::core::models::SelectionModel::setMaxHeight(int t_maxHeight) {
     if(m_maxHeight == t_maxHeight || selectedWidget == nullptr){
         return;
     }
     m_maxHeight = t_maxHeight;
     selectedWidget->setMaximumHeight(m_maxHeight);

     emit heightChanged(t_maxHeight);
}

void haevn::core::models::SelectionModel::setMinHeight(int t_minHeight) {
     if(m_minHeight == t_minHeight || selectedWidget == nullptr){
         return;
     }
     m_minHeight = t_minHeight;
     selectedWidget->setMinimumHeight(m_minHeight);

     emit heightChanged(t_minHeight);
}

void haevn::core::models::SelectionModel::setWidth(int t_width) {
     if(m_width == t_width || selectedWidget == nullptr){
         return;
     }
     if(true || t_width <= m_maxWidth && t_width >= m_minWidth){
        m_width = t_width;
        selectedWidget->resize(m_width, m_height);
     }
     emit widthChanged(m_width);
}

void haevn::core::models::SelectionModel::setMaxWidth(int t_maxWidth) {
     if(m_maxWidth == t_maxWidth || selectedWidget == nullptr){
         return;
     }
     m_maxWidth = t_maxWidth;
     selectedWidget->setMaximumWidth(m_maxWidth);

     emit widthChanged(t_maxWidth);
}

void haevn::core::models::SelectionModel::setMinWidth(int t_minWidth) {
     if(m_minWidth == t_minWidth || selectedWidget == nullptr){
         return;
     }
     m_minWidth = t_minWidth;
     selectedWidget->setMinimumWidth(m_minWidth);

     emit widthChanged(t_minWidth);
}

void haevn::core::models::SelectionModel::setPosition(int t_x, int t_y){
    if(m_posX == t_x && m_posY == t_y || selectedWidget == nullptr){
        return;
    }
    m_posY = t_y;
    m_posX = t_x;
    selectedWidget->move(m_posX, m_posY);
    emit positionChanged(t_x, t_y);
}

void haevn::core::models::SelectionModel::setEnabled(bool t_visibility) {
    if(m_visibility == t_visibility || selectedWidget == nullptr){
        return;
    }
    m_visibility = t_visibility;
    selectedWidget->setEnabled(m_visibility);
    emit enabledChanged(t_visibility);
}

void haevn::core::models::SelectionModel::setTooltip(QString t_tooltip){
    if(m_tooltip == t_tooltip || selectedWidget == nullptr){
        return;
    }
    m_tooltip = t_tooltip;
    selectedWidget->setToolTip(m_tooltip);

    emit tooltipChanged(t_tooltip);
}

void haevn::core::models::SelectionModel::setName(QString t_name){
    if(t_name == m_name || selectedWidget == nullptr){
        return;
    }
     // TODO
    m_name = t_name;
    selectedWidget->setWhatsThis(t_name);
    emit nameChanged(m_name);
}
