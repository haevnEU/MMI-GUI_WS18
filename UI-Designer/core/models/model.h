#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QListWidget>

namespace haevn{
    namespace core {
        namespace models{

            /**
             * @brief This class represent the application data
             * @details The Model class is a singleton object and
             * will contain data and operation which every
             * object requires.
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 15, 2019
             */
            class Model : public QObject{
                Q_OBJECT

            // public static methods
            public:

                /**
                 * @brief Gets the instance
                 * @details GetInstance returns the existing instance,
                 * new one is created iff theres no existing one.
                 * @return Model Only existing instance
                 */
                static Model* getInstance();

            // static variables
            private:
                /// Only allowed instance
                static Model* s_instance;

             // public methods
             public:

                virtual ~Model();

                /**
                 * @brief Gets the scenegraph
                 * @details This Method returns a pointer to the scenegraph
                 * @return QList<QWidget*>*
                 */
                QList<QWidget*>* getScenegraph();

                /**
                 * @brief Sets the path to resources
                 * @details This method will set the path to the resource folder
                 * The resource folder contains everything what the application
                 * needs to operate.
                 * See readme for further information about resource folder.
                 * @param t_resourcePath - String which represent the OS specific path
                 */
                void setResourcePath(QString t_resourcePath);

                /**
                 * @brief Gets the path to the resource folder
                 * @details This method will return an OS specific path to the
                 * resource folder.
                 * @return String
                 */
                QString getResourcePath();

            // private methods
            private:

                /**
                 * @brief Constructor
                 * @details The constructor isnt available public.
                 * It isnt public available due to singleton pattern.
                 * @param parent
                 */
                explicit Model();

                /**
                 * @brief Coppy constructor
                 * @details The copy constructor isnt available public.
                 * It isnt public available due to singleton pattern.
                 * @param another - Reference to another instance
                 */
                explicit Model(Model& another){}

                /**
                 * @brief Assignement operator.
                 * @details The assignement operator isnt available public.
                 * It isnt public available due to singleton pattern.
                 * @param another - Reference to another instance
                 */
                Model& operator=(Model& another){}

            // private variables
            private:
                /**
                 * @brief This variable represents the scenegraph
                 */
                QList<QWidget*>* m_scenegraph;

                /**
                 * @brief This variable represents the resourepath
                 */
                QString m_resourcePath;

            signals:


            public slots:

                /**
                 * @brief Adds an item to the scenegraph
                 * @details This method will add an item to the scenegraph.
                 * This is a slot which made a call by the scenegraph
                 * add item signal possible.
                 * @param t_item - Pointer to the item which should be added
                 */
                void addItem(QWidget* t_item);

                /**
                 * @brief Removes an item to the scenegraph
                 * @details This method will remove an item from the scenegraph.
                 * This is a slot which made a call by the scenegraph
                 * remove item signal possible.
                 * @param t_item - Pointer to the item which should be added
                 */
                void removeItem(QWidget* t_item);
            };
        }
    }
}
#endif // MODEL_H
