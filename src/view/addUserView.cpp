/*
 * Password Manager - Witty Application
 *
 * View - Add a user to the list
 * jathur, 11/19/24
 */
#include <string>

#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "addUserView.h"

using namespace Wt;

addUserView::addUserView() // addUserView::addUserView(passMang::UserList& ul) :
                           // UserForm {ul}
{
    UserForm(); // this line should be deleted after UserList is added
    typeEdit->setNoSelectionEnabled(false);
    typeEdit->setCurrentIndex(0);

    // addButton->clicked().connect(this, &addUserView::addNewUser);
}

void
addUserView::addNewUser()
{
    // finish me
}
