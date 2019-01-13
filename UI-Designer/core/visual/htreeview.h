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
        namespace visual{

            /**
             * @brief The HTreeView class
             */
            class HTreeView : public QTreeWidget {
                Q_OBJECT

            // public methods
            public:

                /**
                 * @brief HTreeView
                 * @param parent
                 */
                explicit HTreeView(QWidget *parent = nullptr);

                /**
                 * @brief mousePressEvent
                 * @param event
                 */
                void mousePressEvent(QMouseEvent* event);

                void startDrag(Qt::DropActions supportedActions);
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
                 * @brief getTopLevelCount
                 * @return
                 */
                int getTopLevelCount();

            signals:

            public slots:

            };


        }
    }
}
#endif // HTREEVIEW_H
