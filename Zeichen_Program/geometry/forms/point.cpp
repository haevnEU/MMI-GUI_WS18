#include "point.h"

namespace geometry {
    namespace forms{

        Point::Point(double t_x, double t_y) : m_x(t_x), m_y(t_y){

        }

        Point::Point(Point &another){
            m_x = another.X();
            m_y = another.Y();
        }

        Point::~Point(){

        }

        double Point::X(){
            return m_x;
        }

        void Point::X(double t_x){
            m_x = t_x;
        }

        double Point::Y(){
            return m_y;
        }

        void Point::Y(double t_y){
            m_y = t_y;
        }

        void Point::print(){
            std::cout << "[x/y] [" << m_x << "/" << m_y << "]" << std::endl;
        }
    }
}

