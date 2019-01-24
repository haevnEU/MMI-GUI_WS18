#ifndef SCRIPTPAGE_H
#define SCRIPTPAGE_H

#include <QWizardPage>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include "core/models/model.h"
#include "core/visual/hlistwidgetitem.h"

namespace haevn{
    namespace view{
        namespace wizzard{

            /**
             * @brief This class is a custom implementation of a
             * QWizardPage. It is used to implement a simple wizzard
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 24, 2019
             */
            class ScriptPage : public QWizardPage{
                Q_OBJECT
            public:

                /**
                 * @brief Constructor
                 * @details The constructor will create and initialize important data.
                 * @param t_appModel - this parameter contains the application model
                 * @param parent - default = nullptr, it could be a reference to the parent.
                 */
                ScriptPage(haevn::core::models::Model* t_appmodel,  QWidget* parent = nullptr);

                ~ScriptPage();

            private:

                /**
                 * @brief This label contains information about the page
                 */
                QLabel* m_lbInformation;

                /**
                 * @brief This label contains a sentence which states the script selection
                 */
                QLabel* m_lbScript;

                /**
                 * @brief This listwidget contains all scripts
                 */
                QListWidget* m_lwScripts;

                /**
                 * @brief This line edit contains the path to the script
                 */
                QLineEdit* m_leSelectedScript;

                /**
                 * @brief This variable contains all scripts
                 */
                QList<haevn::visual::HListWidgetItem>* m_items;

            public slots:

                /**
                 * @brief itemSelectionChanged, this slot is called if the listwidget index changed
                 * @details This slot is called if the user changed the entry inside the list widget.
                 * This method will handle basic operation which are required by the next page.
                 */
                void itemSelectionChanged();
            };
        }
    }
}
#endif // SCRIPTPAGE_H
