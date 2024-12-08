/*
 * Password Manager - Witty Application
 *
 * View - Add a Credential to the list
 * jathur, momerk 12/7/24
 */

#include "Credential.h"
#include "CredentialForm.h"
#include "Database.h"
#include "passMangApp.h"

#ifndef ADDCREDENTIALVIEW_H
#define ADDCREDENTIALVIEW_H

class addCredentialView : public CredentialForm
{
  public:
    // addCredentialView() = delete;
    addCredentialView(const std::string& userID, Database& db);

  private:
    void addNewCredential();
    std::string userID;
    Database& db;
};

#endif /* ADDCREDENTIALVIEW_H */
