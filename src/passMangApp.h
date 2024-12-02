/*
 * Password Manager - Witty Application
 *
 * Password Manager Application
 * mmerkle, jathur,  11/15/2024
 */

#include <string>

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

#ifndef PASSMANGAPP_H
#define PASSMANGAPP_H

using namespace Wt;

class passMangApp : public WApplication
{
  public:
    passMangApp() = delete;
    explicit passMangApp(const WEnvironment& env);

  private:
    void onInternalPathChange();
    void userLogin();
    bool checkLogin(const std::string& usernm, const std::string& pass);
    void createHeaderContainer();
    void createNavigationContainer();
    void showHomeScreen();
    void createFooterContainer();
    void addUser();
    void addCredential();
    void resultAddSuccess();
    void resultAddFailure();
    void searchCredential();
    void searchUser();
    void resultSearchFailure();

    std::string appName;
    WContainerWidget* content;
    WContainerWidget* navigation;
    bool navCreated = false;
};

#endif /* PASSMANGAPP_H */
