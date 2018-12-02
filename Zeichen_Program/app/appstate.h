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

    public:

        AppState();
        ~AppState();


        Tool selectedTool();

        void selectTool(Tool t_tool);

        Color selectedColor();

        void selectColor(Color t_color);

        double selectedHeight();

        void selectHeight(double t_height);

        double selectedWidth();

        void selectWidth(double t_width);

        geometry::forms::Point selectedPosition();

        void selectPosition(geometry::forms::Point t_position);

        void selectPosition(double t_x, double t_y);

        geometry::forms::BasicShape* selectedShape();

        void selectShape(geometry::forms::BasicShape* t_shape);
    };
}

#endif // ZEICHEN_PRORGAMM_APP_APP_STATE_H_
