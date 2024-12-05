/*
 * Password Manager - Witty Application
 *
 * Model - A single user
 * jathur, anpier, Miguel 12/3/2024
 */

#include <string>

#include "User.h"

using namespace passMang;

User::User() : userID(-1), username(""), password(""), type(Role::ViewOnly) {}

User::User(int id,
           const std::string& user,
           const std::string& pass,
           const userType& r) :
    userID(id),
    username(user), password(pass), type(r), lastLogin()
{
}

bool
User::operator==(const User& user)
{
    return (username == user.getUsername() && password == user.getPassword());
}

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
User::setUsername(const std::string& user)
{
    username = user;
}

void
User::setPassword(const std::string& newPassword)
{
    password = newPassword;
}

void
User::setType(const userType& newType)
{
    type = newType;
}

void
User::updateLastLogin()
{
    lastLogin = std::chrono::system_clock::now();
}
