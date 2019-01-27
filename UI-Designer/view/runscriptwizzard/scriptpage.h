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
                 * @brief ShowEvent, occurres if the page is visible
                 * @details This event occurred iff this page is activated.
                 * This method will handle the everything which should happened if this page is shown.
                 * @param event - This param contains all information about the show operation.
                 */
                void showEvent(QShowEvent* event);

                /**
                 * @brief This functionn validates the page
                 * @details [FROM qt wizard page class doc http://doc.qt.io/qt-5/qwizardpage.html#validatePage]
                 * This virtual function is called by QWizard::validateCurrentPage() when the user clicks Next or Finish
                 * to perform some last-minute validation. If it returns true,
                 * the next page is shown (or the wizard finishes); otherwise, the current page stays up.
                 * @return True iff a script is selected
                 */
                bool validatePage();

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
