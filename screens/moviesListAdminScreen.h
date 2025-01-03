#pragma once

#include <controllers/authController.h>

constexpr int ADMIN_SEARCH_TITLE_OPERATION = 1;
constexpr int ADMIN_SEARCH_GENRE_OPERATION = 2;
constexpr int ADMIN_RATE_OPERATION = 3;
constexpr int ADMIN_SORT_RATING_OPERATION = 4;
constexpr int ADMIN_SORT_TITLE_OPERATION = 5;
constexpr int ADMIN_FILTER_RATING_OPERATION = 6;
constexpr int ADMIN_ADD_OPERATION = 7;
constexpr int ADMIN_UPDATE_OPERATION = 8;
constexpr int ADMIN_DELETE_OPERATION = 9;
constexpr int ADMIN_LOGOUT_OPERATION = 10;

void actionMoviesListAdminScreen();

void renderMoviesListAdminScreen(userType user);