#ifndef ZEICHEN_PRORGAMM_GEOMETRY_FORMS_SQUARE_H_
#define ZEICHEN_PRORGAMM_GEOMETRY_FORMS_SQUARE_H_

#include <iostream>

#include "rectangle.h"

namespace geometry{
    namespace forms{
         class Square : public Rectangle{
         private:

             double width();
             void width(double t_width);

             double height();
             void height(double t_height);

             void circumference(double t_circumference);
             void area(double t_area);

         public:
             Square(double t_side, double t_x, double t_y);
             Square(Square &another);
             ~Square();

             void side(double t_side);
             double side();

             void print();
         };
    }
}

#endif // ZEICHEN_PRORGAMM_GEOMETRY_FORMS_SQUARE_H_
