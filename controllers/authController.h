#pragma once

constexpr int ID_COLUMN = 0;
constexpr int USERNAME_COLUMN = 1;
constexpr int PASSWORD_COLUMN = 2;

bool checkIfUserExists(const char* username);

int registerUser(const char* username, const char* password, const char* repeatPassword);

int loginUser(const char* username, const char* password);