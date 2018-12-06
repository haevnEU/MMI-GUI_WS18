#include "IBaseElement.h"

namespace core{
    namespace objects{

        IBaseElement::IBaseElement(){

        }

        IBaseElement::~IBaseElement(){

        }


        QString IBaseElement::getName(){
            return m_name;
        }

        void IBaseElement::setName(QString t_name){
            m_name = t_name;
        }

        QString IBaseElement::getToolTip(){
            return m_tooltip;
        }

        void IBaseElement::setToolTip(QString t_tooltip){
            m_tooltip = t_tooltip;
        }

        QString IBaseElement::getAction(){
            return m_action;
        }

        void IBaseElement::setAction(QString t_action){
            m_action = t_action;
        }

        double IBaseElement::getWidth(){
            return m_width;
        }

        void IBaseElement::setWidth(double t_width){
            m_width = t_width;
        }

        double IBaseElement::getMaxWidth(){
            return m_maxWidth;
        }

        void IBaseElement::setMaxWidth(double t_width){
            m_maxWidth = t_width;
        }

        double IBaseElement::getMinWidth(){
            return m_minWidth;
        }

        void IBaseElement::setMinWidth(double t_width){
            m_minWidth = t_width;
        }

        double IBaseElement::getHeight(){
            return m_height;
        }

        void IBaseElement::setHeight(double t_height){
            m_height = t_height;
        }

        double IBaseElement::getMaxHeight(){
            return m_maxHeight;
        }

        void IBaseElement::setMaxHeight(double t_height){
            m_maxHeight = t_height;
        }

        double IBaseElement::getMinHeight(){
            return m_minHeight;
        }

        void IBaseElement::setMinHeight(double t_height){
            m_minHeight = t_height;
        }

        bool IBaseElement::getEnabled(){
            return m_enabled;
        }

        void IBaseElement::setEnabled(bool t_enabled){
            m_enabled = t_enabled;
        }

        int IBaseElement::getColor(){
            return m_color;
        }

        void IBaseElement::setColor(int t_color){
            m_color = t_color;
        }

        int IBaseElement::getVisibility(){
            return m_visibility;
        }

        void IBaseElement::setVisibility(int t_visibility){
            m_visibility = t_visibility;
        }

        void IBaseElement::clear(){
            m_name = "";
            m_tooltip = "";
            m_action = "";

            m_width = 0;
            m_minWidth= 0;
            m_maxWidth = 0;

            m_height = 0;
            m_minHeight = 0;
            m_maxHeight = 0;

            m_enabled = true;

            m_color = 0;
            m_visibility = 0;
        }

    }
}
