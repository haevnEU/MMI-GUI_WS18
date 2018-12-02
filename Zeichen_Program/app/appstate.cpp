#include "appstate.h"

namespace app{

    /**
    * This method will be used to construct the state of the application
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    */
    AppState::AppState()
        : m_selectedToool(NO_SELECTION), m_selectedColor(BLUE), m_selectedHeight(0), m_selectedWidth(0),
          m_selectedShape(nullptr) {

    }

    /**
    * This method will be used to clean up used resources
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    */
    AppState::~AppState(){

    }

    /**
    * This method will be used to retreive the currently selected tool
    * @see tool.h
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @return Currently selected tool
    */
    Tool AppState::AppState::selectedTool(){
        return m_selectedToool;
    }

    /**
    * This method will be used to set the currently selected tool
    * @see tool.h
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @param t_tool new tool to operate with
    */
    void AppState::AppState::selectTool(Tool t_tool){
        m_selectedToool = t_tool;
    }

    /**
    * This method will be used to retreive the currently selected color
    * @see color.h
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @return Currently selected color
    */
    Color AppState::AppState::selectedColor(){
        return m_selectedColor;
    }

    /**
    * This method will be used to set the currently color
    * @see color.h
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @param t_color new color to operate with
    */
    void AppState::AppState::selectColor(Color t_color){
        m_selectedColor = t_color;
    }

    /**
    * This method will be used to retreive the currently used height
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @return Currently used height
    */
    double AppState::AppState::selectedHeight(){
        return m_selectedHeight;
    }

    /**
    * This method will be used to set the currently used height
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @param t_height New height to operate with
    */
    void AppState::AppState::selectHeight(double t_height){
        m_selectedHeight = t_height;
    }

    /**
    * This method will be used to retreive the currently used width
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @return Currently used width
    */
    double AppState::AppState::selectedWidth(){
        return m_selectedWidth;
    }

    /**
    * This method will be used to set the currently used width
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @param t_width New width to operate with
    */
    void AppState::AppState::selectWidth(double t_width){
        m_selectedWidth = t_width;
    }

    /**
    * This method will be used to retreive the currently used position
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @return Currently used position
    */
    geometry::forms::Point AppState::AppState::selectedPosition(){
        return m_selectedPosition;
    }

    /**
    * This method will be used to set the currently used position
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @param t_positionNew position to operate with
    */
    void AppState::AppState::selectPosition(geometry::forms::Point t_position){
        m_selectedPosition = t_position;
    }

    /**
    * This method will be used to set the currently used position
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @param t_x X coordinate to operate with
    * @param t_y Y coordinate to operate with
    */
    void AppState::AppState::selectPosition(double t_x, double t_y){
        m_selectedPosition = geometry::forms::Point(t_x, t_y);
    }

    /**
    * This method will be used to retreive the currently used shape
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @return Currently used shape
    */
    geometry::forms::BasicShape* AppState::AppState::selectedShape(){
       return m_selectedShape;
    }

    /**
    * This method will be used to set the currently used shape
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @param t_shape New shape to operate with
    */
    void AppState::selectShape(geometry::forms::BasicShape* t_shape){
        m_selectedShape = t_shape;
    }

}
