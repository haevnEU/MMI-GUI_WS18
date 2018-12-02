#ifndef ZEICHEN_PRORGAMM_GEOMETRY_FORMS_RECTANGLE_H_
#define ZEICHEN_PRORGAMM_GEOMETRY_FORMS_RECTANGLE_H_

#include "basicshape.h"

namespace geometry{
    namespace forms{
        class Rectangle : public BasicShape{
        private:
            double m_width, m_height;

            void circumference(double t_circumference);
            void area(double t_area);
        public:
            Rectangle(double t_width, double t_height, double t_x, double t_y);
            Rectangle(Rectangle &another);
            virtual ~Rectangle();

            double width();
            void width(double t_width);

            double height();
            void height(double t_height);

            void print();
        };

    }
}
#endif // ZEICHEN_PRORGAMM_GEOMETRY_FORMS_RECTANGLE_H_
