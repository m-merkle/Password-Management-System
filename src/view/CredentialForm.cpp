/*
 * Password Manager - Witty Application
 *
 * View - Credential form
 * jathur, momerk  12/8/2024
 */

#include <memory>

#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#include "CredentialForm.h"

using namespace Wt;

CredentialForm::CredentialForm(bool addDelete, bool userIDtext)
{
    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("Credential ID: "));
    idEdit = addWidget(std::make_unique<WLineEdit>());
    idEdit->setFocus();

    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("Username: "));
    usernameEdit = addWidget(std::make_unique<WLineEdit>());

    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("Password: "));
    passwordEdit = addWidget(std::make_unique<WLineEdit>());

    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("Email: "));
    emailEdit = addWidget(std::make_unique<WLineEdit>());

    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("Credential Name: "));
    credNameEdit = addWidget(std::make_unique<WLineEdit>());

    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("Description: "));
    descriptionEdit = addWidget(std::make_unique<WLineEdit>());

    addWidget(std::make_unique<WBreak>());

    // only add this if user ID is needed (search credential)
    if(userIDtext == true){
  	addWidget(std::make_unique<WText>("User ID: "));
   	userIDEdit = addWidget(std::make_unique<WLineEdit>());	
   	addWidget(std::make_unique<WBreak>());
    }	

    auto cancelButton = addWidget(std::make_unique<WPushButton>("Cancel"));
    cancelButton->setMargin(5, Side::Left | Side::Top);
    cancelButton->setLink(WLink(LinkType::InternalPath, "/home"));

    addButton = addWidget(std::make_unique<WPushButton>("Add"));
    addButton->setMargin(5, Side::Left | Side::Top);
    // connect "add" button in derived class

    // only add this if delete button is needed (edit credential)
    if(addDelete == true){
	deleteButton = addWidget(std::make_unique<WPushButton>("Delete"));
	deleteButton->setMargin(5, Side::Left | Side::Top);
	// connect "delete" button in derived class
    }
	
    addWidget(std::make_unique<WBreak>());
}
