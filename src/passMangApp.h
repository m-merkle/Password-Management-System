/*
 * Password Manager - Witty Application
 *
 * Password Manager Application
 * mmerkle, 11/15/2024
*/

#include <string>

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>

#ifndef PASSMANGAPP_H
#define PASSMANGAPP_H

using namespace Wt;

class passMangApp: public WApplication {
	public:
		passMangApp()=delete;
		explicit passMangApp(const WEnvironment &env);

	private:
		void onInternalPathChange();
		void createHeaderContainer();
		void createNavigationContainer();
		void showHomeScreen();
		void createFooterContainer();

		std::string appName;
		WContainerWidget* content;
};

#endif /* PASSMANGAPP_H */
