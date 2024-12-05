#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <sqlite3.h>
#include <stdexcept>

class Database
{
  public:
    Database() = delete;
    explicit Database(const std::string& dbFile);
    ~Database();

    // User and credential methods to access database
    std::string retrieveRecord(const std::string& table,
                               const std::string& criteria);
    bool insertRecord(const std::string& table, const std::string& data);
    bool UpdateRecord(const std::string& table,
                      const std::string& data,
                      const std::string& criteria);
    bool DeleteRecord(const std::string& table, const std::string& criteria);

  private:
    sqlite3* database;
    bool openDB();
    bool closeDB();
};

#endif // DATABASE_H
