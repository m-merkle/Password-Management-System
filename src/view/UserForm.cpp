/*
 * Password Manager - Witty Application
 *
 * View - User form
 * mmerkle,jathur, 11/19/2024
 */

#include <memory>

#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#include "UserForm.h"

using namespace Wt;

UserForm::UserForm(bool addDelete)
{
    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("ID: "));
    idEdit = addWidget(std::make_unique<WLineEdit>());
    idEdit->setFocus();

    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("Username: "));
    usernameEdit = addWidget(std::make_unique<WLineEdit>());

    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("Password: "));
    passwordEdit = addWidget(std::make_unique<WLineEdit>());

    addWidget(std::make_unique<WBreak>());

    addWidget(std::make_unique<WText>("User type: "));
    typeEdit = addWidget(std::make_unique<WComboBox>());

    typeEdit->addItem("");
    typeEdit->addItem("Admin");
    typeEdit->addItem("Regular");
    typeEdit->addItem("View-Only");

    addWidget(std::make_unique<WBreak>());

    auto cancelButton = addWidget(std::make_unique<WPushButton>("Cancel"));
    cancelButton->setMargin(5, Side::Left | Side::Top);
    cancelButton->setLink(WLink(LinkType::InternalPath, "/home"));

    addButton = addWidget(std::make_unique<WPushButton>("Add"));
    addButton->setMargin(5, Side::Left | Side::Top);
    // connect "add" button in derived class

    if(addDelete == true){
	deleteButton = addWidget(std::make_unique<WPushButton>("Delete"));
	deleteButton->setMargin(5, Side::Left | Side::Top);
	// connect "delete" button in derived class
    }

    addWidget(std::make_unique<WBreak>());
}
