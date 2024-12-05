/*
 * Password Manager - Witty Application
 *
 * Model - A type of user
 * anpier, jathur, 11/12/2024
 */
#ifndef USERTYPE_H
#define USERTYPE_H

#include <string>

namespace passMang {

enum class Role
{
    Admin,
    Regular,
    ViewOnly
};

class userType
{
  public:
    userType() = delete;
    explicit userType(Role r);

    Role getType() const;
    std::string getText() const;

  private:
    Role type;
    std::string text;
};

}

#endif /* USERTYPE_H */
