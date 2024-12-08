/*
 * Password Manager - Witty Application
 *
 * Model - Class that hashes and unhashes passwords
 * anpier 12/8/2024
 */
#ifndef HASHCLASS_H
#define HASHCLASS_H

#include <iomanip>
#include <openssl/sha.h>
#include <sstream>
#include <string>

class HashClass
{
  public:
    static std::string ToHash(const std::string& plainTextPassword);
    static bool FromHash(const std::string& plainTextPassword,
                         const std::string& hashedPassword);
};

#endif /* HASHCLASS_H */
