/*
 * Password Manager - Witty Application
 *
 * View - Search Users
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

#include "searchUserView.h"

using namespace Wt;

searchUserView::searchUserView(Database& db, passMang::Role userRole) :
    db(db), userRole(userRole)
{
    UserForm();
    addButton->setText("Search");
    addButton->clicked().connect(this, &searchUserView::searchUser);

    // if user role is admin, then show all users
    if (userRole == passMang::Role::Admin) {
        addWidget(std::make_unique<WBreak>());
        addWidget(std::make_unique<WBreak>());

        // create box for users
        auto userBox = std::make_unique<Wt::WGroupBox>("All Users");
        // get all users
        std::string allUsers = db.retrieveRecord("Users", "1=1");

        // parse users recieved
        std::stringstream userSS(allUsers);
        std::string uID, username, password, type, lastLogin;

        while (std::getline(userSS, uID, ',')) {
            if (userSS.eof()) {
                break;
            }

            // parse users to get user attributes
            std::getline(userSS, username, ',');
            std::getline(userSS, password, ',');
            std::getline(userSS, type, ',');

            // handle the period seperating the last login time/date and the
            // next record
            std::getline(userSS, lastLogin, '.');

            // add user to user box
            userBox->addWidget(std::make_unique<Wt::WText>("User ID: " + uID));
            userBox->addWidget(std::make_unique<WBreak>());
            userBox->addWidget(
                std::make_unique<Wt::WText>("Username: " + username));
            userBox->addWidget(std::make_unique<WBreak>());
            userBox->addWidget(
                std::make_unique<Wt::WText>("Password: " + password));
            userBox->addWidget(std::make_unique<WBreak>());
            userBox->addWidget(
                std::make_unique<Wt::WText>("User Type: " + type));
            userBox->addWidget(std::make_unique<WBreak>());
            userBox->addWidget(
                std::make_unique<Wt::WText>("Last Login: " + lastLogin));
            userBox->addWidget(std::make_unique<WBreak>());
            userBox->addWidget(std::make_unique<Wt::WText>(
                "-------------------------------------"));
            userBox->addWidget(std::make_unique<WBreak>());
        }
        // add user box to view
        addWidget(std::move(userBox));
    }
}

void
searchUserView::searchUser()
{
    // just a test to see if the status is working
    //  ^^will be triggered when user clicks search button
    wApp->setInternalPath("/search-failure", true);
}
