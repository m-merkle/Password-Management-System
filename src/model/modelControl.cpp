/*
 * Password Manager - Witty Application
 *
 * Model - model test driver
 * anpier  12/5/2024
 * Names: Andrew Pierson
 * Course: CS
 */

#include "Credential.h"
#include "Database.h"
#include "User.h"
#include "userType.h"
#include <ctime>
#include <iostream>
#include <string>

void
displayMenu()
{
    std::cout << "\n=== Password Manager ===\n";
    std::cout << "1. View All Credentials\n";
    std::cout << "2. View All Users\n";
    std::cout << "3. View Credentials by User ID\n";
    std::cout << "4. Add New User\n";
    std::cout << "5. Add New Credential\n";
    std::cout << "6. Update User\n";
    std::cout << "7. Update Credential\n";
    std::cout << "8. Remove User\n";
    std::cout << "9. Remove Credential\n";
    std::cout << "10. Exit\n";
    std::cout << "Choose an option: ";
}

void
addNewUser(Database& db)
{
    int id;
    std::string username, password, roleStr;
    passMang::Role role;

    std::cout << "Enter User ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter Username: ";
    std::getline(std::cin, username);

    std::cout << "Enter Password: ";
    std::getline(std::cin, password);

    std::cout << "Enter Role (Admin/Regular/ViewOnly): ";
    std::getline(std::cin, roleStr);

    if (roleStr == "Admin") {
        role = passMang::Role::Admin;
    } else if (roleStr == "Regular") {
        role = passMang::Role::Regular;
    } else {
        role = passMang::Role::ViewOnly;
    }

    passMang::userType userType(role);
    passMang::User user(id, username, password, userType);
    user.updateLastLogin();

    if (db.insertUser(user)) {
        std::cout << "User added successfully.\n";
    } else {
        std::cout << "Failed to add user.\n";
    }
}

void
addNewCredential(Database& db)
{
    int id;
    std::string name, email, username, password, description, userid;

    std::cout << "Enter Credential ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter Credential Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Email: ";
    std::getline(std::cin, email);

    std::cout << "Enter Username: ";
    std::getline(std::cin, username);

    std::cout << "Enter Password: ";
    std::getline(std::cin, password);

    std::cout << "Enter Description: ";
    std::getline(std::cin, description);

    std::cout << "Enter the UserID associated with credential: ";
    std::getline(std::cin, userid);

    passMang::Credential credential(
        id, name, email, username, password, description);
    credential.setLastUpdated();

    if (db.insertCredential(credential, userid)) {
        std::cout << "Credential added successfully.\n";
    } else {
        std::cout << "Failed to add credential.\n";
    }
}

void
updateUser(Database& db)
{
    int id;
    std::string username, password, roleStr;
    passMang::Role role;

    std::cout << "Enter User ID to update: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter New Username: ";
    std::getline(std::cin, username);

    std::cout << "Enter New Password: ";
    std::getline(std::cin, password);

    std::cout << "Enter New Role (Admin/Regular/ViewOnly): ";
    std::getline(std::cin, roleStr);

    if (roleStr == "Admin") {
        role = passMang::Role::Admin;
    } else if (roleStr == "Regular") {
        role = passMang::Role::Regular;
    } else {
        role = passMang::Role::ViewOnly;
    }

    passMang::userType userType(role);
    passMang::User user(id, username, password, userType);
    user.updateLastLogin();

    if (db.updateUser(user)) {
        std::cout << "User updated successfully.\n";
    } else {
        std::cout << "Failed to update user.\n";
    }
}

void
updateCredential(Database& db)
{
    int id;
    std::string name, email, username, password, description, userid;

    std::cout << "Enter Credential ID to update: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter New Credential Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter New Email: ";
    std::getline(std::cin, email);

    std::cout << "Enter New Username: ";
    std::getline(std::cin, username);

    std::cout << "Enter New Password: ";
    std::getline(std::cin, password);

    std::cout << "Enter New Description: ";
    std::getline(std::cin, description);

    std::cout << "Enter the UserID associated with credential: ";
    std::getline(std::cin, userid);

    passMang::Credential credential(
        id, name, email, username, password, description);
    credential.setLastUpdated();

    if (db.updateCredential(credential, userid)) {
        std::cout << "Credential updated successfully.\n";
    } else {
        std::cout << "Failed to update credential.\n";
    }
}

void
removeUser(Database& db)
{
    int id;

    std::cout << "Enter User ID to remove: ";
    std::cin >> id;

    if (db.deleteUser(id)) {
        std::cout << "User removed successfully.\n";
    } else {
        std::cout << "Failed to remove user.\n";
    }
}

void
removeCredential(Database& db)
{
    int id;

    std::cout << "Enter Credential ID to remove: ";
    std::cin >> id;

    if (db.deleteCredential(id)) {
        std::cout << "Credential removed successfully.\n";
    } else {
        std::cout << "Failed to remove credential.\n";
    }
}

int
main()
{
    Database db("Passmang.db");
    bool running = true;
    int choice;

    while (running) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1 :
                std::cout << "All Credentials:\n"
                          << db.retrieveRecord("Credentials", "1=1") << "\n";
                break;
            case 2 :
                std::cout << "All Users:\n"
                          << db.retrieveRecord("Users", "1=1") << "\n";
                break;
            case 3 : {
                std::string userId;
                std::cout << "Enter the User ID: ";
                std::getline(std::cin, userId);
                std::string criteria = "userid=" + userId;
                std::cout << "Credentials for User ID " << userId << ":\n"
                          << db.retrieveRecord("Credentials", criteria) << "\n";
                break;
            }
            case 4 :
                addNewUser(db);
                break;
            case 5 :
                addNewCredential(db);
                break;
            case 6 :
                updateUser(db);
                break;
            case 7 :
                updateCredential(db);
                break;
            case 8 :
                removeUser(db);
                break;
            case 9 :
                removeCredential(db);
                break;
            case 10 :
                running = false;
                std::cout << "Exiting the application.\n";
                break;
            default :
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
