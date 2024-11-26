/*
 * Password Manager - Witty Application
 *
 * View - status of request
 * momerk, 11/25/2024
 */

#include <Wt/WBreak.h>
#include <Wt/WText.h>

#include "statusView.h"

using namespace Wt;

statusView::statusView(bool status, std::string msg) : status{status}, msg{msg}
{
    addWidget(std::make_unique<WBreak>());
    addWidget(std::make_unique<WText>(msg));
}

bool
statusView::getStatus() const
{
    return status;
}
