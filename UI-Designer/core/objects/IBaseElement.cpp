#include "IBaseElement.h"

namespace core{
    namespace objects{

        IBaseElement::IBaseElement(){ }

        IBaseElement::~IBaseElement(){ }

        QString IBaseElement::getName(){
            return m_name;
        }

        QString IBaseElement::getToolTip(){
            return m_tooltip;
        }

        QString IBaseElement::getAction(){
            return m_action;
        }

        double IBaseElement::getWidth(){
            return m_width;
        }

        double IBaseElement::getMaxWidth(){
            return m_maxWidth;
        }

        double IBaseElement::getMinWidth(){
            return m_minWidth;
        }

        double IBaseElement::getHeight(){
            return m_height;
        }

        double IBaseElement::getMaxHeight(){
            return m_maxHeight;
        }

        double IBaseElement::getMinHeight(){
            return m_minHeight;
        }

        bool IBaseElement::getEnabled(){
            return m_enabled;
        }

        int IBaseElement::getColor(){
            return m_color;
        }

        int IBaseElement::getVisibility(){
            return m_visibility;
        }

        QPoint IBaseElement::getPosition(){
            return m_position;
        }

    }
}
