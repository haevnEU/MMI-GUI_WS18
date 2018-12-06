#include "circle.h"

namespace geometry{
    namespace forms{

        Circle::Circle(double t_radius, double t_x, double t_y)
            : BasicShape(t_x, t_y), m_radius(t_radius){
            BasicShape::circumference(2 * M_PI * t_radius);
            BasicShape::area(M_PI * pow(t_radius, 2));
        }

        Circle::Circle(Circle &another)
            : BasicShape(another), m_radius(another.radius()){
            BasicShape::circumference(2 * M_PI * another.radius());
            BasicShape::area(M_PI * pow(another.radius(), 2));
        }

        Circle::~Circle(){
        }

        double  Circle::radius(){
            return m_radius;
        }

        void  Circle::radius(double t_radius){
            m_radius = t_radius;
            BasicShape::circumference(2 * M_PI * t_radius);
            BasicShape::area(M_PI * pow(t_radius, 2));
        }

        void Circle::print(){
            std::cout << "+----------------------------------------" << std::endl
                      << "| Circle"  << std::endl
                      << "| [id] " << id() << std::endl
                      << "| [Position] " << position()->X() << "/" << position()->Y() << std::endl
                      << "| [Radius] " << radius() << std::endl
                      << "| [Area] " << BasicShape::area() << std::endl
                      << "| [Circumference] " << BasicShape::circumference() << std::endl
                      << "+----------------------------------------" << std::endl
                      << std::endl;
        }

    }
}
