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
* <Definition of Movies Utility functions>
*
*/

#pragma once

#include <global/types.h>

void sortMoviesByTitle(movieType* movies, int moviesCount, const char* direction);

void sortMoviesByRating(movieType* movies, int moviesCount, const char* direction);
