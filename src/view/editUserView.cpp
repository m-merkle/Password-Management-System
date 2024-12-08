/*
* Password manager - Witty Application
*
* Edit - Edit a user
* Trmiss, 12/07/2024
*/
#include <string>
#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "editUserView.h"

using namespace Wt;

editUserView::editUserView()                                       
{
    UserForm(); 
    addButton->setText("Edit");
    addButton->clicked().connect(this, &editUserView::editNewUser);
}

void
editUserView::editNewUser()
{
  

}
