#include "Database.h"

// Constructor
Database::Database(const std::string& dbFile)
{
    if (sqlite3_open(dbFile.c_str(), &database) != SQLITE_OK) {
        throw std::runtime_error("Failed to open database");
    }
}

// Destructor
Database::~Database()
{
    sqlite3_close(database);
}

// Private methods
bool
Database::openDB()
{
    if (database == nullptr) {
        return false;
    }
    return true;
}

bool
Database::closeDB()
{
    if (sqlite3_close(database) == SQLITE_OK) {
        database = nullptr;
        return true;
    }
    return false;
}

// Public Methods
bool
Database::insertRecord(const std::string& table, const std::string& data)
{
    sqlite3_stmt* stmt;
    std::string sql = "INSERT INTO " + table + " VALUES (" + data + ");";

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(database, sql.c_str(), -1, &stmt, nullptr) !=
        SQLITE_OK) {
        std::cerr << "Error preparing insert statement: "
                  << sqlite3_errmsg(database) << std::endl;
        return false;
    }

    // Execute the SQL statement
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error executing insert statement: "
                  << sqlite3_errmsg(database) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
    return true;
}

std::string
Database::retrieveRecord(const std::string& table, const std::string& criteria)
{
    sqlite3_stmt* stmt;
    std::string sql = "SELECT * FROM " + table + " WHERE " + criteria + ";";
    std::string record = "";

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(database, sql.c_str(), -1, &stmt, nullptr) !=
        SQLITE_OK) {
        std::cerr << "Error preparing select statement: "
                  << sqlite3_errmsg(database) << std::endl;
        return record;
    }

    // Execute the statement and iterate over results
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int cols = sqlite3_column_count(stmt);
        for (int i = 0; i < cols; ++i) {
            const char* text =
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            if (text) {
                record += text;
            }
            if (i < cols - 1) {
                record += ", ";
            }
        }
        record += "\n";
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
    return record;
}

bool
Database::UpdateRecord(const std::string& table,
                       const std::string& data,
                       const std::string& criteria)
{
    sqlite3_stmt* stmt;
    std::string sql =
        "UPDATE " + table + " SET " + data + " WHERE " + criteria + ";";

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(database, sql.c_str(), -1, &stmt, nullptr) !=
        SQLITE_OK) {
        std::cerr << "Error preparing update statement: "
                  << sqlite3_errmsg(database) << std::endl;
        return false;
    }

    // Execute the SQL statement
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error executing update statement: "
                  << sqlite3_errmsg(database) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
    return true;
}

bool
Database::DeleteRecord(const std::string& table, const std::string& criteria)
{
    sqlite3_stmt* stmt;
    std::string sql = "DELETE FROM " + table + " WHERE " + criteria + ";";

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(database, sql.c_str(), -1, &stmt, nullptr) !=
        SQLITE_OK) {
        std::cerr << "Error preparing delete statement: "
                  << sqlite3_errmsg(database) << std::endl;
        return false;
    }

    // Execute the SQL statement
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error executing delete statement: "
                  << sqlite3_errmsg(database) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
    return true;
}

bool
Database::insertUser(const passMang::User& user)
{
    std::string sql =
        std::to_string(user.getUserID()) + ", '" + user.getUsername() + "', '" +
        user.getPassword() + "', '" + user.getTypeStr() + "', '" +
        std::to_string(std::chrono::duration_cast<std::chrono::seconds>(
                           user.getLastLogin().time_since_epoch())
                           .count()) +
        "'";
    return insertRecord("Users", sql);
}

bool
Database::updateUser(const passMang::User& user)
{
    std::string sql =
        "Username = '" + user.getUsername() + "', Password = '" +
        user.getPassword() + "', Type = '" + user.getTypeStr() +
        "', LastLogin = '" +
        std::to_string(std::chrono::duration_cast<std::chrono::seconds>(
                           user.getLastLogin().time_since_epoch())
                           .count()) +
        "'";
    std::string criteria = "UserID = " + std::to_string(user.getUserID());
    return UpdateRecord("Users", sql, criteria);
}

bool
Database::deleteUser(int userID)
{
    std::string criteria = "UserID = " + std::to_string(userID);
    return DeleteRecord("Users", criteria);
}

bool
Database::insertCredential(const passMang::Credential& credential,
                           std::string userid)
{
    std::string sql =
        std::to_string(credential.getCredID()) + ", '" +
        credential.getCredName() + "', '" + credential.getUsername() + "', '" +
        credential.getPassword() + "', '" + credential.getEmail() + "', '" +
        credential.getDescription() + "', '" +
        std::to_string(std::chrono::duration_cast<std::chrono::seconds>(
                           credential.getLastUpdated().time_since_epoch())
                           .count()) +
        "', '" + userid + "'";
    return insertRecord("Credentials", sql);
}

bool
Database::updateCredential(const passMang::Credential& credential,
                           std::string userid)
{
    std::string sql =
        "CredName = '" + credential.getCredName() + "', CredUsername = '" +
        credential.getUsername() + "', CredPassword = '" +
        credential.getPassword() + "', CredEmail = '" + credential.getEmail() +
        "', CredDescription = '" + credential.getDescription() + "'";
    std::string criteria =
        "CredentialID = " + std::to_string(credential.getCredID()) +
        " AND UserID = '" + userid + "'";
    return UpdateRecord("Credentials", sql, criteria);
}

bool
Database::deleteCredential(int credID)
{
    std::string criteria = "CredentialID = " + std::to_string(credID);
    return DeleteRecord("Credentials", criteria);
}
