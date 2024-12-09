/*
 * Password Manager - Witty Application
 *
 * View - Add a user to the list
 * jathur, momerk  12/8/24
 */
#include <string>

#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "addUserView.h"

using namespace Wt;

addUserView::addUserView(Database& db) : db(db)
{
    UserForm(false);
    typeEdit->setNoSelectionEnabled(false);
    typeEdit->setCurrentIndex(0);

    addButton->clicked().connect(this, &addUserView::addNewUser);
}

void
addUserView::addNewUser()
{
    // variable to check if the id text box is empty
    bool idcheck = false;
    int id;

    // get text from text boxes of the user form
    std::string stringid = WString(idEdit->text()).toUTF8();
    // if id text box is not empty, convert to int
    if (stringid.empty() == false) {
        id = std::stoi(stringid);
        idcheck = true;
    }
    std::string username = WString(usernameEdit->text()).toUTF8();
    std::string password = WString(passwordEdit->text()).toUTF8();

    // get current index and the type of user
    int currIndex = typeEdit->currentIndex();
    passMang::Role role;

    if (currIndex == 1)
        role = passMang::Role::Admin;
    else if (currIndex == 2)
        role = passMang::Role::Regular;
    else if (currIndex == 3)
        role = passMang::Role::ViewOnly;

    // if any of the text boxes are empty or the combo box is empty than fail
    if (idcheck == false || username.length() == 0 || password.length() == 0 ||
        currIndex == 0)
        wApp->setInternalPath("/add-failure", true);
    else {
        passMang::userType userType(role);
        passMang::User user(id, username, password, userType);
        user.updateLastLogin();
        if (db.insertUser(user))
            wApp->setInternalPath("/add-success", true);
        else
            wApp->setInternalPath("/add-failure", true);
    }
}
