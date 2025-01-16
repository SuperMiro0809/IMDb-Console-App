#pragma once

#include <constants.h>
#include <types.h>

constexpr const char* USER_DB = "users.txt";

constexpr int ID_COLUMN = 0;
constexpr int USERNAME_COLUMN = 1;
constexpr int PASSWORD_COLUMN = 2;
constexpr int ROLE_COLUMN = 3;

bool checkIfUserExists(const char* username);

int registerUser(const char* username, const char* password, const char* repeatPassword);

int loginUser(const char* username, const char* password);

userType getUserById(int id);

void logoutUser(userType& currentUser);
