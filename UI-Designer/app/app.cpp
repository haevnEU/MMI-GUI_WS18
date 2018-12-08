#include "app.h"

namespace app{

    App::App(){
        m_scene = new QGraphicsScene();
        m_scene->setBackgroundBrush(Qt::darkGray);
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

        double x = m_state->selectedPosition().x();
        double y = m_state->selectedPosition().y();
        double width = m_state->selectedWidth();
        double height = m_state->selectedHeight();
        double side = (height + width) * 0.5;
        QAbstractGraphicsShapeItem* item;
        // (3) Execute the operation
        switch(m_state->selectedTool()){
        case Tool::CIRCLE:
            item = new QGraphicsEllipseItem(x, y, side, side);
            break;
        case Tool::RECTANGLE:
            item = new QGraphicsRectItem(width, height, x, y);
            break;
        case Tool::SQUARE:
            item = new QGraphicsRectItem(x, y, side, side);
            break;
        case Tool::DELETE:
           // m_scene->removeItem(m_state->selectedShape()->id());
            break;

        case Tool::BUTTON:
            core::objects::Button* bt = new core::objects::Button("TEST");
            bt->move(QCursor::pos());
            m_scene->addWidget(bt);
            break;
        }
      /*  item->setBrush(m_state->selectedColor());
        m_scene->addItem(item);*/
       }

    QGraphicsScene* App::scene(){
        return m_scene;
    }

    AppState* App::state(){
        return m_state;
    }

}
