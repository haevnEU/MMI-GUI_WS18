#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QListWidget>
#include <QMap>

#include "core/export/fileio.h"

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


            // static variables
            private:

             // public methods
             public:

                /**
                 * @brief Constructor
                 * @details The constructor isnt available public.
                 * It isnt public available due to singleton pattern.
                 * @param parent
                 */
                explicit Model();              

                virtual ~Model();

                /**
                 * @brief Gets all available scripts
                 * @details This Method returns a pointer to a map which contains all scripts,
                 * which were declared inside a scripts.toc file, which is placed in the root directory
                 * @return  QMap<QString, QString>*
                 */
                QMap<QString, QString>* getScripts();

                /**
                 * @brief Insert a new script to the script map
                 * @details This adds a new script to the available scripts map.
                 * Note this should be called if the scripts.toc file is read.
                 * @param name Name of the script, e.g. javaFX
                 * @param path OS specific path to the script
                 */
                void insertScript(QString name, QString path);

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


            // private variables
            private:
                /**
                 * @brief This variable represents the scenegraph
                 */
                QList<QWidget*>* m_scenegraph;

                /**
                 * @brief This variable represents all available scripts read by scripts.toc
                 */
                QMap<QString, QString>* m_scripts;

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
