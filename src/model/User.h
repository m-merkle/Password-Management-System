/* Names: Jagger Thurman, 
 * Course: CS455
 * Description: Header file for User class
 */

#ifndef USER_H
#define USER_H

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
