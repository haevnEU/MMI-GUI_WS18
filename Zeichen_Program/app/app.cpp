#include "app.h"

namespace app{

    App::App(){
        m_scene = new view::Scene();
        m_state = new AppState();
    }

    App::~App(){
        delete m_state;
        delete m_scene;
    }

    /*
     * (1) First task is to verirfy that a shape was selected
     * (2) Second task is to retreive some base variables from the application state
     * (3) Next the selected operation will be executed
     * (4) Finally everything is rendered
     */
    void App::onCanvasClicked(){
        // (1) Determine if any shape was selected
        // if not the operation will abort
//        if(m_state->selectedShape() == nullptr){
//            return;
//        }


        // (2) Request couple variable which are required to add
        double x = m_state->selectedPosition().X();
        double y = m_state->selectedPosition().Y();
        double width = m_state->selectedWidth();
        double height = m_state->selectedHeight();
        double side = (height + width) * 0.5;

        // (3) Execute the operation
        switch(m_state->selectedTool()){
        case Tool::CIRCLE:
            m_scene->addItem(new geometry::forms::Circle(side, x, y));
            break;
        case Tool::RECTANGLE:
            m_scene->addItem(new geometry::forms::Rectangle(width, height, x, y));
            break;
        case Tool::SQUARE:
            m_scene->addItem(new geometry::forms::Square(side, x, y));
            break;
        case Tool::DELETE:
            m_scene->removeItem(m_state->selectedShape()->id());
            break;
        case Tool::NO_SELECTION:
            break;
        }

        // (4) Render the result to screen
        m_scene->render();
    }

    view::Scene* App::scene(){
        return m_scene;
    }

    AppState* App::state(){
        return m_state;
    }
}
