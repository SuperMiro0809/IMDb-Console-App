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
* <Login Screen>
*
*/

#pragma once

#include <global/types.h>

void actionLoginScreen(const char* username, const char* password, int& result);

int formLoginScreen(userType& user);

int renderLoginScreen(userType& user);