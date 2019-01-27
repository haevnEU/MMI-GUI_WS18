#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QListWidget>
#include <QMap>

#include "core/util/fileutils.h"

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

            private:
                /**
                 * @brief This variable represents the scenegraph
                 */
                QList<QWidget*>* m_scenegraph;

                /**
                  * @brief This variable represents all available scripts read by scripts.toc
                  */
                QMap<QString, QString>* m_scripts;

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
                 * @brief Loads the scripts from the toc file
                 * @details This method will read the script.toc in the root application directory.
                 * The scripts are placed in a QMap, the filename is used as the key and the path
                 * is used as a value.
                 */
                void loadScripts();

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
