# Model Source Code

# The model consist of User, userType, Credential, and database controller classes to run.

# Instructions for running the model Controller:
1. type run "make"
2. run the ./drivertest file
3. choose an option on the menu


# Here is the schema for the database tables in the database file:
1. CREATE TABLE Users (UserID INTEGER PRIMARY KEY, Username TEXT NOT NULL,
    - Password TEXT NOT NULL, Role TEXT, LastLogin DATETIME); 

2. CREATE TABLE Credentials (CredentialID INTEGER PRIMARY KEY, CredName TEXT,
    - CredUsername TEXT, CredPassword TEXT, CredEmail TEXT, ROLE TEXT,
    - CredDescription TEXT, LastUpdated DATETIME, UserID INTEGER, FOREIGN KEY
    - (UserID)REFERENCES User(USERID));
 
# Here are sample inserts to the Credential and User database:
1. Sample User add:
    - "123", "user", "password", "admin", "2024-03-16 11:50:25"

2. Sample Credential add:
    - "938", "google drive", "anpier", "password1", "google@gmail.com", "admin",
    - "description adsjhfgdj", "2002-03-15 11:45:25", "123" 
