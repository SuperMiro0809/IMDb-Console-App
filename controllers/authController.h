#pragma once

#include <types.h>

bool checkIfUserExists(const char* username);

int registerUser(const char* username, const char* password, const char* repeatPassword);

int loginUser(const char* username, const char* password);

userType getUserById(int id);

void logoutUser(userType& currentUser);
