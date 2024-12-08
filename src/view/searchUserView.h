/*
 * Password Manager - Witty Application
 *
 * View - Search Users
 * momerk, 12/7/2024
 */

#include "Database.h"
#include "UserForm.h"
#include "userType.h"

#ifndef SEARCHUSERVIEW_H
#define SEARCHUSERVIEW_H

class searchUserView : public UserForm
{
  public:
    // searchUserView() = delete;
    searchUserView(Database& db, passMang::Role userRole);

  private:
    void searchUser();
    Database& db;
    passMang::Role userRole;
};

#endif /* SEARCHUSERVIEW_H */
