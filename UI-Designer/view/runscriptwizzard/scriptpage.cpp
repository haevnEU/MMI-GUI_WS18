#include "scriptpage.h"

haevn::view::wizzard::ScriptPage::ScriptPage(haevn::core::models::Model* t_appmodel, QWidget* parent) : QWizardPage(parent){
    setTitle("Select a script");
    m_lbInformation = new QLabel();
    m_lbInformation->setText("Select an available script below.");
    m_lbInformation->setWordWrap(true);

    m_lbScript = new QLabel();
    m_lbScript->setText("Selected script path");

    m_lwScripts = new QListWidget();

    m_leSelectedScript = new QLineEdit();
    m_leSelectedScript->setDisabled(true);


    for(QString key : t_appmodel->getScripts()->keys()){
        m_lwScripts->addItem(new haevn::visual::HListWidgetItem(key, t_appmodel->getScripts()->value(key)));
    }

    QVBoxLayout* layout = new QVBoxLayout();

    layout->addWidget(m_lbInformation);
    layout->addWidget(m_lwScripts);
    layout->addWidget(m_lbScript);
    layout->addWidget(m_leSelectedScript);
    setLayout(layout);
    connect(m_lwScripts, SIGNAL(itemSelectionChanged()), this, SLOT(itemSelectionChanged()));
    registerField("script", m_leSelectedScript);
}

haevn::view::wizzard::ScriptPage::~ScriptPage(){
    delete m_lbInformation;
    m_lbInformation = nullptr;

    delete m_lwScripts;
    m_lwScripts = nullptr;

    delete m_leSelectedScript;
    m_leSelectedScript = nullptr;

    delete m_lbScript;
    m_lbScript = nullptr;
}

void haevn::view::wizzard::ScriptPage::itemSelectionChanged(){
    // Set the line edit to the script path
    if(haevn::visual::HListWidgetItem* item = dynamic_cast<haevn::visual::HListWidgetItem*>(m_lwScripts->currentItem())){
        m_leSelectedScript->setText(item->getData());
    }
}


void haevn::view::wizzard::ScriptPage::showEvent(QShowEvent* event){
    // Reset selection
    m_lwScripts->setCurrentRow(-1);
    m_leSelectedScript->setText("");

}

bool haevn::view::wizzard::ScriptPage::validatePage(){
    // A script must be selected inside the listview, which implies that the lineedit is set too
    return m_leSelectedScript->text() != "" && m_lwScripts->currentRow() >= 0;
}
