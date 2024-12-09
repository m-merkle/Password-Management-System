/*
 * Password Manager - Witty Application
 *
 * View - Edit a Credential
 * trmiss 12/05/24
 * momerk 12/8/24
 */

#include "CredentialForm.h"
#include "Credential.h"
#include "Database.h"
#include "passMangApp.h"

#ifndef EDITCREDENTIALVIEW_H
#define EDITCREDENTIALVIEW_H

class editCredentialView : public CredentialForm
{
  public:
    // editCredentialView() = delete;
    editCredentialView(const std::string& userID, Database& db);

  private:
    void editCredential();
    void deleteCredential();
    std::string userID;
    Database& db;
};

#endif /* EDITCREDENTIALVIEW_H */
