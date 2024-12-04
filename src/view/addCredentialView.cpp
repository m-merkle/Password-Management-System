/*
 * Password Manager - Witty Application
 *
 * View - Add a Credential to the list
 * jathur,momerk  12/1/24
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
    CredentialForm(); // this line should be deleted after CredList is added
    addButton->clicked().connect(this, &addCredentialView::addNewCredential);
}

void
addCredentialView::addNewCredential()
{
    // get text from text boxes of the credential form
    std::string id = WString(idEdit->text()).toUTF8();
    std::string username = WString(usernameEdit->text()).toUTF8();
    std::string password = WString(passwordEdit->text()).toUTF8();
    std::string email = WString(emailEdit->text()).toUTF8();
    std::string credname = WString(credNameEdit->text()).toUTF8();

    // if any of the text boxes are empty than fail
    if(id.length()==0||username.length()==0||password.length()==0||email.length()==0||credname.length()==0)
	wApp->setInternalPath("/add-failure", true);
    else
        // test: will be success as long as all text boxes have something
	wApp->setInternalPath("/add-success", true);

    // eventually use this to actually add new credential
/*    else{
	if(cl.addCred(id, username, password, email, credname))
		wApp->setInternalPath("/add-success", true);
	else
		wApp->setInternalPath("/add-failure", true);
    }
*/
}
