/*
 * Password Manager - Witty Application
 *
 * View - Search Credential
 * momerk, 11/25/2024
 */

#include <memory>
#include <string>

#include <Wt/WApplication.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>
#include <Wt/WText.h>

#include "searchCredView.h"

using namespace Wt;

// eventually replace with this to include cred list
// searchCredView::searchCredView(passMang::CredentialList& cl) : CredentialForm
// {cl}

searchCredView::searchCredView()
{
    CredentialForm(); // line deleted after cred list added
    addButton->setText("Search");
    addButton->clicked().connect(this, &searchCredView::searchCred);
}

void
searchCredView::searchCred()
{
    // just a test to see if the status is working
    //  ^^will be triggered when user clicks search button
    wApp->setInternalPath("/search-failure", true);
}
