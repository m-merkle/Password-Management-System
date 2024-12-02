/*
 * Password Manager - Witty Application
 *
 * View - Search Users
 * momerk, 11/25/2024
 */

#include <memory>
#include <string>

#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "searchUserView.h"

using namespace Wt;

// eventually replace with this to include user list
// searchUserView::searchUserView(passMang::UserList& ul) : UserForm {ul}

searchUserView::searchUserView()
{
    UserForm(); // line deleted after user list added
    addButton->setText("Search");
    addButton->clicked().connect(this, &searchUserView::searchUser);
}

void
searchUserView::searchUser()
{
    // just a test to see if the status is working
    //  ^^will be triggered when user clicks search button
    wApp->setInternalPath("/searchFailure", true);
}
