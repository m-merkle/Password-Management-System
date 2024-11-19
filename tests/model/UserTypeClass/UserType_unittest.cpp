#include "gtest/gtest.h"

#include "../../../src/model/User.h"

namespace passMang {

TEST(UserTest, ConstructorAndGetters)
{
    userType admin(Role::Admin);
    userType regular(Role::Regular);
    userType viewOnly(Role::ViewOnly);

    EXPECT_EQ(Role::Admin, admin.getType());
    EXPECT_EQ("Admin", admin.getText());

    EXPECT_EQ(Role::Regular, regular.getType());
    EXPECT_EQ("Regular", regular.getText());

    EXPECT_EQ(Role::ViewOnly, viewOnly.getType());
    EXPECT_EQ("ViewOnly", viewOnly.getText());
}
}
