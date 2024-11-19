/*
 * Password Manager - Witty Application
 *
 * View - Add a Credential to the list
 * jathur, 11/19/24
 */
#include <string>

#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "addCredentialView.h"

using namespace Wt;

addCredentialView::addCredentialView() // addCredentialView::addCredentialView(passMang::CredentialList&
                                       // cl) : CredentialForm {cl}
{
    CredentialForm(); // this line should be deleted after UserList is added

    // addButton->clicked().connect(this, &addUserView::addNewUser);
}

void
addCredentialView::addNewCredential()
{
    // finish me
}
