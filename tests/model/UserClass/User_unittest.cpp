#include "gtest/gtest.h"
#include <chrono>
#include <string.h>
#include <thread>

#include "../../../src/model/User.h"

namespace passMang {

TEST(UserTest, ConstructorAndGetters)
{
    int userID = 1;
    std::string username = "testUsername1";
    std::string password = "testPassword1";
    userType userRole(Role::Admin);

    User user(userID, username, password, userRole);

    EXPECT_EQ(userID, user.getUserID());
    EXPECT_EQ(username, user.getUsername());
    EXPECT_EQ(password, user.getPassword());
}

TEST(UserTest, UpdateLastLogin)
{
    int userID = 2;
    std::string username = "Username2";
    std::string password = "Password123";
    userType adminRole(Role::Regular);

    User user(userID, username, password, adminRole);

    auto firstLoginTime = user.getLastLogin();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    user.updateLastLogin();
    auto secondLoginTime = user.getLastLogin();

    EXPECT_LT(firstLoginTime, secondLoginTime);
}
}
