/*
 * Password Manager - Witty Application
 *
 * View - Search Users
 * momerk, 12/7/2024
 * jathur, 12/8/2024
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
    searchUserView(Database& db);

  private:
    void searchUser();
    void displayUsers();
    Database& db;
    Wt::WGroupBox* resultBox;
    std::unique_ptr<Wt::WGroupBox> userBox;
};

#endif /* SEARCHUSERVIEW_H */
