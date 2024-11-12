/*
 * Password Manager - Witty Application
 *
 * Model - A single user
 * jathur, 11/12/2024
 */

#include <string>

#include "User.h"

using namespace passMang;

int
User::getUserID() const
{
    return userID;
}

std::string
User::getUsername() const
{
    return username;
}

std::string
User::getPassword() const
{
    return password;
}

Role
User::getType() const
{
    return type.getType();
}

std::string
User::getTypeStr() const
{
    return type.getText();
}

std::chrono::system_clock::time_point
User::getLastLogin() const
{
    return lastLogin;
}

void
User::updateLastLogin()
{
    lastLogin = std::chrono::system_clock::now();
}
