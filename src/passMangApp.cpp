/*
 * Password Manager - Witty Application
 *
 * Password Manager Application
 * mmerkle, 11/15/2024
*/

#include <memory>
#include <utility>

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>

//add files for views here eventually
#include "passMangApp.h"

using namespace Wt;

passMangApp::passMangApp(const WEnvironment& env) : WApplication(env), appName("Password Manager")
{
	setTitle(appName);

	//add CSS theme eventually
	
	//install path handler
	internalPathChanged().connect(this, &passMangApp::onInternalPathChange);

	//create the base UI
	createHeaderContainer();
	createNavigationContainer();

	auto contentContainer = std::make_unique<WContainerWidget>();
	//contentContainer->addStyleClass("");
	content = contentContainer.get();
	root()->addWidget(std::move(contentContainer));
	showHomeScreen();

	createFooterContainer();
}

void
passMangApp::onInternalPathChange()
{
	assert(content != nullptr);

	content->clear();

	//right now only shows home screen
	showHomeScreen();

	//need to add the differnt paths to different screens eventually
	//if(internalPath() == "/"
}

void
passMangApp::createHeaderContainer()
{
	auto header = std::make_unique<WContainerWidget>();
	header->addWidget(std::make_unique<WText>("<h1>" + appName + "</h1>"));
	root()->addWidget(std::move(header));
}

void
passMangApp::createNavigationContainer()
{
	//create container for navigation bar and add menu items
	//right now only home (add more with new screens)
	auto t = std::make_unique<WText>("<a href='#/home'>Home</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));
}

void
passMangApp::showHomeScreen()
{
	assert(content != nullptr);

	//will eventually be connected to credential list and display that here
	auto welcomeText = std::make_unique<WText>("Welcome to the password manager app");
	welcomeText->setInternalPathEncoding(true);
	content->addWidget(std::move(welcomeText));
}

void
passMangApp::createFooterContainer()
{
	auto footer = std::make_unique<WContainerWidget>();
	footer->addWidget(std::make_unique<WText>("Developed by Better Team of CS455 UNA"));
	root()->addWidget(std::move(footer));
}
