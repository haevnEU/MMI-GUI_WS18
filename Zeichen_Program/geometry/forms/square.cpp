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


        /**
         * This method will be to print all variables from this square
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
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


        double Square::side(){
            return (height() + width()) *0.5;
        }


        void Square::side(double t_side){
            height(t_side);
            width(t_side);
        }


        // private method

        double Square::width(){
           return Rectangle::width();
        }

        void Square::width(double t_width){
           Rectangle::width(t_width);
        }

        double Square::height(){
            return Rectangle::height();
        }
        void Square::height(double t_height){
            Rectangle::height(t_height);
        }
    }
}
