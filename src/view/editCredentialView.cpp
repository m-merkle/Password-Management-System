/*
 * Password manager - Witty Application
 *
 * Edit - Edit a credential
 * Tristen, 12/05/2024
 * momerk, 12/8/24
 */

#include "editCredentialView.h"
#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>
#include <sstream>
#include <string>

using namespace Wt;

editCredentialView::editCredentialView(Database& db) :
    CredentialForm(true, false), db(db)
{
    addButton->setText("Edit");
    addButton->clicked().connect(this, &editCredentialView::editCredential);
    deleteButton->clicked().connect(this,
                                    &editCredentialView::deleteCredential);
    // output instructions for the user
    addWidget(std::make_unique<WBreak>());
    addWidget(
        std::make_unique<WText>("To delete a credential: enter the credential "
                                "ID and click the delete button"));
    addWidget(std::make_unique<WBreak>());
    addWidget(std::make_unique<WBreak>());
    addWidget(std::make_unique<WText>(
        "To edit a credential: enter the credential ID and any updates for the "
        "credential then click the edit button"));
}

void
editCredentialView::editCredential()
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

    // if credential id is empty then fail (edit won't work) or if all text
    // boxes are empty
    if (idcheck == false || (username.length() == 0 && password.length() == 0 &&
                             email.length() == 0 && credname.length() == 0 &&
                             descrip.length() == 0))
        wApp->setInternalPath("/edit-failure", true);
    else {

        // get temporary values of current credential
        std::string criteria = "credentialID=" + stringid;
        std::string record = db.retrieveRecord("Credentials", criteria);

        // if no matching credential then fail
        if (record.empty() == true)
            wApp->setInternalPath("/edit-failure", true);
        else {
            std::stringstream credSS(record);
            std::string ogCredID, ogName, ogUsername, ogPass, ogEmail,
                ogDescrip, LastChange, ogUserID;

            std::getline(credSS, ogCredID, ',');
            std::getline(credSS, ogName, ',');
            std::getline(credSS, ogUsername, ',');
            std::getline(credSS, ogPass, ',');
            std::getline(credSS, ogEmail, ',');
            std::getline(credSS, ogDescrip, ',');
            std::getline(credSS, LastChange, ',');
            std::getline(credSS, ogUserID, '.');

            // make changes based on user input (which text boxes have updates)
            // if no update, then set variable to the og
            if (credname.length() == 0)
                credname = ogName;
            if (username.length() == 0)
                username = ogUsername;
            if (password.length() == 0)
                password = ogPass;
            if (email.length() == 0)
                email = ogEmail;
            if (descrip.length() == 0)
                descrip = ogDescrip;

            // now variables have the updates
            passMang::Credential credential(
                id, credname, email, username, password, descrip);
            credential.setLastUpdated();

            if (db.updateCredential(credential, ogUserID)) {
                wApp->setInternalPath("/edit-success", true);
            } else
                wApp->setInternalPath("/edit-failure", true);
        }
    }
}

void
editCredentialView::deleteCredential()
{
    // variable to check if the id text box if empty
    bool idcheck = false;
    int id;

    // get text from credential id text box of the credential form
    std::string stringid = WString(idEdit->text()).toUTF8();
    // if id text box is not empty, convert to int
    if (stringid.empty() == false) {
        id = std::stoi(stringid);
        idcheck = true;
    }

    // if credential id is empty then fail (delete won't work)
    if (idcheck == false)
        wApp->setInternalPath("/edit-failure", true);
    else {
        // get current credential
        std::string criteria = "credentialID=" + stringid;
        std::string record = db.retrieveRecord("Credentials", criteria);

        // if no matching credential then fail
        if (record.empty() == true)
            wApp->setInternalPath("/edit-failure", true);
        else {
            if (db.deleteCredential(id)) {
                wApp->setInternalPath("/edit-success", true);
            } else
                wApp->setInternalPath("/edit-failure", true);
        }
    }
}
