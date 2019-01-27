#ifndef INTROPAGE_H
#define INTROPAGE_H

#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>

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
            class IntroPage : public QWizardPage{
                Q_OBJECT

            private:
                /**
                 * @brief This is a ui element which represent basic information at startup
                 */
                QLabel* m_lbInformation;

            public:
                /**
                 * @brief Constructor
                 * @details The constructor will create and initialize important data.
                 * @param parent - default = nullptr, it could be a reference to the parent.
                 */
                explicit IntroPage(QWidget* parent = nullptr);

                ~IntroPage();
            };
        }
    }
}

#endif // INTROPAGE_H
