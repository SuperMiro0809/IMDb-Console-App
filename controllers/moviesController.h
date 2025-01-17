#pragma once

#include <types.h>

constexpr const char* MOVIES_DB = "movies.txt";
constexpr const char* ACTORS_DB = "movie_actors.txt";

constexpr int ID_COLUMN = 0;
constexpr int TITLE_COLUMN = 1;
constexpr int YEAR_COLUMN = 2;
constexpr int GENRE_COLUMN = 3;
constexpr int DIRECTOR_COLUMN = 4;
constexpr int RATING_COLUMN = 5;
constexpr int ACTORS_COUNT_COLUMN = 6;

constexpr int MOVIE_ID_COLUMN = 0;
constexpr int ACTOR_NAME_COLUMN = 1;

int getMoviesCount();

void addActorsToMovie(const char* const* actors, int actorsCount, int movieId);

char** getMovieActors(int movieId, int actorsCount);

movieType* getMovies(routeParamsType routeParams);

int addMovie(const char* title, int year, const char* genre, const char* director, const char* const* actors, int actorsCount);

int updateMovie(int id);

int deleteMovie(int id);

void freeUpMoviesSpace(movieType* movies, int length);