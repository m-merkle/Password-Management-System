/*
 * Password Manager - Witty Application
 *
 * Model - A single credential
 * jathur, 11/12/2024
 */

#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <chrono>
#include <ctime>
#include <string>

namespace passMang {

class Credential
{
  public:
    Credential() = delete;
    Credential(int id,
               std::string& n,
               std::string& e,
               std::string& user,
               std::string& pass) :
        credID{id},
        credName{n}, email{e}, username{user}, password{pass}
    {
        setLastUpdated();
    }

    // Getters
    int getCredID() const;
    std::string getCredName() const;
    std::string getEmail() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::chrono::system_clock::time_point getLastUpdated() const;

    // Setters
    void setLastUpdated();

  private:
    int credID;
    std::string credName;
    std::string email;
    std::string username;
    std::string password;
    std::chrono::system_clock::time_point lastUpdated;
};

}
#endif /* CREDENTIAL_H */
