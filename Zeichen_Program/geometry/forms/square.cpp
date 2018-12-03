#include "square.h"

namespace geometry {
    namespace forms{

        Square::Square(double t_side, double t_x, double t_y)
            : Rectangle(t_side, t_side, t_x, t_y){
        }

        Square::Square(Square &another)
            : Rectangle(another.side(), another.side(), another.position()->X(), another.position()->Y()){
        }
        Square::~Square(){
        }

        void Square::side(double t_side){
            height(t_side);
            width(t_side);
        }

        double Square::side(){
            return (height() + width()) *0.5;
        }

        void Square::print(){
            std::cout
                    << "+----------------------------------------" << std::endl
                    << "| Square"  << std::endl
                    << "| [id] " << id() << std::endl
                    << "| [Position] " << position()->X() << "/" << position()->Y() << std::endl
                    << "| [Sidelength] " << width() << std::endl
                    << "| [Area] " << BasicShape::area() << std::endl
                    << "| [Circumference] " << BasicShape::circumference() << std::endl
                    << "+----------------------------------------" << std::endl
                    << std::endl;
        }

        // private method

        void Square::width(double t_width){
           Rectangle::width(t_width);
        }

        double Square::width(){
           return Rectangle::width();
        }

        void Square::height(double t_height){
            Rectangle::height(t_height);
        }

        double Square::height(){
            return Rectangle::height();
        }
    }
}
