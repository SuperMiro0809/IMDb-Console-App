#pragma once

#include <controllers/authController.h>

void actionLoginScreen(const char* username, const char* password, int& result);

int formLoginScreen(userType& user);

int renderLoginScreen(userType& user);