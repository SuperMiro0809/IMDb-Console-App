#include <controllers/authController.h>

#include <iostream>
#include <fstream>
#include <utils/databaseUtils.h>
#include <utils/stringUtils.h>
#include <errorCodes.h>
using namespace std;

bool checkIfUserExists(const char* username) {
    ifstream MyFile("users.txt");

    if (!MyFile.is_open()) {
        cout << "Error: Unable to open file: users.txt" << endl;
        return false;
    }

    char line[DEFAULT_DB_ROW_SIZE];

    while (MyFile >> line) {
        char* currentUsername = getColumn(line, USERNAME_COLUMN);

        int cmp = myStrCmp(username, currentUsername);

        delete[] currentUsername;

        if (cmp == 0) {
            MyFile.close();
            return true;
        }
    }

    MyFile.close();
    return false;
}

int registerUser(const char* username, const char* password, const char* repeatPassword) {
    if (!username || !password || !repeatPassword) {
        return 0;
    }

    // check if passwords match
    bool passwordMatch = myStrCmp(password, repeatPassword);
    if (passwordMatch != 0) {
        return PASSWORDS_NOT_MATCH;
    }

    // check if username already exists
    bool isRegistered = checkIfUserExists(username);
    if (isRegistered) {
        return USER_ALREDY_EXISTS;
    }

    ofstream MyFile("users.txt", ios::app); // open file in append mode

    // save record
    int nextId = autoIncrement("users.txt");
    MyFile << nextId << DEFAULT_DB_DELIMITER;
    MyFile << username << DEFAULT_DB_DELIMITER;
    MyFile << password << DEFAULT_DB_DELIMITER;
    MyFile << "User" << '\n';

    MyFile.close();
    return nextId;
}

int loginUser(const char* username, const char* password) {
    if (!username || !password) {
        return 0;
    }

    ifstream MyFile("users.txt");

    if (!MyFile.is_open()) {
        cout << "Error: Unable to open file: users.txt" << endl;
        return false;
    }

    char line[DEFAULT_DB_ROW_SIZE];

    while (MyFile >> line) {
        char* currentId = getColumn(line, ID_COLUMN);
        char* currentUsername = getColumn(line, USERNAME_COLUMN);
        char* currentPassword = getColumn(line, PASSWORD_COLUMN);

        int cmpUsername = myStrCmp(username, currentUsername);
        int cmpPassword = myStrCmp(password, currentPassword);
        int idNumber = myAtoi(currentId);

        delete[] currentUsername;
        delete[] currentPassword;
        delete[] currentId;

        if (cmpUsername == 0 && cmpPassword == 0) {
            MyFile.close();
            return idNumber;
        }
    }

    MyFile.close();
    return LOGIN_FAILED;
}

userType getUserById(int id) {
    ifstream MyFile("users.txt");

    char line[DEFAULT_DB_ROW_SIZE];
    while (MyFile >> line) {
        char* currentId = getColumn(line, ID_COLUMN);
        int idNumber = myAtoi(currentId);

        delete[] currentId;

        if (idNumber == id) {
            char* currentUsername = getColumn(line, USERNAME_COLUMN);
            char* currentRole = getColumn(line, ROLE_COLUMN);

            userType currentUser;
            currentUser.id = idNumber;
            currentUser.username = currentUsername;
            currentUser.role = currentRole;

            // used dynamic memory here will be deleted on logout

            MyFile.close();

            return currentUser;
        }
    }

    return GUEST;
}