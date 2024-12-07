/*
 * Password Manager - Witty Application
 *
 * View - Credential form
 * jathur, momerk 12/7/2024
 */

#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

#ifndef CREDENTIALFORM_H
#define CREDENTIALFORM_H

using namespace Wt;

class CredentialForm : public WContainerWidget
{
  public:
    // CredentialForm() = delete;
    CredentialForm();

  protected:
    WLineEdit* idEdit;
    WLineEdit* usernameEdit;
    WLineEdit* passwordEdit;
    WLineEdit* emailEdit;
    WLineEdit* credNameEdit;
    WLineEdit* descriptionEdit;
    WPushButton* addButton;
    WPushButton* cancelButton;
};

#endif /* CREDENTIALFORM_H */
