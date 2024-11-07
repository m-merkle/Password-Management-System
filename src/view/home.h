#include <Wt/WComboBox.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

#ifndef HOME_H
#define HOME_H

using namespace Wt;

class credHome: public WContainerWidget {
	public:
		credHome() = delete;
		explicit credHome(petShop::userList& ul);

	protected:
		petShop::userList& ul;

		WLineEdit*	nameEdit;
		WComboBox*	typeEdit;
		WPushButton*	OkButton;
};


#endif /* HOME_H */
