#include "scene.h"

namespace view{

    Scene::Scene(){

    }

    Scene::Scene(Scene &another){

    }

    Scene::~Scene(){
        // Destruct every shape
        for(std::list<geometry::forms::BasicShape*>::iterator it = m_items.begin(); it != m_items.end(); ++it){
           delete (*it);
        }
    }

    void Scene::addItem(geometry::forms::BasicShape* t_shape){
        m_items.push_back(t_shape);
    }

    void Scene::removeItem(int t_id){
        // Retreive an interator and iterate over the list until its rechaed the end
        for(std::list<geometry::forms::BasicShape*>::iterator it = m_items.begin(); it != m_items.end(); ++it){
            // Removes the object and returns
            if((*it)->id() == t_id){
                m_items.remove(*it);
                return;
            }
        }
    }

    void Scene::render(){
        std::cout << "Scene" << std::endl;
        for(std::list<geometry::forms::BasicShape*>::iterator it = m_items.begin(); it != m_items.end(); ++it){
            (*it)->print();
        }
    }
}
