#ifndef DATAEXPORT_H
#define DATAEXPORT_H

#include <iostream>
#include <fstream>

#include <QObject>
#include <QList>
#include <QGraphicsItem>
#include <QWidget>

namespace haevn{
    namespace core{
        namespace FileIO{
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

            const char* read(const char* path);

            /**
             * @brief This method will determine if a file exist.
             * @details This method will use basic io operation to determine the existence of a file.
             * @param path - const char* this parameter contains the path to the file.
             */
            bool fileExist(const char* path);

        }
    }
}

#endif // DATAEXPORT_H
