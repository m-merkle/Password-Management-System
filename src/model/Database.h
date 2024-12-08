#ifndef DATABASE_H
#define DATABASE_H

#include "Credential.h"
#include "User.h"
#include <iostream>
#include <sqlite3.h>
#include <stdexcept>

#include "HashClass.h"

class Database
{
  public:
    Database() = delete;
    explicit Database(const std::string& dbFile);
    ~Database();

    // standard methods to access database
    std::string retrieveRecord(const std::string& table,
                               const std::string& criteria);
    bool insertRecord(const std::string& table, const std::string& data);
    bool UpdateRecord(const std::string& table,
                      const std::string& data,
                      const std::string& criteria);
    bool DeleteRecord(const std::string& table, const std::string& criteria);

    // User and credential methods to access database
    bool insertUser(const passMang::User& user);
    bool updateUser(const passMang::User& user);
    bool deleteUser(int userID);
    bool insertCredential(const passMang::Credential& credential,
                          std::string userid);
    bool updateCredential(const passMang::Credential& credential,
                          std::string userid);
    bool deleteCredential(int credID);
    bool validateUser(const std::string& username, const std::string& plainPassword);

  private:
    sqlite3* database;
    bool openDB();
    bool closeDB();
};

#endif // DATABASE_H
