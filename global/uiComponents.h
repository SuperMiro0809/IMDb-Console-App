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
* <Definition of UI Components>
*
*/

#pragma once

#include <global/constants.h>
#include <global/colors.h>
#include <global/types.h>

void printScreenHeader(const char* title, int titleColor, const char* subtitle, int subtitleColor);

void printScreenText(const char* text, int textColor = DEFAULT_COLOR);

void printScreenDivider(int length = DEFAULT_DIVIDER_LENGTH);

char* printTextField(const char* prompt, int textColor = DEFAULT_COLOR);

int printNumberField(const char* prompt, int textColor = DEFAULT_COLOR);

char** printActorsField(int actorsCount, int textColor = DEFAULT_COLOR);

void printUserInfo(const char* username, const char* role);

void printMoviesTable(const movieType* movies, int length);

void printMovieInfo(movieType movie);

void printRouteParams(routeParamsType routeParams);
