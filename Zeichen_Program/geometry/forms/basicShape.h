#ifndef ZEICHEN_PRORGAMM_GEOMETRY_FORMS_BASICSHAPE_H_
#define ZEICHEN_PRORGAMM_GEOMETRY_FORMS_BASICSHAPE_H_

#include "point.h"

namespace geometry {
    namespace forms{

        /**
         * @file basicshape.h
         * @brief This header file will contain all requirements for an basicshape.<br>
         * A basic is the supper class of each new shape
         *
         * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
         *
         * @version 1.0
         * @date 12/02/2018
         */
        class BasicShape{
        private:
            /// Used to create unique IDs, possible through incrementing special counter
            static int s_shapeCounter;

            /// Parent of this shape
            BasicShape* m_parent;

            /// Position of this shape
            Point *m_position;

            /// the area of the shape
            double m_area;

            /// The circumference of the shape
            double m_circumference;

            /// The id from the shape
            int m_id;
        public:
            BasicShape(double t_x, double t_y);

            BasicShape(BasicShape &another);

            virtual ~BasicShape();

            int id();

            BasicShape* parent();

            void parent(BasicShape* t_parent);

            Point* position();

            void position(Point* t_position);

            double area();

            void area(double t_area);

            double circumference();

            void circumference(double t_circumference);

            virtual void print() = 0;

            bool operator==(BasicShape& another){
                return another.id() == id();
            }
        };
    }
}

#endif // ZEICHEN_PRORGAMM_GEOMETRY_FORMS_BASICSHAPE_H_
