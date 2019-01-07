#include "iabstractobject.h"

using namespace haevn::core::objects;

IAbstractObject::IAbstractObject(){

}

IAbstractObject::~IAbstractObject(){

}


IAbstractObject::IAbstractObject(IAbstractObject& another){
    m_posX = another.m_posX;
    m_posY = another.m_posY;

    m_width = another.m_width;
    m_maxWidth = another.m_maxWidth;
    m_minWidth = another.m_minWidth;

    m_height = another.m_height;
    m_maxHeight = another.m_maxHeight;
    m_minHeight = another.m_minHeight;

    m_content = another.m_content;
    m_tooltip = another.m_tooltip;

    m_background = another.m_background;
    m_foreground = another.m_foreground;

    m_visibility = another.m_visibility;

}
