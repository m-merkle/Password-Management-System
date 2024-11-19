/*
 * Password Manager - Witty Application
 *
 * View - home form
 * mmerkle, 11/15/2024
*/

#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

#ifndef HOME_H
#define HOME_H

using namespace Wt;

class credHome: public WContainerWidget{
	public:
		credHome() = delete;
		explicit credHome();

	protected:
		WLineEdit*	nameEdit;
		WComboBox*	typeEdit;
		WPushButton*	OkButton;
};


#endif /* HOME_H */
