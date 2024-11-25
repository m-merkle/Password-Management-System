/*
 * Password Manager - Witty Application
 *
 * Model - A single user
 * jathur,anpier  11/12/2024
 * Names: Jagger Thurman, Andrew Pierson
 * Course: CS
 */

#ifndef USER_H
#define USER_H

#include <chrono>
#include <ctime>
#include <string>

#include "userType.h"

namespace passMang {

class User
{
  public:
    User() = delete;
    User(int id, std::string& user, std::string& pass, const userType& r) :
        userID{id}, username{user}, password{pass}, type{r}
    {
        updateLastLogin();
    }

    // Getters
    int getUserID() const;
    std::string getUsername() const;
    std::string getPassword() const;
    Role getType() const;
    std::string getTypeStr() const;
    std::chrono::system_clock::time_point getLastLogin() const;

    // Setters
    void updateLastLogin();
    void setUsername(const std::string& user);
    void setPassword(const std::string& pass);
    void setType(const userType& r);

  private:
    // fields
    int userID;
    std::string username;
    std::string password;
    userType type;
    std::chrono::system_clock::time_point lastLogin;
};

}

#endif USER_H
