/*
 * Password Manager - Witty Application
 *
 * Password Manager Application
 * mmerkle,jathur, 12/3/2024
 * Reference:
 * https://stackoverflow.com/questions/42463871/how-to-put-spaces-between-text-in-html
 */

#include <memory>
#include <utility>

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

// add files for views here eventually
#include "addCredentialView.h"
#include "addUserView.h"
#include "passMangApp.h"
#include "searchCredView.h"
#include "searchUserView.h"
#include "statusView.h"

using namespace Wt;

passMangApp::passMangApp(const WEnvironment& env) :
    WApplication(env), appName("Password Manager")
{
    setTitle(appName);

    // add CSS theme eventually

    // install path handler
    internalPathChanged().connect(this, &passMangApp::onInternalPathChange);

    // create the base UI
    createHeaderContainer();
    // create navigation container/bar
    createNavigationContainer();

    auto contentContainer = std::make_unique<WContainerWidget>();
    // contentContainer->addStyleClass("");
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

    // create label and username line
    loginContainer->addWidget(std::make_unique<WText>("Username: "));
    auto usernameIn = loginContainer->addWidget(std::make_unique<WLineEdit>());

    loginContainer->addWidget(std::make_unique<WBreak>());

    // create label and password line
    loginContainer->addWidget(std::make_unique<WText>("Password: "));
    auto passwordIn = loginContainer->addWidget(std::make_unique<WLineEdit>());

    loginContainer->addWidget(std::make_unique<WBreak>());

    // create login button
    auto loginButton =
        loginContainer->addWidget(std::make_unique<WPushButton>("Login"));

    // add container to content
    content->addWidget(std::move(loginContainer));

    // create temp variable to track the number of error messages created
    int tempCount = 0;

    // validate login once clicked (convert wstring to std::string with .toUTF8
    // method)
    loginButton->clicked().connect([this, usernameIn, passwordIn, &tempCount] {
        if (checkLogin(usernameIn->text().toUTF8(),
                       passwordIn->text().toUTF8())) {
            // show home screen once validated
            showHomeScreen();
        } else {
            if (tempCount == 0) {
                content->addWidget(std::make_unique<WText>("Invalid Login"));
                tempCount = tempCount + 1;
            }
        }
    });
}

bool
passMangApp::checkLogin(const std::string& usernm, const std::string& pass)
{
    // need to incorporate link to actual database of passwords/usernames so
    // just test here, sets the role of the user based on login
    if (usernm == "admin" && pass == "password"){
        userRole = passMang::Role::Admin;
	return true;
    }
    else if (usernm == "viewonly" && pass == "password"){
        userRole = passMang::Role::ViewOnly;
	return true;
    }
    else if (usernm == "regular" && pass == "password"){
        userRole = passMang::Role::Regular;
	return true;
    }
    else{
        return false;
    }
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
    else
        showHomeScreen();

    // if(internalPath() == "/"
}

void
passMangApp::createHeaderContainer()
{
    auto header = std::make_unique<WContainerWidget>();
    header->addWidget(std::make_unique<WText>("<h1>" + appName + "</h1>"));
    root()->addWidget(std::move(header));
}

void
passMangApp::createNavigationContainer()
{
    // ensures only one navigation bar made
    if (navCreated == false) {
        navigation = root()->addWidget(std::make_unique<WContainerWidget>());
        // create navigation bar and add menu items
        auto t = std::make_unique<WText>(
            "<a href='#/home'>Home</a>&nbsp;&nbsp;"
            "<a href='#/add-user'>Add User</a>&nbsp;&nbsp;"
            "<a href='#/add-credential'>Add Credential</a>&nbsp;&nbsp;"
            "<a href='#/search-credential'>Search Credentials</a>&nbsp;&nbsp;"
            "<a href='#/search-user'>Search Users</a>");
        t->setInternalPathEncoding(true);
        navigation->addWidget(std::move(t));
        // hide the navigation bar to start (since login page shown first)
        navigation->hide();
        navCreated = true;
    }
}

void
passMangApp::showHomeScreen()
{
    assert(content != nullptr);
    // remove the login container
    content->clear();
    // show navigation starting here so that not there for login page
    navigation->show();

    // will eventually be connected to credential list and display that here
    auto welcomeText =
        std::make_unique<WText>("Welcome to the password manager app");
    welcomeText->setInternalPathEncoding(true);
    content->addWidget(std::make_unique<WBreak>());
    content->addWidget(std::make_unique<WBreak>());
    content->addWidget(std::move(welcomeText));
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
    content->addWidget(std::make_unique<addUserView>());
}

void
passMangApp::addCredential()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<addCredentialView>());
}

void
passMangApp::resultAddSuccess()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<statusView>(true, "Successfully added!"));
}

void
passMangApp::resultAddFailure()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<statusView>(false, "Add failed. Try again"));
}

void
passMangApp::searchCredential()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<searchCredView>());
}

void
passMangApp::searchUser()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<searchUserView>());
}

void
passMangApp::resultSearchFailure()
{
    assert(content != nullptr);
    content->addWidget(std::make_unique<statusView>(false, "No Matches :("));
}
