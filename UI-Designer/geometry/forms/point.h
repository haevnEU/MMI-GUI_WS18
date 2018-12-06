#ifndef ZEICHEN_PRORGAMM_GEOMETRY_FORMS_POINT_H_
#define ZEICHEN_PRORGAMM_GEOMETRY_FORMS_POINT_H_

#include <iostream>
namespace geometry{
    namespace forms {

        /**
         * @file point.h
         * @brief This header file will contain all requirements to implement a point
         *
         * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
         *
         * @version 1.0
         * @date 12/02/2018
         */
        class Point{
        // Variables
        private:
            /// X coordinate of the point
            double m_x;

            /// Y coordinate of the point
            double m_y;

        // Methods
        public:

            /**
             * This method will be used to ceate a new point.
             * @param t_x X coordinate of the point.
             * @param t_y Y coordinate of the point.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            Point(double t_x = 0, double t_y = 0);

            /**
             * This method will be used to ceate a new point using an existing one.
             * @param another Point which should be copied.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            Point(Point &another);

            /**
             * This method will destruct the object an release used resource.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            ~Point();

            /**
             * This method will be used to retreive the x coordinate of the circle.
             *
             * @return X coordinate of the point
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            double X();

            /**
             * This method will be used to set the X coordinate of the point.
             * @param t_x New X coordinate of the point.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */

            void X(double t_x);

            /**
             * This method will be used to retreive the y coordinate of the circle.
             *
             * @return Y coordinate of the point
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            double Y();

            /**
             * This method will be used to set the Y coordinate of the point.
             * @param t_y New Y coordinate of the point.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void Y(double t_y);

            /**
             * This method will be to print all variables from this point.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void print();
        };

    }

}

#endif // ZEICHEN_PRORGAMM_GEOMETRY_FORMS_POINT_H_
