#include "../../../src/model/Credential.h"
#include "gtest/gtest.h"
#include <chrono>
#include <thread>

namespace passMang {

TEST(CredentialTest, ConstructorAndGetters)
{
    int credID = 1;
    std::string credName = "testCredName1";
    std::string email = "test@email.com";
    std::string username = "testUsername1";
    std::string password = "testPassword1";
    std::string description = "description1";

    Credential cred(credID, credName, email, username, password, description);

    EXPECT_EQ(credID, cred.getCredID());
    EXPECT_EQ(credName, cred.getCredName());
    EXPECT_EQ(email, cred.getEmail());
    EXPECT_EQ(username, cred.getUsername());
    EXPECT_EQ(password, cred.getPassword());
    EXPECT_EQ(description, cred.getDescription());
}

TEST(CredentialTest, UpdateLastUpdated)
{
    int credID = 2;
    std::string credName = "CredName2";
    std::string email = "test2@email.com";
    std::string username = "Username2";
    std::string password = "Password123";
    std::string description = "description2";

    Credential cred(credID, credName, email, username, password, description);

    auto firstUpdateTime = cred.getLastUpdated();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cred.setLastUpdated();
    auto secondUpdateTime = cred.getLastUpdated();

    EXPECT_LT(firstUpdateTime, secondUpdateTime);
}

TEST(CredentialTest, Setters)
{
    int credID = 3;
    std::string credName = "CredName3";
    std::string email = "test3@email.com";
    std::string username = "Username3";
    std::string password = "Password123";
    std::string description = "description3";

    Credential cred(credID, credName, email, username, password, description);

    // Credential Name
    std::string newCredName = "NewCredentialName";
    cred.setCredName(newCredName);
    EXPECT_EQ(newCredName, cred.getCredName());

    // Email
    std::string newEmail = "new@email.com";
    cred.setEmail(newEmail);
    EXPECT_EQ(newEmail, cred.getEmail());

    // Username
    std::string newUsername = "newUser";
    cred.setUsername(newUsername);
    EXPECT_EQ(newUsername, cred.getUsername());

    // Password
    std::string newPassword = "newPassword123";
    cred.setPassword(newPassword);
    EXPECT_EQ(newPassword, cred.getPassword());

    // Description
    std::string newDescription = "newDescription";
    cred.setDescription(newDescription);
    EXPECT_EQ(newDescription, cred.getDescription());
}
}
