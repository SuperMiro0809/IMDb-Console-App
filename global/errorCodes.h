/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
*
* @author Miroslav Balev
* @idnumber 9MI0600470
* @compiler GCC
*
* <Error Codes>
*
*/

#pragma once

constexpr int LOGIN_FAILED = -1;
constexpr int USER_ALREDY_EXISTS = -2;
constexpr int PASSWORDS_NOT_MATCH = -3;
constexpr int MOVIE_NOT_FOUND = -4;
constexpr int INVALID_RATING = -5;
constexpr int INVALID_DATA_COLUMN = -6;

void printError(int errorCode);