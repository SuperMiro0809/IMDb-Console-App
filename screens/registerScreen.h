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
* <Register Screen>
*
*/

#pragma once

#include <global/types.h>

void actionRegisterScreen(const char* username, const char* password, const char* repeatPassword, int& result);

int formRegisterPage(userType& user);

int renderRegisterScreen(userType& user);