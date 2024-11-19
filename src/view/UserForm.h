/*
 * Password Manager - Witty Application
 *
 * View - home form
 * mmerkle, jathur, 11/19/2024
 */

#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

// #include "UserList.h"

#ifndef USERFORM_H
#define USERFORM_H

using namespace Wt;

class UserForm : public WContainerWidget
{
  public:
    // UserForm() = delete;
    explicit UserForm(); // explicit UserForm(passMang::UserList& ul);

  protected:
    // passMang::UserList& ul;

    WLineEdit* idEdit;
    WLineEdit* usernameEdit;
    WLineEdit* passwordEdit;
    WComboBox* typeEdit;
    WPushButton* addButton;
    WPushButton* cancelButton;
};

#endif /* USERFORM_H */
