#ifndef DATAEXPORT_H
#define DATAEXPORT_H

/*
 *
 +--------------------------------------+
 | TODO                                 |
 +--------------------------------------+
 |                                      |
 | [ ] Implement method getResourcePath |
 | [ ] Implement method getDataPath     |
 | [ ] Implement method read            |
 |                                      |
 +--------------------------------------+
 *
 */


#include <iostream>
#include <fstream>
#include <QApplication>

#include <QObject>
#include <QList>
#include <QFileDialog>
#include <QTextStream>

#include <QWidget>
#include <QMessageBox>
#include <QGraphicsItem>

namespace haevn{
    namespace core{
        namespace util{

            class FileUtils{

            public:

                FileUtils();
                ~FileUtils();

                #ifdef _WIN32
                    /// Windows file seperator
                    const char seperator = '\\';
                #else
                    /// Unix file seperator
                    const char seperator = '/';
                #endif

                /**
                 * @brief This method write a text to the disk
                 * @details This method will ask the user about a place to store
                 * the data. It will abort if an error occurred or the user canceled the action.
                 * @param data - const char* this parameter contains the text which should be stored.
                 */
                void write(const char* data);

                /**
                 * @brief This method will determine if a file exist.
                 * @details This method will use basic io operation to determine the existence of a file.
                 * @param path - const char* this parameter contains the path to the file.
                 */
                bool fileExist(const char* path);

                /**
                 * @brief This method will load scripts based on a toc file.
                 * @details This method will read the path to all available scripts.
                 * Each scriptpath must be defined inside the scripts.toc file.
                 * @return Map of available scripts.
                 */
                QMap<QString, QString>* loadScripts();

                /**
                 * @brief This method evaluates the healthy of the application files
                 * @details This method should be called on start up or if the user request it.
                 * It will run a procedure to verify that all files exists.
                 * It is also possible to reset the directory
                 * @param forceRepair - bool This can be set if the directory must be reseted, it is default disabled
                 */
                void checkFiles(bool forceRepair = false);
            private:

                /**
                 * @brief This method should be called iff the method checkFiles find finds a problem.
                 * This is an internal method which replace corupted files with new one.
                 * It will also create new files iff they not exist.
                 *
                 */
                void repairFiles();
            };
        }
    }
}

#endif // DATAEXPORT_H
