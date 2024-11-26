/*
 * Password Manager - Witty Application
 *
 * View - Search Users
 * momerk, 11/25/2024
 */

// eventually include user list to actually search
// #include UserList.h
#include "UserForm.h"

#ifndef SEARCHUSERVIEW_H
#define SEARCHUSERVIEW_H

class searchUserView : public UserForm
{
  public:
    // searchUserView() = delete;
    searchUserView();
    // explicit searchUserView(passMang::UserList& ul);

  private:
    void searchUser();
};

#endif /* SEARCHUSERVIEW_H */
