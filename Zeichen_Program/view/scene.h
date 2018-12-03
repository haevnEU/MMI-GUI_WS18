#ifndef ZEICHEN_PRORGAMM_VIEW_Scene_H_
#define ZEICHEN_PRORGAMM_VIEW_Scene_H_

#include <list>
#include "geometry/forms/basicshape.h"

namespace view{

    /**
     * @file scene.h
     * @brief This header file will be used as a scenegraph.
     *
     * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
     *
     * @version 1.0
     * @date 12/02/2018
     */
    class Scene{
    private:
        /// Scenegraph
        std::list<geometry::forms::BasicShape*> m_items;

    public:

        /**
         * This method will create an empty scenegraph.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Scene();

        /**
         * This method will copy a scenegraph.
         *
         * @param another Another scenegraph
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Scene(Scene &another);

        /**
         * This method will destruct the object an release used resource.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        ~Scene();

        /**
         * This method will add an existing shape(@see tools.h) to the scene graph.<br>
         *
         * @param t_shape Shape which should be displayed, the abstract class BasicShape must be implemented.
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void addItem(geometry::forms::BasicShape* t_shape);

        /**
         * This method will remove a shape(@see tools.h) to the scene graph.
         *
         * @param t_id Object id which should be removed from the scene graph.
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void removeItem(int t_id);

        /**
         * This method will render the scenegraph and display it to screen.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void render();
    };
}

#endif //ZEICHEN_PRORGAMM_VIEW_CENE_H_
