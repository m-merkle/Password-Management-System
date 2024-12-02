/*
 * Password Manager - Witty Application
 *
 * View - status of request
 * momerk, 11/25/2024
 */

#include <Wt/WContainerWidget.h>
#include <string>

#ifndef STATUS_VIEW_H
#define STATUS_VIEW_H

using namespace Wt;

class statusView : public WContainerWidget
{
  public:
    statusView() = delete;
    statusView(bool status, std::string msg);

    bool getStatus() const;

  private:
    bool status;
    std::string msg;
};

#endif /* STATUS_VIEW_H */
