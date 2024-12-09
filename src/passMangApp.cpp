/*
 * Password Manager - Witty Application
 *
 * Password Manager Application
 * mmerkle,jathur,cawhee 12/8/2024
 * References:
 * https://stackoverflow.com/questions/42463871/how-to-put-spaces-between-text-in-html
 * https://www.geeksforgeeks.org/c-program-remove-spaces-string
 * https://akh1l.hashnode.dev/stringstream-and-getline-in-cpp
 * https://www.geeksforgeeks.org/strftime-function-in-c
 */

#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WGroupBox.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#include "passMangApp.h"

// files from view
#include "addCredentialView.h"
#include "addUserView.h"
#include "editCredentialView.h"
#include "editUserView.h"
#include "searchCredView.h"
#include "searchUserView.h"
#include "statusView.h"

// files from model
#include "Database.h"
#include "User.h"
#include "userType.h"

using namespace Wt;

passMangApp::passMangApp(const WEnvironment& env) :
    WApplication(env), db("model/Passmang.db"), appName("Password Manager")
{
    setTitle(appName);

    root()->setAttributeValue(
		    "style", "background-color: #008000; margin: 0 auto;"
		    "width: 100%;");

    // add CSS theme eventually

    // install path handler
    internalPathChanged().connect(this, &passMangApp::onInternalPathChange);

    // create the base UI
    createHeaderContainer();

    // create navigation container/bar
    createNavigationContainer();

    auto contentContainer = std::make_unique<WContainerWidget>();
    contentContainer->setAttributeValue("style", "background-color: #165B33;");
    content = contentContainer.get();
    root()->addWidget(std::move(contentContainer));

    // call for login screen
    userLogin();

    // create footer container
    createFooterContainer();
}

void
passMangApp::userLogin()
{
    assert(content != nullptr);

    auto loginContainer = std::make_unique<WContainerWidget>();
    loginContainer->setAttributeValue(
        "style",
        "padding: 20px; background-color: #165B33; "
        "border-radius: 5px width: 300px; margin: auto;");

    // create label and username line
    auto usernameText =
        loginContainer->addWidget(std::make_unique<WText>("Username: "));
    usernameText->setAttributeValue("style",
                                    "font-weight: bold; margin: 0  auto;");

    auto usernameIn = loginContainer->addWidget(std::make_unique<WLineEdit>());
    usernameIn->setAttributeValue(
        "style",
        "width: 20%; padding: 5px; margin-bottom: 10px; margin: 0 auto;");

    loginContainer->addWidget(std::make_unique<WBreak>());

    // create label and password line
    auto passwordText =
        loginContainer->addWidget(std::make_unique<WText>("Password: "));
    passwordText->setAttributeValue("style",
                                    "font-weight: bold; margin: auto;");

    auto passwordIn = loginContainer->addWidget(std::make_unique<WLineEdit>());
    passwordIn->setAttributeValue(
        "style",
        "width: 20%; padding: 5px; margin-bottom: 10px; margin: auto;");

    loginContainer->addWidget(std::make_unique<WBreak>());

    // create login button
    auto loginButton =
        loginContainer->addWidget(std::make_unique<WPushButton>("Login"));
    loginButton->setAttributeValue("style", "background-color: #C0C0C0;");
    loginButton->mouseWentOver().connect([=] {
        loginButton->setAttributeValue("style", "background-color: #FFD700;");
    });
    loginButton->mouseWentOut().connect([=] {
        loginButton->setAttributeValue("style", "background-color: #C0C0C0;");
    });

    // add container to content
    content->addWidget(std::move(loginContainer));

    // validate login once clicked (convert wstring to std::string with .toUTF8
    // method)
    loginButton->clicked().connect([this, usernameIn, passwordIn] {
        if (checkLogin(usernameIn->text().toUTF8(),
                       passwordIn->text().toUTF8())) {
            // show home screen once validated
            showHomeScreen();
        } else {
            if (invalidCount == 0) {
                auto invalidLoginText =
                    std::make_unique<WText>("Invalid Login");
                invalidLoginText->setAttributeValue(
                    "style", "background-color: #A50000; font-weight: bold;");
                content->addWidget(std::move(invalidLoginText));
                invalidCount++;
            }
        }
    });
}

bool
passMangApp::checkLogin(const std::string& usernm, const std::string& pass)
{
    // attempt to retrieve record of user with given login
    std::string criteria =
        "Username='" + usernm + "' AND Password='" + pass + "'";
    std::string record = db.retrieveRecord("Users", criteria);
    // std::cout << "RECORD: " << record << std::endl;

    // if no record of user than fail (if empty), if not get user ID and role
    if (record.empty() == false) {

        std::stringstream recordSS(record);
        std::string ID, username, password, role;

        // parse the record to get user attributes
        std::getline(recordSS, ID, ',');
        std::getline(recordSS, username, ',');
        std::getline(recordSS, password, ',');
        std::getline(recordSS, role, ',');

        // get rid of whitespace of role (code taken from geeksforgeeks.org)
        for (int i = 0; i < role.length(); i++) {
            if (role[i] == ' ') {
                role.erase(role.begin() + i);
                i--;
            }
        }

        // set id of user (keep string so easier to use throughout application)
        userID = ID;

        // set role of user
        if (role == "admin" || role == "Admin")
            userRole = passMang::Role::Admin;
        else if (role == "regular" || role == "Regular")
            userRole = passMang::Role::Regular;
        else
            userRole = passMang::Role::ViewOnly;

        // update the last login time (code taken from model team and
        // geeksforgeeks.org)
        std::chrono::system_clock::time_point update =
            std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(update);

        struct tm* localtime = std::localtime(&currentTime);

        char time[50];
        std::strftime(time, sizeof(time), "%Y-%m-%d %I:%M:%S", localtime);

        // std::cout << "UPDATED TIME: " << time << std::endl;

        // define data and criteria for user update
        std::string timeCriteria = "UserID=" + ID;
        std::string data = "LastLogin='" + std::string(time) + "'";

        // update database with new login time for user
        db.UpdateRecord("Users", data, timeCriteria);

        return true;
    } else
        return false;
}

void
passMangApp::onInternalPathChange()
{
    assert(content != nullptr);

    content->clear();

    if (internalPath() == "/add-user")
        addUser();
    else if (internalPath() == "/add-credential")
        addCredential();
    else if (internalPath() == "/add-success")
        resultAddSuccess();
    else if (internalPath() == "/add-failure")
        resultAddFailure();
    else if (internalPath() == "/search-credential")
        searchCredential();
    else if (internalPath() == "/search-user")
        searchUser();
    else if (internalPath() == "/search-failure")
        resultSearchFailure();
    else if (internalPath() == "/edit-credential")
        editCredential();
    else if (internalPath() == "/edit-user")
        editUser();
    else if (internalPath() == "/edit-success")
        resultEditSuccess();
    else if (internalPath() == "/edit-failure")
        resultEditFailure();
    else
        showHomeScreen();
}

void
passMangApp::createHeaderContainer()
{
    auto header = std::make_unique<WContainerWidget>();
    header->setAttributeValue("style", "background-color: #FFD700;");
    header->addWidget(std::make_unique<WText>("<h1>" + appName + "</h1>"));
    root()->addWidget(std::move(header));
}

void
passMangApp::createNavigationContainer()
{
    // ensures only one navigation bar made
    if (navCreated == false) {

        // create navigation bar but clear contents (placeholder, fill later)
        navigation = root()->addWidget(std::make_unique<WContainerWidget>());
        navigation->setAttributeValue("style", "background-color: #C0C0C0;");
        navigation->clear();

        // hide the navigation bar to start (since login page shown first)
        navigation->hide();

        navCreated = true;
    }
}

void
passMangApp::updateNavigation()
{
    assert(navigation != nullptr);

    navigation->clear();

    // create navigation bar and add menu items based on user role
    // all will have the home screen and search credentials view
    std::string navText = "<a href='#/home'>Home</a>&nbsp;&nbsp;";
    navText +=
        "<a href='#/search-credential'>Search Credentials</a>&nbsp;&nbsp;";

    if (userRole == passMang::Role::Admin) {
        navText += "<a href='#/add-credential'>Add Credential</a>&nbsp;&nbsp;";
        navText += "<a href='#/add-user'>Add User</a>&nbsp;&nbsp;";
        navText += "<a href='#/search-user'>Search Users</a>&nbsp;&nbsp;";
        navText +=
            "<a href='#/edit-credential'>Edit Credential</a>&nbsp;&nbsp;";
        navText += "<a href='#/edit-user'>Edit User</a>&nbsp;&nbsp;";
    } else if (userRole == passMang::Role::Regular) {
        navText += "<a href='#/add-credential'>Add Credential</a>&nbsp;&nbsp;";
    }

    auto navLink = std::make_unique<WText>(navText);
    navLink->setInternalPathEncoding(true);
    navigation->addWidget(std::move(navLink));

    // show after updated navigation (only called after login)
    navigation->show();
}

void
passMangApp::showHomeScreen()
{
    assert(content != nullptr);
    // remove the login container
    content->clear();
    // update navigation so that navigation options match the user role
    updateNavigation();
    // will eventually be connected to credential list and display that here
    auto welcomeText =
        std::make_unique<WText>("Welcome to the password manager app");
    welcomeText->setInternalPathEncoding(true);
    content->addWidget(std::make_unique<WBreak>());
    content->addWidget(std::make_unique<WBreak>());
    content->addWidget(std::move(welcomeText));
    content->addWidget(std::make_unique<WBreak>());
    content->addWidget(std::make_unique<WBreak>());

    // create container for credentials
    auto credBox = std::make_unique<Wt::WGroupBox>("Your Credentials");

    // get all credentials for current user (based on user ID)
    std::string criteria = "userid=" + userID;
    std::string userCreds = db.retrieveRecord("Credentials", criteria);

    // parse records retrieved
    std::stringstream credentialSS(userCreds);
    std::string credID, name, username, password, email, descrip, lastChange,
        uID;

    while (std::getline(credentialSS, credID, ',')) {

        // if end of string then stop the loop (prevents copy of last cred
        // added)
        if (credentialSS.eof()) {
            break;
        }

        // parse the record to get cred attributes
        std::getline(credentialSS, name, ',');
        std::getline(credentialSS, username, ',');
        std::getline(credentialSS, password, ',');
        std::getline(credentialSS, email, ',');
        std::getline(credentialSS, descrip, ',');
        std::getline(credentialSS, lastChange, ',');

        // must handle the period seperating the userID and the next record
        std::getline(credentialSS, uID, '.');

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

    content->addWidget(std::move(credBox));
}

void
passMangApp::createFooterContainer()
{
    auto footer = std::make_unique<WContainerWidget>();
    footer->addWidget(std::make_unique<WBreak>());
    footer->addWidget(std::make_unique<WBreak>());
    footer->addWidget(
        std::make_unique<WText>("Developed by Better Team of CS455 UNA"));
    root()->addWidget(std::move(footer));
}

void
passMangApp::addUser()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<addUserView>(db));
}

void
passMangApp::addCredential()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<addCredentialView>(db, userID));
}

void
passMangApp::resultAddSuccess()
{
    assert(content != nullptr);
    content->addWidget(
        std::make_unique<statusView>(true, "Successfully Added!"));
}

void
passMangApp::resultAddFailure()
{
    assert(content != nullptr);
    content->addWidget(
        std::make_unique<statusView>(false, "Add failed. Try again"));
}

void
passMangApp::resultEditSuccess()
{
    assert(content != nullptr);
    content->addWidget(
        std::make_unique<statusView>(true, "Successfully Edited!"));
}

void
passMangApp::resultEditFailure()
{
    assert(content != nullptr);
    content->addWidget(
        std::make_unique<statusView>(false, "Edit failed. Try again"));
}

void
passMangApp::searchCredential()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<searchCredView>(db, userRole));
}
void
passMangApp::editCredential()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<editCredentialView>(db));
}
void
passMangApp::searchUser()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<searchUserView>(db));
}
void
passMangApp::editUser()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<editUserView>(db));
}
void
passMangApp::resultSearchFailure()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<statusView>(false, "No Matches"));
}
