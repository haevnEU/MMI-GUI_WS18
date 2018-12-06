#include "basicshape.h"

namespace geometry{
    namespace forms{

        unsigned int BasicShape::s_shapeCounter = 0;

        BasicShape::BasicShape(double t_x, double t_y){
            m_id = s_shapeCounter;
            s_shapeCounter++;
            m_position = new Point(t_x, t_y);
        }

        BasicShape::BasicShape(BasicShape &another){
            m_id = s_shapeCounter;
            m_position = new Point(*another.position());
        }

        BasicShape::~BasicShape(){
            if(m_position != nullptr){
                delete m_position;
            }
        }

        unsigned int BasicShape::id(){
            return m_id;
        }

        BasicShape* BasicShape::parent(){
            return m_parent;
        }

        void BasicShape::parent(BasicShape* t_parent){
            m_parent = t_parent;
        }

        Point* BasicShape::position(){
            return m_position;
        }

        void BasicShape::position(Point* t_position){
            m_position = new Point(t_position->X(), t_position->Y());
        }

        double BasicShape::area(){
            return m_area;
        }

        void BasicShape::area(double t_area){
            m_area = t_area;
        }

        double BasicShape::circumference(){
            return m_circumference;
        }

        void BasicShape::circumference(double t_circumference){
            m_circumference = t_circumference;
        }
    }
}
