#ifndef ZEICHEN_PRORGAMM_GEOMETRY_FORMS_RECTANGLE_H_
#define ZEICHEN_PRORGAMM_GEOMETRY_FORMS_RECTANGLE_H_

#include "basicshape.h"

namespace geometry{
    namespace forms{

        /**
         * @file rectangle.h
         * @brief This header file will contain all requirements to implement a rectangle
         *
         * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
         *
         * @version 1.0
         * @date 12/02/2018
         */
        class Rectangle : public BasicShape{
        // Variables
        private:

            /// Width of the rectangle
            double m_width;

            /// Height of the rectangle
            double m_height;

        // Methods
        private:
            void circumference(double t_circumference);

            void area(double t_area);
        public:

            /**
             * This method will be used to ceate a new rectangle.
             * @param t_width Width of the rectangle.
             * @param t_height Height of the rectangle.
             * @param t_x X coordinate of the point.
             * @param t_y Y coordinate of the point.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            Rectangle(double t_width, double t_height, double t_x, double t_y);

            /**
             * This method will be used to ceate a new rectangle.
             * @param another Width of the rectangle.
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            Rectangle(Rectangle &another);

            /**
             * This method will destruct the object an release used resource.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            virtual ~Rectangle();

            /**
             * This method will be used to retreive the width of the rectangle.
             *
             * @return Width of the rectangle
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            double width();

            /**
             * This method will be used to set the width of the rectangle.<br>
             * The area and circumference will also be set.
             *
             * @param t_width New width of the rectangle
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void width(double t_width);

            /**
             * This method will be used to retreive the height of the rectangle.
             *
             * @return Height of the rectangle
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            double height();

            /**
             * This method will be used to set the height of the rectangle.<br>
             * The area and circumference will also be set.
             *
             * @param t_height New height of the rectangle
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void height(double t_height);

            /**
             * This method will be to print all variables from this rectangle
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void print();
        };

    }
}
#endif // ZEICHEN_PRORGAMM_GEOMETRY_FORMS_RECTANGLE_H_
