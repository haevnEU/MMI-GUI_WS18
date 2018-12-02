#include "app.h"

namespace app{

    /**
    * This method will be used to create a new App instance
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    */
    App::App(){
        m_scene = new view::Scene();
        m_state = new AppState();
    }

    /**
    * This method will be used to clean up used pointer
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    */
    App::~App(){
        delete m_state;
        delete m_scene;
    }

    /**
    * This metod will be used to handle user input on the canvas.
    * First the selected shape will be examinated if none is selected the operation will abort
    * After the examination default variables are retreived to operate on
    * Next step is the execution of a selected command
    * Finally the result will be rendered on screen
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    * @code app.onCanvasClicked();
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

    /**
    * This method will be used to retreive the scenegraph
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    */
    view::Scene* App::scene(){
        return m_scene;
    }

    /**
    * This method will be used to retreive the current state
    * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
    * @date 12/02/2018
    */
    AppState* App::state(){
        return m_state;
    }
}
