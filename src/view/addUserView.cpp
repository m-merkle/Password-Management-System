/*
 * Password Manager - Witty Application
 *
 * View - Add a user to the list
 * jathur, momerk  12/1/24
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

    addButton->clicked().connect(this, &addUserView::addNewUser);
}

void
addUserView::addNewUser()
{
    // get text from text boxes of the credential form
    std::string id = WString(idEdit->text()).toUTF8();
    std::string username = WString(usernameEdit->text()).toUTF8();
    std::string password = WString(passwordEdit->text()).toUTF8();
    
    // get current index and the type of user
    int currIndex = typeEdit->currentIndex();
    std::string type = "";

    if(currIndex == 0)
	type = "Admin";
    else if(currIndex == 1)
	type = "Regular";
    else if(currIndex == 2)
	type = "View-Only";

    if(id.length()==0||username.length()==0||password.length()==0)
	wApp->setInternalPath("/add-failure", true);
    else
	// test: will be success as long as all text boxes have text
    	wApp->setInternalPath("/add-success", true);

    // eventually use this to actually add new user
/*    else{
	if(ul.addUser(id, username, password, type))
		wApp->setInternalPath("/add-success", true);
	else
		wApp->setInternalPath("/add-failure", true);
    }
*/
}
