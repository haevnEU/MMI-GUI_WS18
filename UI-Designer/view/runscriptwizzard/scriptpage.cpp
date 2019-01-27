#include "scriptpage.h"

haevn::view::wizzard::ScriptPage::ScriptPage(haevn::core::models::Model* t_appmodel, QWidget* parent) : QWizardPage(parent){
    m_lbScript = new QLabel();
    m_lbInformation = new QLabel();
    m_lwScripts = new QListWidget();
    m_leSelectedScript = new QLineEdit();
    QVBoxLayout* layout = new QVBoxLayout();

    setTitle("Select a script");

    m_lbInformation->setWordWrap(true);
    m_lbInformation->setText("Select an available script below.");
    m_lbScript->setText("Selected script path");

    m_leSelectedScript->setDisabled(true);

    // Add scripts to a listview,
    // each script is represented by a key value pair
    // where the name is used as a key
    // and the path as a value
    for(QString key : t_appmodel->getScripts()->keys()){
        m_lwScripts->addItem(new haevn::visual::HListWidgetItem(key, t_appmodel->getScripts()->value(key)));
    }
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

    delete m_lbScript;
    m_lbScript = nullptr;

    delete m_lwScripts;
    m_lwScripts = nullptr;

    delete m_leSelectedScript;
    m_leSelectedScript = nullptr;

    delete m_items;
    m_items = nullptr;
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
