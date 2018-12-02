#ifndef ZEICHEN_PRORGAMM_GEOMETRY_FORMS_CIRCLE_H_
#define ZEICHEN_PRORGAMM_GEOMETRY_FORMS_CIRCLE_H_

#include <iostream>
#include <cmath>
#include <limits>

#include "basicshape.h"
namespace geometry{
    namespace forms{

        /**
         * @file circe.h
         * @brief This header file will contain all requirements to implement a circle
         *
         * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
         *
         * @version 1.0
         * @date 12/02/2018
         */
         class Circle : public BasicShape{
         private:

             /// Radius of the circle
            double m_radius;

            /**
             * This method will be used to set the circumference of the shape.<br>
             * To ensure right access this method must be private
             * @param t_circumference New area of the shape.
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void circumference(double t_circumference);

            /**
             * This method will be used to set the area of the shape.<br>
             * To ensure right access this method must be private
             * @param t_area New area of the shape.
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/02/2018
             */
            void area(double t_area);
         public:

             Circle(double t_radius = 0, double t_x = 0, double t_y = 0);

             Circle(Circle &another);
             ~Circle();

             void radius(double t_radius);

             double radius();

             void print();

             Circle* operator+ (Circle &another){
                 double r = radius() + another.radius();
                 double x = position()->X() + another.position()->X();
                 double y = position()->Y() + another.position()->Y();
                 return new Circle(r, x, y);
             }

             void operator+= (Circle &another){
                 radius(radius() + another.radius());
                 position()->X(position()->X() + another.position()->X());
                 position()->Y(position()->Y() + another.position()->Y());

             }

             Circle* operator- (Circle &another){
                 double r = radius() + another.radius();
                 double x = position()->X() - another.position()->X();
                 double y = position()->Y() - another.position()->Y();
                 return new Circle(r, x, y);
             }

             void operator-= (Circle &another){
                 radius(radius() - another.radius());
                 position()->X(position()->X() - another.position()->X());
                 position()->Y(position()->Y() - another.position()->Y());

             }

             bool operator< (Circle &another){
                 return radius() < another.radius();
             }

             bool operator> (Circle &another){
                 return radius() > another.radius();
             }
         };
    }
}

#endif //ZEICHEN_PRORGAMM_GEOMETRY_FORMS_CIRCLE_H_
