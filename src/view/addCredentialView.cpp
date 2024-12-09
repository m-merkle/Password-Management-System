/*
 * Password Manager - Witty Application
 *
 * View - Add a Credential to the list
 * jathur, momerk  12/7/24
 */
#include <string>

#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "addCredentialView.h"

using namespace Wt;

addCredentialView::addCredentialView(Database& db, const std::string& userID) :
    db(db), userID(userID)
{
    CredentialForm(false,false);
    addButton->clicked().connect(this, &addCredentialView::addNewCredential);
}

void
addCredentialView::addNewCredential()
{
    // variable to check if the id text box if empty
    bool idcheck = false;
    int id;

    // get text from text boxes of the credential form
    std::string stringid = WString(idEdit->text()).toUTF8();
    // if id text box is not empty, convert to int
    if (stringid.empty() == false) {
        id = std::stoi(stringid);
        idcheck = true;
    }
    std::string username = WString(usernameEdit->text()).toUTF8();
    std::string password = WString(passwordEdit->text()).toUTF8();
    std::string email = WString(emailEdit->text()).toUTF8();
    std::string credname = WString(credNameEdit->text()).toUTF8();
    std::string descrip = WString(descriptionEdit->text()).toUTF8();

    // if any of the text boxes are empty than fail
    if (idcheck == false || username.length() == 0 || password.length() == 0 ||
        email.length() == 0 || credname.length() == 0 || descrip.length() == 0)
        wApp->setInternalPath("/add-failure", true);
    else {
        passMang::Credential credential(
            id, credname, email, username, password, descrip);
        credential.setLastUpdated();

        if (db.insertCredential(credential, userID)) {
            wApp->setInternalPath("/add-success", true);
        } else
            wApp->setInternalPath("/add-failure", true);
    }
}
