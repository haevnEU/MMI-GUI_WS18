#include "hbutton.h"
#include <QDebug>

using namespace haevn::core::objects::buttons;

HButton::HButton(QPushButton *parent) : QPushButton(parent){
    qDebug() << "ctor of HButton called";
}


HButton::~HButton(){
    qDebug() << "DTOR OF HBUTTON CALLED";
}

void HButton::setHeight(int t_height){
    QPushButton::resize(QPushButton::width(), t_height);
    emit heightChanged(t_height);
}

void HButton::setMaxHeight(int t_maxHeight){
    QPushButton::setMaximumHeight(t_maxHeight);
    emit maxHeightChanged(t_maxHeight);
}

void HButton::setMinHeight(int t_minHeight){
    QPushButton::setMinimumHeight(t_minHeight);
    emit minHeightChanged(t_minHeight);
}

void HButton::setWidth(int t_width){
    QPushButton::resize(t_width, QPushButton::height());
    emit widthChanged(t_width);
}

void HButton::setMaxWidth(int t_maxWidth){

    QPushButton::setMaximumWidth(t_maxWidth);
    emit maxWidthChanged(t_maxWidth);
}

void HButton::setMinWidth(int t_minWidth){

    QPushButton::setMinimumWidth(t_minWidth);
    emit minWidthChanged(t_minWidth);
}

void HButton::setPosition(int t_x, int t_y){
    QPushButton::move(t_x, t_y);
    emit positionChanged(t_x, t_y);
}

void HButton::setVisibility(bool t_visibility){
    QPushButton::setVisible(t_visibility);
    emit visibilityChanged(t_visibility);
}

