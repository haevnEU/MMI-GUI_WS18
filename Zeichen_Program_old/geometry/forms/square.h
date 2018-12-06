#ifndef ZEICHEN_PRORGAMM_GEOMETRY_FORMS_SQUARE_H_
#define ZEICHEN_PRORGAMM_GEOMETRY_FORMS_SQUARE_H_

#include <iostream>

#include "rectangle.h"

namespace geometry{
    namespace forms{

        /**
         * @file squre.h
         * @brief This header file will contain all requirements to implement a square
         *
         * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
         *
         * @version 1.0
         * @date 12/02/2018
         */
         class Square : public Rectangle{

         private:

             /**
              * This method will be used to set the width of the rectangle.<br>
              * The area and circumference will also be set.
              *
              * @param t_width New width of the rectangle
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             double width();

             /**
              * This method will be used to retreive the width of the rectangle.
              *
              * @return Width of the rectangle
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             void width(double t_width);

             /**
              * This method will be used to set the height of the rectangle.<br>
              * The area and circumference will also be set.
              *
              * @param t_height New width of the rectangle
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             double height();

             /**
              * This method will be used to retreive the height of the rectangle.
              *
              * @return Height of the rectangle
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             void height(double t_height);

             void area(double t_area);
             void circumference(double t_circumference);

         public:

             /**
              * This method will be used to ceate a new square.
              * @param t_side Side of the square.
              * @param t_x X coordinate of the point.
              * @param t_y Y coordinate of the point.
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             Square(double t_side, double t_x, double t_y);

             /**
              * This method will copy an existing square.
              * @param another Square to copy.
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             Square(Square &another);


             /**
              * This method will destruct the object an release used resource.
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             ~Square();

             /**
              * This method will be used to set the sidelength of the square.<br>
              * The area and circumference will also be set.
              *
              * @param t_side New side of the shape.
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             void side(double t_side);

             /**
              * This method will be used to retreive the sidelength of the square.
              *
              * @return Sidelength of the rectangle.
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             double side();

             /**
              * This method will be to print all variables from this square
              *
              * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
              * @date 12/02/2018
              */
             void print();
         };
    }
}

#endif // ZEICHEN_PRORGAMM_GEOMETRY_FORMS_SQUARE_H_
