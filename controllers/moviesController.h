#pragma once

constexpr const char* MOVIES_DB = "movies.txt";

constexpr int ID_COLUMN = 0;
constexpr int TITLE_COLUMN = 1;
constexpr int YEAR_COLUMN = 2;
constexpr int GENRE_COLUMN = 3;
constexpr int DIRECTOR_COLUMN = 4;
constexpr int RATING_COLUMN = 5;

int getMovies();

int addMovie(const char* title, int year, const char* genre, const char* director);

int updateMovie(int id);

int deleteMovie(int id);