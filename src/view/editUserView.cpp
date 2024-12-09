/*
* Password manager - Witty Application
*
* Edit - Edit a user
* Trmiss, 12/07/2024
* momerk, 12/8/24
*/
#include <string>
#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "editUserView.h"

using namespace Wt;

editUserView::editUserView(Database& db) : UserForm(true), db(db)                                       
{
    addButton->setText("Edit");
    addButton->clicked().connect(this, &editUserView::editUser);
    deleteButton->clicked().connect(this, &editUserView::deleteUser); 
	
    // set the combo box to placeholder
    typeEdit->setCurrentIndex(0);

    // output instructions for the user
    addWidget(std::make_unique<WBreak>());
    addWidget(std::make_unique<WText>("To delete a user: enter the user ID and click the delete button"));
    addWidget(std::make_unique<WBreak>());
    addWidget(std::make_unique<WBreak>());
    addWidget(std::make_unique<WText>("To edit a user: enter the user ID and any updates for the user then click the edit button"));
}

void
editUserView::editUser()
{
    // variable to check if the id text box if empty
    bool idcheck = false;
    int id;

    // get text from text boxes of the user form
    std::string stringid = WString(idEdit->text()).toUTF8();
    // if id text box is not empty, convert to int
    if (stringid.empty() == false) {
        id = std::stoi(stringid);
        idcheck = true;
    }
    std::string username = WString(usernameEdit->text()).toUTF8();
    std::string password = WString(passwordEdit->text()).toUTF8();

    // get current index and the type of user
    int currIndex = typeEdit->currentIndex();
    
    //std::cout << "CURRENT INDEX: " << currIndex << std::endl;

    passMang::Role role;    

    if(currIndex == 1)
	role = passMang::Role::Admin;
    else if(currIndex == 2)
	role = passMang::Role::Regular;
    else if(currIndex == 3)
	role = passMang::Role::ViewOnly;

    // if user id is empty then fail (edit won't work) or if all text boxes are empty and combo box has no selection
    if (idcheck == false || 
	(username.length() == 0 && password.length() == 0 && currIndex == 0)) 
        wApp->setInternalPath("/edit-failure", true);
    else {
	
	// get temporary values of current user
	std::string criteria = "userID="+stringid;
	std::string record = db.retrieveRecord("Users", criteria);
	
	// if no matching user then fail
	if(record.empty() == true)
		wApp->setInternalPath("/edit-failure", true);
	else{
		std::stringstream userSS(record);
		std::string ogUserID, ogUsername, ogPass, ogRole, LastLogin;

		std::getline(userSS, ogUserID, ',');
		std::getline(userSS, ogUsername, ',');
		std::getline(userSS, ogPass, ',');
		std::getline(userSS, ogRole, ',');
		std::getline(userSS, LastLogin, '.');	

		// make changes based on user input (which text boxes have updates)
		// if no update, then set variable to the og
		if (username.length() == 0)
			username = ogUsername;
		if (password.length() == 0)
			password = ogPass;
		if (currIndex == 0){
			if(ogRole == "Admin")	
				role = passMang::Role::Admin;
			else if(ogRole == "Regular")
				role = passMang::Role::Regular;
			else
				role = passMang::Role::ViewOnly;
		}		

		// now variables have the updates
		passMang::userType userType(role);
		passMang::User user(id, username, password, userType);
		user.updateLastLogin();

		if(db.updateUser(user)){
			wApp->setInternalPath("/edit-success", true);
		} 		
		else
			wApp->setInternalPath("/edit-failure", true);
	}

    }
}

void
editUserView::deleteUser()
{
    // variable to check if the id text box if empty
    bool idcheck = false;
    int id;

    // get text from id text box of the user form
    std::string stringid = WString(idEdit->text()).toUTF8();
    // if id text box is not empty, convert to int
    if (stringid.empty() == false) {
        id = std::stoi(stringid);
        idcheck = true;
    }
	
    // if id is empty then fail (delete won't work)
    if(idcheck == false)
	wApp->setInternalPath("/edit-failure", true);
    else {
	// get current user to be deleted
	std::string criteria = "userID="+stringid;
	std::string record = db.retrieveRecord("Users", criteria);

	// if no matching user then fail
	if(record.empty() == true)
		wApp->setInternalPath("/edit-failure", true);
	else{
		if(db.deleteUser(id))
			wApp->setInternalPath("/edit-success", true);
		else
			wApp->setInternalPath("/edit-failure", true);
	}
    }
}
