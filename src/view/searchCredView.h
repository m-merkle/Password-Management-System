/*
 * Password Manager - Witty Application
 *
 * View - Search Credential
 * momerk, 12/7/2024
 */

#include "userType.h"
#include "Database.h"
#include "CredentialForm.h"

#ifndef SEARCHCREDVIEW_H
#define SEARCHCREDVIEW_H

class searchCredView : public CredentialForm
{
  public:
    // searchCredView() = delete;
    searchCredView(Database& db, passMang::Role userRole);

  private:
    void searchCred();
    Database& db;
    passMang::Role userRole;
};

#endif /* SEARCHCREDVIEW_H */
