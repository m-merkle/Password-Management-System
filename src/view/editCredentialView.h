/*
 * Password Manager - Witty Application
 *
 * View - Edit a Credential
 * trmiss 12/05/24
 * momerk 12/8/24
 */

#include "Credential.h"
#include "CredentialForm.h"
#include "Database.h"
#include "passMangApp.h"

#ifndef EDITCREDENTIALVIEW_H
#define EDITCREDENTIALVIEW_H

class editCredentialView : public CredentialForm
{
  public:
    // editCredentialView() = delete;
    editCredentialView(Database& db);

  private:
    void editCredential();
    void deleteCredential();
    Database& db;
};

#endif /* EDITCREDENTIALVIEW_H */
