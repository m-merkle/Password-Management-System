#include "../../../src/model/HashClass.h"
#include "gtest/gtest.h"

// test hash with pre computed hash value
TEST(HashClassTest, ToHashReturnsCorrectHash)
{
    std::string plainTextPassword = "testPassword";
    std::string expectedHash =
        "fd5cb51bafd60f6fdbedde6e62c473da6f247db271633e15919bab78a02ee9eb";
    std::string actualHash = HashClass::ToHash(plainTextPassword);

    EXPECT_EQ(expectedHash, actualHash);
}

// test from hash
TEST(HashClassTest, FromHashValidatesCorrectly)
{
    std::string plainTextPassword = "testPassword";
    std::string correctHash =
        "fd5cb51bafd60f6fdbedde6e62c473da6f247db271633e15919bab78a02ee9eb";

    bool isValid = HashClass::FromHash(plainTextPassword, correctHash);

    EXPECT_TRUE(isValid);
}

// failed hash attempt
TEST(HashClassTest, FromHashFailsOnIncorrectPassword)
{
    std::string plainTextPassword = "testPassword";
    std::string incorrectHash =
        "abcdef1234567890abcdef1234567890abcdef1234567890abcdef1234567890";

    bool isValid = HashClass::FromHash(plainTextPassword, incorrectHash);

    EXPECT_FALSE(isValid);
}

// test to see if two similar hashes are equal
TEST(HashClassTest, ToHashDifferentPasswordsProduceDifferentHashes)
{
    std::string password1 = "password1";
    std::string password2 = "password2";

    std::string hash1 = HashClass::ToHash(password1);
    std::string hash2 = HashClass::ToHash(password2);

    EXPECT_NE(hash1, hash2);
}
