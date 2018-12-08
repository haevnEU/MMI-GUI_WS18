#include "button.h"

namespace core {
    namespace objects {

        Button::Button(QString t_text) {
            QPushButton::setText(t_text);
        }

        void Button::setAction(QString t_action){
            IBaseElement::m_action = t_action;

        }

        void Button::setName(QString t_name){
            IBaseElement::m_name = t_name;
            // TODO IMPLEMENT
        }

        void Button::setToolTip(QString t_tooltip){
            IBaseElement::m_tooltip = t_tooltip;
            QPushButton::setToolTip(m_tooltip);
        }

        void Button::setWidth(double t_width){
            IBaseElement::m_width = t_width;
            // TODO IMPLEMENT
        }

        void Button::setMaxWidth(double t_width){
            IBaseElement::m_maxWidth = t_width;
            QPushButton::setMaximumWidth(t_width);
        }

        void Button::setMinWidth(double t_width){
            IBaseElement::m_minWidth = t_width;
            QPushButton::setMinimumWidth(t_width);
        }


        void Button::setHeight(double t_height){
            IBaseElement::m_height = t_height;
            // TODO IMPLE;EMT
        }

        void Button::setMaxHeight(double t_height){
            IBaseElement::m_maxHeight = t_height;
            QPushButton::setMaximumHeight(t_height);
        }


        void Button::setMinHeight(double t_height){
            IBaseElement::m_minHeight = t_height;
            QPushButton::setMinimumHeight(t_height);
        }


        void Button::setEnabled(bool t_enabled){
            IBaseElement::m_enabled = t_enabled;
            QPushButton::setEnabled(t_enabled);
        }

        void Button::setColor(int t_color){
            IBaseElement::m_color = t_color;
            // TODO IMPLEMENT
        }

        void Button::setVisibility(int t_visibility){
            IBaseElement::m_visibility = t_visibility;
            // TODO IMPLEMENT
        }


    } // namespace objects
} // namespace core
