/*
 * Password Manager - Witty Application
 *
 * Model - model test driver
 * anpier  12/5/2024
 * Names: Andrew Pierson
 * Course: CS
 */

#include "Database.h"
#include "User.h"
#include "userType.h"
#include <iostream>
#include <string>

void
displayMenu()
{
    std::cout << "\n=== Password Manager ===\n";
    std::cout << "1. View Credentials\n";
    std::cout << "2. Insert Credential\n";
    std::cout << "3. Edit Credential\n";
    std::cout << "4. Delete Credential\n";
    std::cout << "5. View Users\n";
    std::cout << "6. Insert User\n";
    std::cout << "7. Edit User\n";
    std::cout << "8. Delete User\n";
    std::cout << "9. View All Credentials\n";
    std::cout << "10. View All Users\n";
    std::cout << "11. View Credentials by User ID\n";
    std::cout << "12. Exit\n";
    std::cout << "Choose an option: ";
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
                // access a credential with creteria
            case 1 : {
                std::string criteria;
                std::cout << "Enter criteria (e.g., id=1): ";
                std::getline(std::cin, criteria);
                std::string records =
                    db.retrieveRecord("Credentials", criteria);
                std::cout << "Records:\n" << records << "\n";
                break;
            }
            // insert a credential
            case 2 : {
                std::string data;
                std::cout << "Enter credential data: ";
                std::getline(std::cin, data);
                if (db.insertRecord("Credentials", data)) {
                    std::cout << "Credential inserted successfully.\n";
                } else {
                    std::cout << "Failed to insert credential.\n";
                }
                break;
            }
            // update a credential
            case 3 : {
                std::string data, criteria;
                std::cout
                    << "Enter data to update (e.g., password='newPass'): ";
                std::getline(std::cin, data);
                std::cout << "Enter criteria (e.g., id=1): ";
                std::getline(std::cin, criteria);
                if (db.UpdateRecord("Credentials", data, criteria)) {
                    std::cout << "Credential updated successfully.\n";
                } else {
                    std::cout << "Failed to update credential.\n";
                }
                break;
            }
            // delete a credential
            case 4 : {
                std::string criteria;
                std::cout << "Enter criteria (e.g., id=1): ";
                std::getline(std::cin, criteria);
                if (db.DeleteRecord("Credentials", criteria)) {
                    std::cout << "Credential deleted successfully.\n";
                } else {
                    std::cout << "Failed to delete credential.\n";
                }
                break;
            }
            // view a Users info based of a given criteria
            case 5 : {
                std::string criteria;
                std::cout << "Enter criteria (e.g., username=user): ";
                std::getline(std::cin, criteria);
                std::string records = db.retrieveRecord("Users", criteria);
                std::cout << "Records:\n" << records << "\n";
                break;
            }
            // inserted User
            case 6 : {
                std::string data;
                std::cout << "Enter user data: ";
                std::getline(std::cin, data);
                if (db.insertRecord("Users", data)) {
                    std::cout << "User inserted successfully.\n";
                } else {
                    std::cout << "Failed to insert user.\n";
                }
                break;
            }
            // update User
            case 7 : {
                std::string data, criteria;
                std::cout
                    << "Enter data to update (e.g., username='newUser'): ";
                std::getline(std::cin, data);
                std::cout << "Enter criteria (e.g., id=1): ";
                std::getline(std::cin, criteria);
                if (db.UpdateRecord("Users", data, criteria)) {
                    std::cout << "User updated successfully.\n";
                } else {
                    std::cout << "Failed to update user.\n";
                }
                break;
            }
            // delete User
            case 8 : {
                std::string criteria;
                std::cout << "Enter criteria (e.g., id=1): ";
                std::getline(std::cin, criteria);
                if (db.DeleteRecord("Users", criteria)) {
                    std::cout << "User deleted successfully.\n";
                } else {
                    std::cout << "Failed to delete user.\n";
                }
                break;
            }
                // retrive all credentials
            case 9 : {
                std::string records = db.retrieveRecord("Credentials", "1=1");
                std::cout << "All Credentials:\n" << records << "\n";
                break;
            }
            // retrive all users
            case 10 : {
                std::string records = db.retrieveRecord("Users", "1=1");
                std::cout << "All Users:\n" << records << "\n";
                break;
            }
            // view credentials by UserID
            case 11 : {
                std::string userid;
                std::cout << "Enter the User ID: ";
                std::getline(std::cin, userid);
                std::string criteria = "userid=" + userid;
                std::string records =
                    db.retrieveRecord("Credentials", criteria);
                if (! records.empty()) {
                    std::cout << "Credentials for User ID " << userid << ":\n"
                              << records << "\n";
                } else {
                    std::cout << "No credentials found for User ID " << userid
                              << ".\n";
                }
                break;
            }
            // exit program
            case 12 :
                running = false;
                std::cout << "Exiting the application.\n";
                break;
            default :
                std::cout << "Invalid option... Try again.\n";
        }
    }

    return 0;
}
