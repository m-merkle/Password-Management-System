/*
 * Password Manager - Witty Application
 *
 * Model - A single credential
 * jathur,anpier 11/12/2024
 */

#include <string>

#include "Credential.h"

using namespace passMang;

/* constructor */
Credential::Credential(int id,
                       std::string& n,
                       std::string& e,
                       std::string& user,
                       std::string& pass,
                       std::string& description)
{
    this->credID = id;
    this->credName = n;
    this->email = e;
    this->username = user;
    this->password = pass;
    this->description = description;

    setLastUpdated();
}
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

std::string
Credential::getDescription() const
{
    return description;
}

std::string
Credential::getLastUpdated() const
{
    return lastUpdated;
}

void Credential::setLastUpdated()
{
    lastupdated = std::chrono::system_clock::now(); 
    std::time_t unix_timestamp = std::chrono::system_clock::to_time_t(lastupdated); 
    std::tm* local_time = std::localtime(&unix_timestamp); 

    char time_str[100];
    std::strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time); 
    lastUpdated = time_str; 
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

void
Credential::setDescription(const std::string& desc)
{
    description = desc;
    setLastUpdated();
}
