#ifndef USERLIST_H
#define USERLIST_H

#include <vector>
#include <string>

#include "User.h"

class userList::public User
{
	std::vector<string> userList;
	bool addUser(int, User, userType);/* Not sure what exactly null is supposed 
					     to be based on the UML diagram */
	bool deleteUser();
	bool getUser();
	bool searchUser();
};

#endif
