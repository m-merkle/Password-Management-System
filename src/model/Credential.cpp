/*
 * Password Manager - Witty Application
 *
 * Model - A single credential
 * jathur,anpier 11/12/2024
 */

#include <string>

#include "Credential.h"

using namespace passMang;

int
Credential::getCredID() const
{
    return credID;
}

std::string
Credential::getCredName() const
{
    return credName;
}

std::string
Credential::getEmail() const
{
    return email;
}

std::string
Credential::getUsername() const
{
    return username;
}

std::string
Credential::getPassword() const
{
    return password;
}

std::chrono::system_clock::time_point
Credential::getLastUpdated() const
{
    return lastUpdated;
}

void
Credential::setLastUpdated()
{
    lastUpdated = std::chrono::system_clock::now();
}

void
Credential::setCredName(const std::string& name)
{
    credName = name;
    setLastUpdated();
}

void
Credential::setEmail(const std::string& mail)
{
    email = mail;
    setLastUpdated();
}

void
Credential::setUsername(const std::string& user)
{
    username = user;
    setLastUpdated();
}

void
Credential::setPassword(const std::string& pass)
{
    password = pass;
    setLastUpdated();
}
