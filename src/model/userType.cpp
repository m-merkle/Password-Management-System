/*
 * Password Manager - Witty Application
 *
 * Model - A type of user
 * jathur, 11/12/2024
 */

#include <string>

#include "userType.h"

using namespace passMang;

userType::userType(Role r)
{
	switch (r) {
	case Role::Admin:
		type = Role::Admin;
		text = "Admin";
		break;
	case Role::Regular:
		type = Role::Regular;
		text = "Regular";
		break;
	case Role::ViewOnly:
		type = Role::ViewOnly;
		text = "ViewOnly";
		break;
	}
}

Role
userType::getType() const
{
	return type;
}

std::string
userType::getText() const
{
	return text;
}
