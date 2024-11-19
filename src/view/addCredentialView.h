/*
 * Password Manager - Witty Application
 *
 * View - Add a Credential to the list
 * jathur, 11/19/24
 */

// #include "CredentialList.h"
#include "CredentialForm.h"

#ifndef ADDCREDENTIALVIEW_H
#define ADDCREDENTIALVIEW_H

class addCredentialView : public CredentialForm
{
  public:
    // addCredentialView() = delete;
    addCredentialView(); // explicit addCredentialView(passMang::CredentialList&
                         // cl);

  private:
    void addNewCredential();
};

#endif /* ADDCREDENTIALVIEW_H */
