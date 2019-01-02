#include "hbutton.h"

using namespace haevn::core::objects;
using namespace haevn::core::objects::buttons;

buttons::HButton::HButton(QPushButton *parent) : QPushButton(parent), IAbstractObject()
{

}



void HButton::setHeight(double t_height){
    IAbstractObject::m_height = t_height;
    emit heightChanged(t_height);
}

void HButton::setMaxHeight(double t_maxHeight){

    IAbstractObject::m_maxHeight = t_maxHeight;
    emit maxHeightChanged(t_maxHeight);
}

void HButton::setMinHeight(double t_minHeight){

    IAbstractObject::m_minHeight = t_minHeight;
    emit minHeightChanged(t_minHeight);
}

void HButton::setWidth(double t_width){

    IAbstractObject::m_width = t_width;
    emit widthChanged(t_width);
}

void HButton::setMaxWidth(double t_maxWidth){

    IAbstractObject::m_maxWidth = t_maxWidth;
    emit maxWidthChanged(t_maxWidth);
}

void HButton::setMinWidth(double t_minWidth){

    IAbstractObject::m_minWidth = t_minWidth;
    emit minWidthChanged(t_minWidth);
}

void HButton::setPosition(double t_x, double t_y){


    IAbstractObject::m_posX = t_x;
    IAbstractObject::m_posY = t_y;
    emit positionChanged(t_x, t_y);
}

void HButton::setVisibility(bool t_visibility){

    IAbstractObject::m_visibility = t_visibility;
    emit visibilityChanged(t_visibility);
}

