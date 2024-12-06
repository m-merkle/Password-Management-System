/*
 * Password Manager - Witty Application
 *
 * Model - A single credential
 * jathur,anpier 11/12/2024
 */

#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <Wt/Dbo/Dbo.h>
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
               std::string& pass,
               std::string& description);

    // Getters
    int getCredID() const;
    std::string getCredName() const;
    std::string getEmail() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getDescription() const;
    std::chrono::system_clock::time_point getLastUpdated() const;

    // Setters
    void setLastUpdated();
    void setCredName(const std::string& name);
    void setEmail(const std::string& mail);
    void setUsername(const std::string& user);
    void setPassword(const std::string& pass);
    void setDescription(const std::string& desc);

    template <class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, credID, "credID");
        Wt::Dbo::field(a, credName, "credName");
        Wt::Dbo::field(a, username, "username");
        Wt::Dbo::field(a, password, "password");
        Wt::Dbo::field(a, email, "email");
        Wt::Dbo::field(a, description, "description");
    }

  private:
    int credID;
    std::string credName;
    std::string email;
    std::string username;
    std::string password;
    std::string description;
    std::chrono::system_clock::time_point lastUpdated;
};

}
#endif /* CREDENTIAL_H */
