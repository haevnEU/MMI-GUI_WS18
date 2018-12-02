#include "rectangle.h"

namespace geometry{
    namespace forms{

        Rectangle::Rectangle(double t_width, double t_height, double t_x, double t_y)
            : BasicShape (t_x, t_y), m_width(t_width), m_height(t_height){
            BasicShape::area(m_width * m_height);
            BasicShape::circumference(2 * (m_width + m_height));

        }

         Rectangle::Rectangle(Rectangle &another)
             : BasicShape(another.position()->X(), another.position()->Y()), m_width(another.width()), m_height(another.height()){

             BasicShape::area(another.width() * another.height());
             BasicShape::circumference(2 * (another.width() + another.height()));
        }

        Rectangle::~Rectangle(){
        }

        double Rectangle::width(){
           return m_width;
        }

        void Rectangle::width(double t_width){
           m_width = t_width;
           BasicShape::area(m_width * m_height);
           BasicShape::circumference(2 * (m_width + m_height));
        }

        double Rectangle::height(){
            return m_height;
        }
        void Rectangle::height(double t_height){
            m_height = t_height;
            BasicShape::area(m_width * m_height);
            BasicShape::circumference(2 * (m_width + m_height));
        }


        /**
         * This method will be to print all variables from this rectangle
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void Rectangle::print(){
            std::cout
                    << "+----------------------------------------" << std::endl
                    << "| Rectangle"  << std::endl
                    << "| [id] " << id() << std::endl
                    << "| [Position] " << position()->X() << "/" << position()->Y() << std::endl
                    << "| [Width] " << width() << std::endl
                    << "| [Height] " << height() << std::endl
                    << "| [Area] " << BasicShape::area() << std::endl
                    << "| [Circumference] " << BasicShape::circumference() << std::endl
                    << "+----------------------------------------" << std::endl
                    << std::endl;
        }
    }
}
