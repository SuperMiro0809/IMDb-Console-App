#pragma once

#include <constants.h>

struct userType {
    int id;
    char* username;
    char* role;
};

constexpr const char* USER_DB = "users.txt";

constexpr int ID_COLUMN = 0;
constexpr int USERNAME_COLUMN = 1;
constexpr int PASSWORD_COLUMN = 2;
constexpr int ROLE_COLUMN = 3;

constexpr userType GUEST = { -1, nullptr, nullptr };

bool checkIfUserExists(const char* username);

int registerUser(const char* username, const char* password, const char* repeatPassword);

int loginUser(const char* username, const char* password);

userType getUserById(int id);
