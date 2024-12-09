/*
 * Password Manager - Witty Application
 *
 * View - Add a user to the list
 * jathur, momerk  12/7/24
 */

#include "Database.h"
#include "User.h"
#include "UserForm.h"
#include "passMangApp.h"

#ifndef ADDUSERVIEW_H
#define ADDUSERVIEW_H

class addUserView : public UserForm
{
  public:
    // addUserView() = delete;
    addUserView(Database& db);

  private:
    void addNewUser();
    Database& db;
};

#endif /* ADDUSERVIEW_H */
