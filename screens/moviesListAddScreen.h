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
* <Movies List Add Screen>
*
*/

#pragma once

#include <global/types.h>

void actionMoviesListAddScreen(const char* title, int year, const char* genre, const char* director, const char* const* actors, int actorsCount, int& result);

int formMoviesListAddScreen();

int renderMoviesListAddScreen();