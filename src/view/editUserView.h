/*
 * Password Manager - Witty Application
 *
 * View - Edit a Credential
 * trmiss 12/07/24
 * momerk 12/8/24
 */

#include "UserForm.h"
#include "User.h"
#include "Database.h"
#include "passMangApp.h"

#ifndef EDITUSERVIEW_H
#define EDITUSERVIEW_H

class editUserView : public UserForm
{
  public:
    editUserView(Database& db);
  private:
    void editUser();
    void deleteUser();
    Database& db;
};

#endif /* EDITUSERVIEW_H */
