#pragma once

constexpr const char* USERS_DB = "users.txt";
constexpr const char* MOVIES_DB = "movies.txt";
constexpr const char* ACTORS_DB = "movie_actors.txt";
constexpr const char* RATINGS_DB = "movie_ratings.txt";

constexpr int USERS_ID_COLUMN = 0;
constexpr int USERS_USERNAME_COLUMN = 1;
constexpr int USERS_PASSWORD_COLUMN = 2;
constexpr int USERS_ROLE_COLUMN = 3;

constexpr int MOVIES_ID_COLUMN = 0;
constexpr int MOVIES_TITLE_COLUMN = 1;
constexpr int MOVIES_YEAR_COLUMN = 2;
constexpr int MOVIES_GENRE_COLUMN = 3;
constexpr int MOVIES_DIRECTOR_COLUMN = 4;
constexpr int MOVIES_ACTORS_COUNT_COLUMN = 5;

constexpr int ACTORS_MOVIE_ID_COLUMN = 0;
constexpr int ACTORS_NAME_COLUMN = 1;

constexpr int RATINGS_MOVIE_ID_COLUMN = 0;
constexpr int RATINGS_USER_ID_COLUMN = 1;
constexpr int RATINGS_RATING_COLUMN = 2;
