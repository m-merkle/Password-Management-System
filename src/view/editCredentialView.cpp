/*
 * Password manager - Witty Application
 *
 * Edit - Edit a credential
 * Tristen, 12/05/2024
 */
#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>
#include <string>

#include "editCredentialView.h"

using namespace Wt;

editCredentialView::
    editCredentialView() // addCredentialView::addCredentialView(passMang::CredentialList&

{
    CredentialForm();
    addButton->setText("Edit");
    addButton->clicked().connect(this, &editCredentialView::editNewCredential);
}

void
editCredentialView::editNewCredential()
{
    std::string id = WString(idEdit->text()).toUTF8();
    std::string username = WString(usernameEdit->text()).toUTF8();
    std::string password = WString(passwordEdit->text()).toUTF8();
    std::string email = WString(emailEdit->text()).toUTF8();
    std::string credname = WString(credNameEdit->text()).toUTF8();

    if (id.length() == 0 || username.length() == 0 || password.length() == 0 ||
        email.length() == 0 || credname.length() == 0)
        wApp->setInternalPath("/edit-failure", true);
    else
        // test: will be success as long as all text boxes have something
        wApp->setInternalPath("/edit-success", true);
}