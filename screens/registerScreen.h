#pragma once

#include <controllers/authController.h>

void actionRegisterScreen(const char* username, const char* password, const char* repeatPassword, int& result);

int formRegisterPage(userType& user);

int renderRegisterScreen(userType& user);