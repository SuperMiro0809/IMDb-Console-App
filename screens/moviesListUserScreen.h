#pragma once

#include <controllers/authController.h>

constexpr int SEARCH_TITLE_OPERATION = 1;
constexpr int SEARCH_GENRE_OPERATION = 2;
constexpr int RATE_OPERATION = 3;
constexpr int SORT_RATING_OPERATION = 4;
constexpr int SORT_TITLE_OPERATION = 5;
constexpr int FILTER_RATING_OPERATION = 6;
constexpr int LOGOUT_OPERATION = 7;

int actionMoviesListUserScreen();

int renderMoviesListUserScreen(userType user);