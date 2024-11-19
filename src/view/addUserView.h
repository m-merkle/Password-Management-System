/*
 * Password Manager - Witty Application
 *
 * View - Add a user to the list
 * jathur, 11/19/24
 */

// #include "UserList.h"
#include "UserForm.h"

#ifndef ADDUSERVIEW_H
#define ADDUSERVIEW_H

class addUserView : public UserForm
{
  public:
    // addUserView() = delete;
    addUserView(); // explicit addUserView(passMang::UserList& ul);

  private:
    void addNewUser();
};

#endif /* ADDUSERVIEW_H */
