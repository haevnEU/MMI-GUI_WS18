#include "appstate.h"

namespace app{

    AppState::AppState()
        : m_selectedToool(NO_SELECTION), m_selectedColor(NO_COLOR), m_selectedHeight(0), m_selectedWidth(0),
          m_selectedShape(nullptr) {

    }

    AppState::~AppState(){

    }

    Tool AppState::AppState::selectedTool(){
        return m_selectedToool;
    }

    void AppState::AppState::selectTool(Tool t_tool){
        m_selectedToool = t_tool;
    }

    QColor AppState::AppState::selectedColor(){
        return m_selectedColor;
    }

    void AppState::AppState::selectColor(QColor t_color){
        m_selectedColor = t_color;
    }

    qreal AppState::AppState::selectedHeight(){
        return m_selectedHeight;
    }

    void AppState::AppState::selectHeight(qreal t_height){
        m_selectedHeight = t_height;
    }

    qreal AppState::AppState::selectedWidth(){
        return m_selectedWidth;
    }

    void AppState::AppState::selectWidth(qreal t_width){
        m_selectedWidth = t_width;
    }

    QPoint AppState::AppState::selectedPosition(){
        return m_selectedPosition;
    }
    void AppState::AppState::selectPosition(QPoint t_position){
        m_selectedPosition = t_position;
    }

    void AppState::AppState::selectPosition(double t_x, double t_y){
        m_selectedPosition = QPoint(t_x, t_y);
    }

    QAbstractGraphicsShapeItem* AppState::AppState::selectedShape(){
       return m_selectedShape;
    }

    void AppState::selectShape(QAbstractGraphicsShapeItem* t_shape){
        m_selectedShape = t_shape;
    }

}
