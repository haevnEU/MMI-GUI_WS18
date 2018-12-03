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
        // First step is to retreive an interator using the first entry
        // Next step is to iterate over each element until the list end is reached
        // With every step the iterator is increased
        for(std::list<geometry::forms::BasicShape*>::iterator it = m_items.begin(); it != m_items.end(); ++it){

            // Removes the item iff the iterator id equals to the param
            if((*it)->id() == t_id){
                m_items.remove(*it);
                return;
            }
        }
    }

    void Scene::render(){

        // Retreive an interator and iterate over the list until its rechaed the end
        // First step is to retreive an interator using the first entry
        // Next step is to iterate over each element until the list end is reached
        // With every step the iterator is increased
        for(std::list<geometry::forms::BasicShape*>::iterator it = m_items.begin(); it != m_items.end(); ++it){
           // Print the item to screen
            (*it)->print();
        }
    }
}
