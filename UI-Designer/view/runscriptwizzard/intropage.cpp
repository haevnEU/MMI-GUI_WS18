#include "intropage.h"

haevn::view::wizzard::IntroPage::IntroPage(QWidget* parent) : QWizardPage(parent){
    setTitle("Information about this wizard");
    m_lbInformation = new QLabel();
    m_lbInformation->setText("This wizard guides you through the build process of your designed interface."
                             "\nIf your script can not be found, "
                             "please review the scripts.toc file to see if it really exists, "
                             "if it does not exist put the path to your script inside the scripts.toc.");
    m_lbInformation->setWordWrap(true);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(m_lbInformation);
    setLayout(layout);
}

haevn::view::wizzard::IntroPage::~IntroPage(){
    delete m_lbInformation;
    m_lbInformation = nullptr;
}
