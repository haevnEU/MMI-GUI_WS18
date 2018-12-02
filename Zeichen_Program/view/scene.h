#ifndef ZEICHEN_PRORGAMM_VIEW_Scene_H_
#define ZEICHEN_PRORGAMM_VIEW_Scene_H_

#include <list>
#include "geometry/forms/basicshape.h"

namespace view{
    /**
     * @brief Scene class
     * @author Nils Milewski (nimile)
     * Purpose: This class describes visual aspects of the application
     */
    class Scene{
    private:
        std::list<geometry::forms::BasicShape*> m_items;
    public:

        Scene();
        Scene(Scene &another);
        ~Scene();

        /**
         * @brief addItem Adds an item to the scene graph
         * @param t_shape Shape which should be displayed, the abstract class BasicShape must be implemented
         * This method adds an BasicShape to the scene graph<br>
         * Current possible shapes are
         * <ul>
         * <li>@code Circle </li>
         * <li>@code Rectangle </li>
         * <li>@code Square </li>
         * <li>@code Point </li>
         * </ul>
        */
        void addItem(geometry::forms::BasicShape* t_shape);

        /**
         * @brief removeItem
         * @param t_id
         */
        void removeItem(int t_id);

        /**
         * @brief render Renders the scenegraph
         * This method display each node from the scenegraph
         */
        void render();
    };
}

#endif //ZEICHEN_PRORGAMM_VIEW_CENE_H_
