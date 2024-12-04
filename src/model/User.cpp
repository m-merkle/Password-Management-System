/*
 * Password Manager - Witty Application
 *
 * Model - A single user
 * jathur, 11/12/2024
 */

#include <string>

#include "User.h"

using namespace passMang;

User::User(int id, std::string& user, std::string& pass, const userType& r)
{
    this->userID = id;
    this->username = user;
    this->password = pass;
    this->type = r;

    updateLastLogin();
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
