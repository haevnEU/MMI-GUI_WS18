#ifndef ZEICHEN_PRORGAMM_App_App_H_
#define ZEICHEN_PRORGAMM_App_App_H_

#include <QGraphicsScene>

#include "appstate.h"
#include "app/appstate.h"
#include "app/color.h"
#include "app/tool.h"
#include "view/scene.h"
#include "geometry/forms/circle.h"
#include "geometry/forms/square.h"
#include "geometry/forms/rectangle.h"
#include "geometry/forms/basicshape.h"

namespace app{

    /**
     * @file app.h
     * @brief This header file will contain all requirements to execute this porject
     *
     * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
     *
     * @version 1.0
     * @date 12/02/2018
     */
    class App{
    private:

         ///Scenegraph which the application will use.
         QGraphicsScene* m_scene;

        //// the state which the application is currently hold
        AppState* m_state;

     public:

        /**
         * This method will be used to create a new App instance
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        App();

        /**
         * This method will destruct the object an release used resource.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        ~App();

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
        void onCanvasClicked();

        /**
         * This method will be used to retreive the scenegraph
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        QGraphicsScene* scene();

        /**
         * This method will be used to retreive the current state
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        AppState* state();
    };
}

#endif // ZEICHEN_PRORGAMM_App_App_H_
