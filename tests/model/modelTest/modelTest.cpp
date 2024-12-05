/*
 * Password Manager - Witty Application
 *
 * Model - Tests for User and Credential classes
 * jathur,anpier 11/12/2024
 */

#include "../../../src/model/Credential.h"
#include "../../../src/model/User.h"
#include "../../../src/model/userType.h"

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

int
main()
{

    // USER TEST
    // ----------------------------------------------------------------------------

    std::string username = "jathur";
    std::string password = "pass123";

    passMang::User* u = new passMang::User(
        123,
        username,
        password,
        passMang::userType(passMang::Role::Admin)); // create new User

    // GETTERS

    std::time_t time = std::chrono::system_clock::to_time_t(
        u->getLastLogin()); // get last login time and convert to time_t

    std::cout << "Type: " << u->getTypeStr() << std::endl;
    std::cout << "ID: " << u->getUserID() << std::endl;
    std::cout << "Username: " << u->getUsername() << std::endl;
    std::cout << "Password: " << u->getPassword() << std::endl;
    std::cout << "Last login: " << std::ctime(&time) << std::endl;

    // SETTERS

    u->updateLastLogin();

    time = std::chrono::system_clock::to_time_t(u->getLastLogin());

    std::cout << "Updated last login: " << std::ctime(&time) << std::endl;

    // CREDENTIAL TEST
    // ----------------------------------------------------------------------

    std::string credName = "Cred1";
    std::string username1 = "jathur1";
    std::string password1 = "pass111";
    std::string email = "jathur@cs.csis.work";
    std::string description = "sample description";

    passMang::Credential* c =
        new passMang::Credential(111,
                                 credName,
                                 email,
                                 username1,
                                 password1,
                                 description); // create new Credential

    // GETTERS

    std::time_t time1 =
        std::chrono::system_clock::to_time_t(c->getLastUpdated());

    std::cout << "ID: " << c->getCredID() << std::endl;
    std::cout << "Credential Name: " << c->getCredName() << std::endl;
    std::cout << "Email: " << c->getEmail() << std::endl;
    std::cout << "Username: " << c->getUsername() << std::endl;
    std::cout << "Password: " << c->getPassword() << std::endl;
    std::cout << "Last Updated: " << std::ctime(&time1) << std::endl;

    // SETTERS

    // Last Updated
    c->setLastUpdated();
    time1 = std::chrono::system_clock::to_time_t(c->getLastUpdated());
    std::cout << "Last Updated Reset: " << std::ctime(&time1) << std::endl;

    // Credential Name
    c->setCredName("Google Drive");
    std::cout << "Updated Credential Name: " << c->getCredName() << std::endl;

    // Email
    c->setEmail("user@gmail.com");
    std::cout << "Updated Credential Email: " << c->getEmail() << std::endl;

    // Username
    c->setUsername("Username1");
    std::cout << "Updated Credential Username: " << c->getUsername()
              << std::endl;

    // Password
    c->setPassword("Password1");
    std::cout << "Updated Credential Password: " << c->getPassword()
              << std::endl;

    return 0;
}
