/*
 * Password Manager - Witty Application
 *
 * View - Search Credential
 * momerk, 12/7/2024
 */

#include <memory>
#include <sstream>
#include <string>

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WGroupBox.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "searchCredView.h"

using namespace Wt;

searchCredView::searchCredView(Database& db, passMang::Role userRole) :
    db(db), userRole(userRole)
{
    CredentialForm();
    addButton->setText("Search");
    addButton->clicked().connect(this, &searchCredView::searchCred);

    // if user role is admin, then show all credentials for all users
    if (userRole == passMang::Role::Admin) {
        addWidget(std::make_unique<WBreak>());
        addWidget(std::make_unique<WBreak>());

        // create box for credentials
        auto credBox =
            std::make_unique<Wt::WGroupBox>("All Credentials for All Users");
        // get all credentials
        std::string allCredentials = db.retrieveRecord("Credentials", "1=1");

        // parse credentials recieved
        std::stringstream credSS(allCredentials);
        std::string credID, name, username, password, email, descrip,
            lastChange, uID;

        while (std::getline(credSS, credID, ',')) {
            if (credSS.eof()) {
                break;
            }

            // parse credential to get cred attributes
            std::getline(credSS, name, ',');
            std::getline(credSS, username, ',');
            std::getline(credSS, password, ',');
            std::getline(credSS, email, ',');
            std::getline(credSS, descrip, ',');
            std::getline(credSS, lastChange, ',');

            // handle the period seperating the userID and the next record
            std::getline(credSS, uID, '.');

            // add credential to credential box
            credBox->addWidget(
                std::make_unique<Wt::WText>("Credential ID: " + credID));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(std::make_unique<Wt::WText>("Name: " + name));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(
                std::make_unique<Wt::WText>("Username: " + username));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(
                std::make_unique<Wt::WText>("Password: " + password));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(std::make_unique<Wt::WText>("Email: " + email));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(
                std::make_unique<Wt::WText>("Description: " + descrip));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(
                std::make_unique<Wt::WText>("Last Changed: " + lastChange));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(std::make_unique<Wt::WText>("User ID: " + uID));
            credBox->addWidget(std::make_unique<WBreak>());
            credBox->addWidget(std::make_unique<Wt::WText>(
                "-------------------------------------"));
            credBox->addWidget(std::make_unique<WBreak>());
        }
        // add cred box to view
        addWidget(std::move(credBox));
    }
}

void
searchCredView::searchCred()
{
    // just a test to see if the status is working
    //  ^^will be triggered when user clicks search button
    wApp->setInternalPath("/search-failure", true);
}
