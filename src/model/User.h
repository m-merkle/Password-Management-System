/*
 * Password Manager - Witty Application
 *
 * Model - A single user
 * jathur, 11/12/2024
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
    User(int id, std::string& user, std::string& pass, userType r) :
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

  private:
    // fields
    int userID;
    std::string username;
    std::string password;
    userType type;
    std::chrono::system_clock::time_point lastLogin;
};

}

#endif /* USER_H */
