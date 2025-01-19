#pragma once

#include <types.h>

int getMoviesCount(routeParamsType routeParams);

void addActorsToMovie(const char* const* actors, int actorsCount, int movieId);

char** getMovieActors(int movieId, int actorsCount);

movieType* getMovies(routeParamsType routeParams);

int addMovie(const char* title, int year, const char* genre, const char* director, const char* const* actors, int actorsCount);

int updateMovie(int id);

int deleteMovie(int id);

void freeUpMoviesSpace(movieType* movies, int length);