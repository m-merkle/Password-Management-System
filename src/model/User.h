<<<<<<< HEAD
/*
 * Password Manager - Witty Application
 *
 * Model - A single user
 * jathur, 11/12/2024
=======
/* Names: Jagger Thurman, 
 * Course: CS455
 * Description: Header file for User class
>>>>>>> 0ae778888e753e60e9a57f3d797da4adddcf9fee
 */

#ifndef USER_H
#define USER_H

<<<<<<< HEAD
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
=======
#include <string>
#include <chrono>
#include <ctime>

	// Enum for Role
enum class Role {
	Admin,
	Regular,
	ViewOnly
};

class User {
	public:
		// constructors
		User() = delete;
		explicit User(int, std::string&, std::string&, Role);

		// getters
		int getUserID() const;
		std::string getUsername() const;
		std::string getPassword() const;
		std::string getRole() const;
		TimePoint getLastLogin() const;

		// setters
		bool setUserID(int);
		bool setUsername(std::string&);
		bool setPassword(std::string&);
		bool setRole(Role);
		bool setLastLogin(TimePoint);

	private:
		
		// fields
		int userID;
		std::string username;
		std::string password;
		Role role;
		TimePoint lastLogin;
		
};

#endif
>>>>>>> 0ae778888e753e60e9a57f3d797da4adddcf9fee
