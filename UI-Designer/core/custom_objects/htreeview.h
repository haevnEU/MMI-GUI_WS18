#ifndef HTREEVIEW_H
#define HTREEVIEW_H

#include <QWidget>
#include <QTreeView>
#include <list>

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>

#include "core/enumerations.h"

namespace haevn {
    namespace core {
        namespace custom_objects{

            /**
             * @brief The HTreeView class
             */
            class HTreeView : public QTreeWidget {
                Q_OBJECT


            public:

                /**
                 * @brief HTreeView
                 * @param parent
                 */
                explicit HTreeView(QWidget *parent = nullptr);

                /**
                 * @brief addRootHeader
                 * @param name
                 */
                void addRootHeader(QString name);

                /**
                 * @brief insertData
                 * @param level
                 * @param t_type
                 */
                void insertData(int level, e_haevn_objects t_type);

                /**
                 * @brief mousePressEvent
                 * @param event
                 */
                void mousePressEvent(QMouseEvent* event);

                /**
                 * @brief getTopLevelCount
                 * @return
                 */
                int getTopLevelCount();
            private:


            signals:

            public slots:

            };


        }
    }
}
#endif // HTREEVIEW_H
