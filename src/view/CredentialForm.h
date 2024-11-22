/*
 * Password Manager - Witty Application
 *
 * View - Credential form
 * jathur, 11/19/2024
 */

#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

// #include "CredentialList.h"

#ifndef CREDENTIALFORM_H
#define CREDENTIALFORM_H

using namespace Wt;

class CredentialForm : public WContainerWidget
{
  public:
    // CredentialForm() = delete;
    CredentialForm(); // explicit CredentialForm(passMang::CredentialList& cl);

  protected:
    // passMang::CredentialList& cl;

    WLineEdit* idEdit;
    WLineEdit* usernameEdit;
    WLineEdit* passwordEdit;
    WLineEdit* emailEdit;
    WLineEdit* credNameEdit;
    WPushButton* addButton;
    WPushButton* cancelButton;
};

#endif /* CREDENTIALFORM_H */
