#include "circle.h"

namespace geometry{
    namespace forms{

        /**
         * This method will be used to ceate a new circle.
         * @param t_x X coordinate of the circle.
         * @param t_y Y coordinate of the circle.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Circle::Circle(double t_radius, double t_x, double t_y)
            : BasicShape(t_x, t_y), m_radius(t_radius){
            BasicShape::circumference(2 * M_PI * t_radius);
            BasicShape::area(M_PI * pow(t_radius, 2));
        }

        /**
         * This method will be used to ceate a new circle using an existing one.
         * @param another Circle which should be copied.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Circle::Circle(Circle &another)
            : BasicShape(another), m_radius(another.radius()){
            BasicShape::circumference(2 * M_PI * another.radius());
            BasicShape::area(M_PI * pow(another.radius(), 2));
        }


        /**
         * This method will be used to clean up used resources.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Circle::~Circle(){
        }

        /**
         * This method will be used to set the radius of the circle.
         *
         * @param t_area New area of the shape.
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void  Circle::radius(double t_radius){
            m_radius = t_radius;
            BasicShape::circumference(2 * M_PI * t_radius);
            BasicShape::area(M_PI * pow(t_radius, 2));
        }

        /**
         * This method will be used to retreive the radius of the circle.
         *
         * @return Area from the shape
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        double  Circle::radius(){
            return m_radius;
        }


        /**
         * This method will be to print all variables from this circle.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
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
