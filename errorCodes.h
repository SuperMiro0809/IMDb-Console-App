#pragma once

constexpr int LOGIN_FAILED = -1;
constexpr int USER_ALREDY_EXISTS = -2;
constexpr int PASSWORDS_NOT_MATCH = -3;
constexpr int MOVIE_NOT_FOUND = -4;
constexpr int INVALID_RATING = -5;
constexpr int INVALID_DATA_COLUMN = -6;

void printError(int errorCode);