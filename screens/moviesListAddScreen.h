#pragma once

#include <types.h>

void actionMoviesListAddScreen(const char* title, int year, const char* genre, const char* director, const char* const* actors, int actorsCount, int& result);

int formMoviesListAddScreen();

int renderMoviesListAddScreen();