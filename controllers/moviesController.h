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
* <Definition of Movie Controller functions>
*
*/

#pragma once

#include <global/types.h>

double getMovieRating(int movieId);

int getMoviesCount(routeParamsType routeParams);

int findMovieByIdOrTitle(const char* query);

void addActorsToMovie(const char* const* actors, int actorsCount, int movieId);

char** getMovieActors(int movieId, int actorsCount);

movieType* getMovies(routeParamsType routeParams);

movieType getMovieById(int movieId);

int addMovie(const char* title, int year, const char* genre, const char* director, const char* const* actors, int actorsCount);

int updateMovie(movieType movie);

int deleteMovie(const char* query);

int addMovieRating(const char* query, int userId, int rating);

void freeUpMovieSpace(movieType movie);

void freeUpMoviesSpace(movieType* movies, int length);
