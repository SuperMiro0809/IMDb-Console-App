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
* <Definition of Movies List Utility functions>
*
*/

#pragma once

#include <global/types.h>

void rateMovieAction(int userId);

void updateColumnForm(movieType& movie, int column, int& result);

void updateMovieAction();

void deleteMovieAction();
