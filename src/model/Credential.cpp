/*
 * Password Manager - Witty Application
 *
 * Model - A single credential
 * jathur, 11/12/2024
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
