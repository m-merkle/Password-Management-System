/*
 * Password Manager - Witty Application
 *
 * View - Edit a Credential
 * trmiss 12/07/24
 */


#include "UserForm.h"

#ifndef EDITUSERVIEW_H
#define EDITUSERVIEW_H

class editUserView : public UserForm
{
  public:
    editUserView();
  private:
    void editNewUser();
};

#endif /* EDITUSERVIEW_H */