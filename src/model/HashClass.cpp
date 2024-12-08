#include "HashClass.h"

std::string
HashClass::ToHash(const std::string& plainTextPassword)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(plainTextPassword.c_str()),
           plainTextPassword.size(),
           hash);

    // Convert to hexadecimal string
    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    return oss.str();
}

// Generate the hash of the plain-text password and compare
bool
HashClass::FromHash(const std::string& plainTextPassword,
                    const std::string& hashedPassword)
{
    return ToHash(plainTextPassword) == hashedPassword;
}
