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

#include "core/enums/enumerations.h"

namespace haevn {
    namespace core {
        namespace visual{

            /**
             * @brief This class is a custom implementation of a
             * QTreeWidget. It is used to enable drag and drop operation.
             * It also mades the insertion of new elements a lot easier.
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 15, 2019
             */
            class HTreeView : public QTreeWidget {
                Q_OBJECT

            // public methods
            public:

                /**
                 * @brief Constructor
                 * @details The constructor will create and initialize important data.
                 * @param parent - default = nullptr, it could be a reference to the parent.
                 */
                explicit HTreeView(QWidget *parent = nullptr);

                /**
                 * @brief startDrag slot
                 * @details This slot is called iff a drag operation started.
                 * This function will handle everythin which is done by dragging.
                 * Example: Dragging an object into the scenegraph.
                 * @param supportedActions - This param contains the supported actions.
                 */
                void startDrag(Qt::DropActions supportedActions);

                /**
                 * @brief Adds a new section to the widget.
                 * @details This method adds a new section into the widget.
                 * It wrapps the insertion of an element into the QTreeWidget and made
                 * it available by one call.
                 * @param name - This param is the content of new section.
                 */
                void addRootHeader(QString name);

                /**
                 * @brief Inserts data into the widget.
                 * @details This add a new object into the widget.
                 * Doing so it requires an enum which represent the type of widget.
                 * It wraps the insertion procedure into one call.
                 * @param level - Id of the section where the widget should be isnerted
                 * @param t_type - Type of the widget which should be inserted.
                 */
                void insertData(int level, haevn::core::enums::e_widget t_type);


                /**
                 * @brief Returns the amount of section.
                 * @details This method will return the ammount of existing section.
                 * It returns 0 if there is no section.
                 * @return Ammount of sections
                 */
                int getTopLevelCount();

            signals:

            public slots:

            };


        }
    }
}
#endif // HTREEVIEW_H
