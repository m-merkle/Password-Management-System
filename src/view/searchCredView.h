/*
 * Password Manager - Witty Application
 *
 * View - Search Credential
 * momerk, 11/25/2024
 */

// eventually include credential list to actually search
// #include CredentialList.h
#include "CredentialForm.h"

#ifndef SEARCHCREDVIEW_H
#define SEARCHCREDVIEW_H

class searchCredView : public CredentialForm
{
  public:
    // searchCredView() = delete;
    searchCredView();
    // explicit searchCredView(passMang::CredentialList& cl);

  private:
    void searchCred();
};

#endif /* SEARCHCREDVIEW_H */
