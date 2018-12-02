#ifndef ZEICHEN_PRORGAMM_App_App_H_
#define ZEICHEN_PRORGAMM_App_App_H_

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
        view::Scene* m_scene;

        //// the state which the application is currently hold
        AppState* m_state;

     public:

        App();

        ~App();

        void onCanvasClicked();

        view::Scene* scene();

        AppState* state();
    };
}

#endif // ZEICHEN_PRORGAMM_App_App_H_
