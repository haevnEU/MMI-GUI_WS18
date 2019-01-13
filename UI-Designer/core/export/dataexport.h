#ifndef DATAEXPORT_H
#define DATAEXPORT_H

#include <QObject>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QWidget>

// singleton

// end singleton
namespace haevn{
    namespace core{
        namespace exporting{
                class DataExport : public QObject{
                    Q_OBJECT

                // public static methods
                public:
                    DataExport* getInstance(QObject* parent = nullptr);

                // static variables
                private:
                    static DataExport* s_instance;

                // public methods
                public:

                    virtual ~DataExport();
                    void setScenegraph(QList<QGraphicsItem*>* t_scenegraph);

                    int getWidth(int id);
                    int getMinWidth(int id);
                    int getMaxWidth(int id);

                    int getHeigth(int id);
                    int getMinHeight(int id);
                    int getMaxHeight(int id);

                    int getPosX(int id);
                    int getPosY(int id);

                    QString getTooltip(int id);
                    QString getName(int id);
                    QString getContent(int id);

                // private methods
                private:
                    explicit DataExport(QObject *parent = nullptr) : QObject(parent){}

                    // No need for copy ctor
                    explicit DataExport(DataExport& another){}

                // private variables
                private:
                    QList<QGraphicsItem*>* m_scenegraph;

                signals:

                public slots:

                };
        }
    }
}
#endif // DATAEXPORT_H
