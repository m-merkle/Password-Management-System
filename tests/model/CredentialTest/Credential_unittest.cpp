#include "gtest/gtest.h"
#include <chrono>
#include <thread>
#include "Credential.h"

namespace passMang {

TEST(CredentialTest, ConstructorAndGetters) {
    int credID = 1;
    std::string credName = "testCredName1";
    std::string email = "test@email.com";
    std::string username = "testUsername1";
    std::string password = "testPassword1";

    Credential cred(credID, credName, email, username, password);

    EXPECT_EQ(credID, cred.getCredID());
    EXPECT_EQ(credName, cred.getCredName());
    EXPECT_EQ(email, cred.getEmail());
    EXPECT_EQ(username, cred.getUsername());
    EXPECT_EQ(password, cred.getPassword());
}

TEST(CredentialTest, UpdateLastUpdated) {
    int credID = 2;
    std::string credName = "CredName2";
    std::string email = "test2@email.com";
    std::string username = "Username2";
    std::string password = "Password123";

    Credential cred(credID, credName, email, username, password);

    auto firstUpdateTime = cred.getLastUpdated();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cred.setLastUpdated();
    auto secondUpdateTime = cred.getLastUpdated();

    EXPECT_LT(firstUpdateTime, secondUpdateTime);
}

} 