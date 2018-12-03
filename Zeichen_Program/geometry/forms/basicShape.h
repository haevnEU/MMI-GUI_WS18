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
        // Variables
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

        // Methods
        public:

            /**
             * This method will be used to set required variables.
             * @param t_x X coordinate of the shape.
             * @param t_y Y coordinate of the shape.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            BasicShape(double t_x, double t_y);

            /**
             * This method will be used to set required variables using another shape.
             * @param another shape to retreive data.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            BasicShape(BasicShape &another);

            /**
             * This method will destruct the object an release used resource.
             *
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            virtual ~BasicShape();

            /**
             * This method will be used to retreive the shape ID.
             *
             * @return ID of the shape
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            int id();

            /**
             * This method will be used to retreive the parent of the shape.
             *
             * @return Parent of the shape
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            BasicShape* parent();

            /**
             * This method will be used to set the parent of the shape.
             *
             * @param t_parent New Parent of the shape.
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void parent(BasicShape* t_parent);

            /**
             * This method will be used to retreive the position of the shape.
             *
             * @return Position from the shape
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            Point* position();

            /**
             * This method will be used to set the position of the shape.
             *
             * @param t_position New position of the shape.
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void position(Point* t_position);

            /**
             * This method will be used to retreive the area of the shape.
             *
             * @return Area from the shape
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            double area();

            /**
             * This method will be used to set the area of the shape.
             *
             * @param t_area New area of the shape.
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void area(double t_area);

            /**
             * This method will be used to retreive the circumference of the shape.
             *
             * @return Circumference from the shape.
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            double circumference();

            /**
             * This method will be used to set the circumference of the shape.
             *
             * @param t_circumference New circumference.
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void circumference(double t_circumference);

            virtual void print() = 0;


            /**
             * This method will be used to made a equality tesz.
             *
             * @param another Second object to compate with.
             * @return true iff booth shapes share the same id
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            bool operator==(BasicShape& another){
                return another.id() == id();
            }
        };
    }
}

#endif // ZEICHEN_PRORGAMM_GEOMETRY_FORMS_BASICSHAPE_H_
