#pragma once

#include <types.h>

int getMoviesCount(routeParamsType routeParams);

int getMovieByIdOrTitle(const char* query);

void addActorsToMovie(const char* const* actors, int actorsCount, int movieId);

char** getMovieActors(int movieId, int actorsCount);

double getMovieRating(int movieId);

movieType* getMovies(routeParamsType routeParams);

int addMovie(const char* title, int year, const char* genre, const char* director, const char* const* actors, int actorsCount);

int updateMovie(int id);

int deleteMovie(int id);

int addMovieRating(const char* query, int userId, int rating);

void freeUpMoviesSpace(movieType* movies, int length);
