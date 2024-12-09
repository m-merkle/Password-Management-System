/*
 * Password Manager - Witty Application
 *
 * View - user form
 * mmerkle, jathur, 12/8/2024
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
    explicit UserForm(bool addDelete = false);

  protected:
    WLineEdit* idEdit;
    WLineEdit* usernameEdit;
    WLineEdit* passwordEdit;
    WComboBox* typeEdit;
    WPushButton* addButton;
    WPushButton* cancelButton;
    WPushButton* deleteButton;
};

#endif /* USERFORM_H */
