/*
 * Password Manager - Witty Application
 *
 * View - user form
 * mmerkle, jathur, 11/19/2024
 */

#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

#ifndef USERFORM_H
#define USERFORM_H

using namespace Wt;

class UserForm : public WContainerWidget
{
  public:
    // UserForm() = delete;
    explicit UserForm();

  protected:
    WLineEdit* idEdit;
    WLineEdit* usernameEdit;
    WLineEdit* passwordEdit;
    WComboBox* typeEdit;
    WPushButton* addButton;
    WPushButton* cancelButton;
};

#endif /* USERFORM_H */
