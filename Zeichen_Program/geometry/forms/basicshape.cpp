#include "basicshape.h"

namespace geometry{
    namespace forms{

        int BasicShape::s_shapeCounter = 0;

        /**
         * This method will be used to set required variables.
         * @param t_x X coordinate of the shape.
         * @param t_y Y coordinate of the shape.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        BasicShape::BasicShape(double t_x, double t_y){
            m_id = s_shapeCounter;
            s_shapeCounter++;
            m_position = new Point(t_x, t_y);
        }

        /**
         * This method will be used to set required variables using another shape.
         * @param another shape to retreive data.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        BasicShape::BasicShape(BasicShape &another){
            m_id = s_shapeCounter;
            m_position = new Point(*another.position());
        }

        /**
         * This method will be used to clean up used resources.
         *
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        BasicShape::~BasicShape(){
            if(m_position != nullptr){
                delete m_position;
            }
        }

        /**
         * This method will be used to retreive the shape ID.
         *
         * @return ID of the shape
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        int BasicShape::id(){
            return m_id;
        }

        /**
         * This method will be used to retreive the parent of the shape.
         *
         * @return Parent of the shape
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        BasicShape* BasicShape::parent(){
            return m_parent;
        }

        /**
         * This method will be used to set the parent of the shape.
         *
         * @param t_parent New Parent of the shape.
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void BasicShape::parent(BasicShape* t_parent){
            m_parent = t_parent;
        }

        /**
         * This method will be used to retreive the position of the shape.
         *
         * @return Position from the shape
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        Point* BasicShape::position(){
            return m_position;
        }

        /**
         * This method will be used to set the position of the shape.
         *
         * @param t_position New position of the shape.
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void BasicShape::position(Point* t_position){
            m_position = new Point(t_position->X(), t_position->Y());
        }

        /**
         * This method will be used to retreive the area of the shape.
         *
         * @return Area from the shape
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        double BasicShape::area(){
            return m_area;
        }

        /**
         * This method will be used to set the area of the shape.
         *
         * @param t_area New area of the shape.
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void BasicShape::area(double t_area){
            m_area = t_area;
        }

        /**
         * This method will be used to retreive the circumference of the shape.
         *
         * @return Circumference from the shape.
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        double BasicShape::circumference(){
            return m_circumference;
        }

        /**
         * This method will be used to set the circumference of the shape.
         *
         * @param t_circumference New circumference.
         * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
         * @date 12/02/2018
         */
        void BasicShape::circumference(double t_circumference){
            m_circumference = t_circumference;
        }

    }
}
