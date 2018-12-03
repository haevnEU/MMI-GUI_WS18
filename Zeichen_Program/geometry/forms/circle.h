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

         // Variables
         private:

            /// Radius of the circle
            double m_radius;

         // Methods
         private:
            void circumference(double t_circumference);
            void area(double t_area);

         public:

             /**
              * This method will be used to ceate a new circle.
              * @param t_x X coordinate of the circle.
              * @param t_y Y coordinate of the circle.
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             Circle(double t_radius = 0, double t_x = 0, double t_y = 0);

             /**
              * This method will be used to ceate a new circle using an existing one.
              * @param another Circle which should be copied.
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             Circle(Circle &another);

             /**
              * This method will destruct the object an release used resource.
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             ~Circle();

             /**
              * This method will be used to retreive the radius of the circle.
              *
              * @return Area from the shape
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             double radius();

             /**
              * This method will be used to set the radius of the circle.<br>
              * The area and circumference will also be set
              *
              * @param t_area New area of the shape.
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             void radius(double t_radius);

             /**
              * This method will be to print all variables from this circle.
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             void print();

             /**
              * This method will add this circle and the rvalue circle together.<br>
              * Radii and position are added
              * @param another
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             Circle* operator+ (Circle &another){
                 double r = radius() + another.radius();
                 double x = position()->X() + another.position()->X();
                 double y = position()->Y() + another.position()->Y();
                 return new Circle(r, x, y);
             }

             /**
              * This method will add another circle to this one<br>
              * Radii and position are added
              * @param another
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             void operator+= (Circle &another){
                 radius(radius() + another.radius());
                 position()->X(position()->X() + another.position()->X());
                 position()->Y(position()->Y() + another.position()->Y());

             }

             /**
              * This method will subtract the rvalue circle from this circle.<br>
              * Radii and position are subtracted
              * @param another
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             Circle* operator- (Circle &another){
                 double r = radius() + another.radius();
                 double x = position()->X() - another.position()->X();
                 double y = position()->Y() - another.position()->Y();
                 return new Circle(r, x, y);
             }

             /**
              * This method will add subtract circle to this one<br>
              * Radii and position are subtracted
              * @param another
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             void operator-= (Circle &another){
                 radius(radius() - another.radius());
                 position()->X(position()->X() - another.position()->X());
                 position()->Y(position()->Y() - another.position()->Y());

             }

             /**
              * This method will check if this circle is smaller than the other one<br>
              * @param another
              * @return true iff this circle is smaller then the rvalue circle
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             bool operator< (Circle &another){
                 return radius() < another.radius();
             }

             /**
              * This method will check if this circle is greater than the other one<br>
              * @param another
              * @return true iff this circle is greater then the rvalue circle
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             bool operator> (Circle &another){
                 return radius() > another.radius();
             }
         };
    }
}

#endif //ZEICHEN_PRORGAMM_GEOMETRY_FORMS_CIRCLE_H_
