/*
 * Password Manager - Witty Application
 *
 * View - Search Users
 * momerk, 12/7/2024
 * jathur, 12/8/2024
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

searchUserView::searchUserView(Database& db) :
    db(db), userBox(nullptr), resultBox(nullptr)
{
    // UserForm(false);

    addWidget(std::make_unique<WBreak>());
    resultBox = addWidget(std::make_unique<Wt::WGroupBox>("Results:"));

    addButton->setText("Search");
    addButton->clicked().connect(this, &searchUserView::searchUser);

    // if user role is admin, then show all users (all users able to navigate
    // here are admin)
    displayUsers();
}

void
searchUserView::displayUsers()
{
    addWidget(std::make_unique<WBreak>());
    addWidget(std::make_unique<WBreak>());

    // create box for users
    userBox = std::make_unique<Wt::WGroupBox>("All Users");
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
        userBox->addWidget(std::make_unique<Wt::WText>("User Type: " + type));
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

void
searchUserView::searchUser()
{
    bool isID, isUser, isPass, isType, isMatch;
    std::string stringid, username, password;
    std::string userRecord, criteria;
    int currIndex, id;
    passMang::Role role;

    // Check for inputs ------------------------------------------------
    stringid = WString(idEdit->text()).toUTF8();
    if (stringid.empty())
        isID = false;
    else {
        id = std::stoi(stringid);
        isID = true;
    }

    username = WString(usernameEdit->text()).toUTF8();
    if (username.empty())
        isUser = false;
    else
        isUser = true;

    password = WString(passwordEdit->text()).toUTF8();
    if (password.empty())
        isPass = false;
    else
        isPass = true;

    currIndex = typeEdit->currentIndex();
    // isType set to true by default, will be set to false if
    // no type is selected
    isType = true;

    if (currIndex == 0)
        role = passMang::Role::Admin;
    else if (currIndex == 1)
        role = passMang::Role::Regular;
    else if (currIndex == 2)
        role = passMang::Role::ViewOnly;
    else
        isType = false;
    //------------------------------------------------------------------
    // Search in order of valid inputs: id, username, password, type
    isMatch = false;

    if (isID) {
        // search for user by id
        criteria = "userid=" + stringid;
        userRecord = db.retrieveRecord("Users", criteria);

        if (userRecord.empty())
            isMatch = false;
        else
            isMatch = true;
    }

    if (isUser && (isMatch == false)) {
        // search for user by username
        criteria = "Username='" + username + "'";
        userRecord = db.retrieveRecord("Users", criteria);

        if (userRecord.empty())
            isMatch = false;
        else
            isMatch = true;
    }

    if (isPass && (isMatch == false)) {
        // search for user by password
        criteria = "Password='" + password + "'";
        userRecord = db.retrieveRecord("Users", criteria);

        if (userRecord.empty())
            isMatch = false;
        else
            isMatch = true;
    }

    if (isMatch == true) {
        resultBox->clear();
        resultBox->addWidget(std::make_unique<Wt::WText>(userRecord));
        // addWidget(std::move(resultBox));
    } else
        wApp->setInternalPath("/search-failure", true);
}
