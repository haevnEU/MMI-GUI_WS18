#ifndef DATAEXPORT_H
#define DATAEXPORT_H

#include <QObject>
#include <QList>
#include <QGraphicsItem>
#include <QWidget>

#include "core/models/model.h"

// singleton

// end singleton
namespace haevn{
    namespace core{
        namespace exporting{
                class DataExport : public QObject{
                    Q_OBJECT

                // public static methods
                public:
                    /**
                     * @brief getInstance
                     * @param parent
                     * @return
                     */
                    static DataExport* getInstance(QObject* parent = nullptr);

                // static variables
                private:
                    ///
                    static DataExport* s_instance;

                // public methods
                public:

                    virtual ~DataExport();

                    /**
                     * @brief getWidth
                     * @param id
                     * @return
                     */
                    int getWidth(int id);
                    /**
                     * @brief getMinWidth
                     * @param id
                     * @return
                     */
                    int getMinWidth(int id);

                    /**
                     * @brief getMaxWidth
                     * @param id
                     * @return
                     */
                    int getMaxWidth(int id);

                    /**
                     * @brief getHeigth
                     * @param id
                     * @return
                     */
                    int getHeigth(int id);

                    /**
                     * @brief getMinHeight
                     * @param id
                     * @return
                     */
                    int getMinHeight(int id);

                    /**
                     * @brief getMaxHeight
                     * @param id
                     * @return
                     */
                    int getMaxHeight(int id);

                    /**
                     * @brief getPosX
                     * @param id
                     * @return
                     */
                    int getPosX(int id);

                    /**
                     * @brief getPosY
                     * @param id
                     * @return
                     */
                    int getPosY(int id);

                    /**
                     * @brief getTooltip
                     * @param id
                     * @return
                     */
                    QString getTooltip(int id);

                    /**
                     * @brief getName
                     * @param id
                     * @return
                     */
                    QString getName(int id);

                    /**
                     * @brief getContent
                     * @param id
                     * @return
                     */
                    QString getContent(int id);

                    /**
                     * @brief toString
                     * @return
                     */
                    QString toString();

                    /**
                     * @brief toString
                     * @param id
                     * @return
                     */
                    QString toString(int id);

                // private methods
                private:

                    /**
                     * @brief DataExport
                     * @param parent
                     */
                    explicit DataExport(QObject *parent = nullptr);

                    /**
                     * @brief DataExport
                     * @param another
                     */
                    explicit DataExport(DataExport& another){}

                // private variables
                private:

                    ///
                    QList<QWidget*>* m_scenegraph;

                    ///
                    haevn::core::models::Model* m_model;

                signals:

                };
        }
    }
}
#endif // DATAEXPORT_H
