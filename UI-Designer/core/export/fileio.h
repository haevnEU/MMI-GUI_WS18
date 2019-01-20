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
                const char seperator = '\\';
            #else
                const char seperator = '/';
            #endif

                void write(const char* path, const char* data);
                void write(const char* data);

            const char* read(const char* path);

            bool fileExist(const char* path);

        }
    }
}

#endif // DATAEXPORT_H
