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
        private:
            /// X coordinate of the point
            double m_x;

            /// Y coordinate of the point
            double m_y;
        public:
            Point(double t_x = 0, double t_y = 0);

            Point(Point &another);

            ~Point();

            void X(double t_x);

            double X();

            void Y(double t_y);

            double Y();

            void print();
        };

    }

}

#endif // ZEICHEN_PRORGAMM_GEOMETRY_FORMS_POINT_H_
