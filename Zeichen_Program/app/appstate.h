#ifndef ZEICHEN_PRORGAMM_APP_APP_STATE_H_
#define ZEICHEN_PRORGAMM_APP_APP_STATE_H_

#include "tool.h"
#include "color.h"
#include "geometry/forms/point.h"
#include "geometry/forms/basicshape.h"

namespace app{

    /**
     * @file appstate.h
     * @brief This header file will contain all required variables and functions to determine the state
     * of the application.
     *
     * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
     *
     * @version 1.0
     * @date 12/02/2018
     */
    class AppState{
    // Variables
    private:

         /// Tool which is currently selected for the next oepration.
        Tool m_selectedToool;

        /// Color which is currently selected to fill a shape.
        Color m_selectedColor;

         /// Height which is currently used.
        double m_selectedHeight;


        /// Width which is currently used.
        double m_selectedWidth;

        /// Position which is currently used
        geometry::forms::Point m_selectedPosition;

        /// Shape which the next oepration will operate on
        geometry::forms::BasicShape* m_selectedShape;

    // Methods
    public:

        /**
         * This method will be used to construct the state of the application
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        AppState();

        /**
         * This method will destruct the object an release used resource.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        ~AppState();

        /**
        * This method will be used to retreive the currently selected tool
        * @see tool.h
        * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
        * @date 12/02/2018
        * @return Currently selected tool
        */
        Tool selectedTool();

        /**
         * This method will be used to set the currently selected tool
         * @see tool.h
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @param t_tool new tool to operate with
         */
        void selectTool(Tool t_tool);


        /**
         * This method will be used to retreive the currently selected color
         * @see color.h
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @return Currently selected color
         */
        Color selectedColor();

        /**
         * This method will be used to set the currently color
         * @see color.h
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @param t_color new color to operate with
         */
        void selectColor(Color t_color);

        /**
         * This method will be used to retreive the currently used height
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @return Currently used height
         */
        double selectedHeight();

        /**
         * This method will be used to set the currently used height
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @param t_height New height to operate with
         */
        void selectHeight(double t_height);

        /**
         * This method will be used to retreive the currently used width
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @return Currently used width
         */
        double selectedWidth();

        /**
         * This method will be used to set the currently used width
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @param t_width New width to operate with
         */
        void selectWidth(double t_width);

        /**
         * This method will be used to retreive the currently used position
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @return Currently used position
         */
        geometry::forms::Point selectedPosition();

        /**
         * This method will be used to set the currently used position
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @param t_positionNew position to operate with
         */
        void selectPosition(double t_x, double t_y);

        /**
         * This method will be used to set the currently used position
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @param t_x X coordinate to operate with
         * @param t_y Y coordinate to operate with
         */
        void selectPosition(geometry::forms::Point t_position);

        /**
         * This method will be used to retreive the currently used shape
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @return Currently used shape
         */
        geometry::forms::BasicShape* selectedShape();

        /**
         * This method will be used to set the currently used shape
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         * @param t_shape New shape to operate with
         */
        void selectShape(geometry::forms::BasicShape* t_shape);
    };
}

#endif // ZEICHEN_PRORGAMM_APP_APP_STATE_H_
