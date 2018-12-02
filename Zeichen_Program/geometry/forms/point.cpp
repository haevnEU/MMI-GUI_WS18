#include "point.h"

namespace geometry {
    namespace forms{

        /**
         * This method will be used to ceate a new point.
         * @param t_x X coordinate of the point.
         * @param t_y Y coordinate of the point.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Point::Point(double t_x, double t_y) : m_x(t_x), m_y(t_y){

        }

        /**
         * This method will be used to ceate a new point using an existing one.
         * @param another Point which should be copied.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Point::Point(Point &another){
            m_x = another.X();
            m_y = another.Y();
        }

        /**
         * This method will be used to clean up used resources.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Point::~Point(){

        }

        /**
         * This method will be used to set the X coordinate of the point.
         * @param t_x New X coordinate of the point.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void Point::X(double t_x){
            m_x = t_x;
        }

        /**
         * This method will be used to retreive the x coordinate of the circle.
         *
         * @return X coordinate of the point
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        double Point::X(){
            return m_x;
        }

        /**
         * This method will be used to set the Y coordinate of the point.
         * @param t_y New Y coordinate of the point.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void Point::Y(double t_y){
            m_y = t_y;
        }

        /**
         * This method will be used to retreive the y coordinate of the circle.
         *
         * @return Y coordinate of the point
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        double Point::Y(){
            return m_y;
        }


        /**
         * This method will be to print all variables from this point.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void Point::print(){
            std::cout << "[x/y] [" << m_x << "/" << m_y << "]" << std::endl;
        }
    }
}

