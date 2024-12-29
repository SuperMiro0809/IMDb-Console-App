#pragma once

constexpr int LOGIN_FAILED = -1;
constexpr int USER_ALREDY_EXISTS = -2;
constexpr int PASSWORDS_NOT_MATCH = -3;

void printError(int errorCode);