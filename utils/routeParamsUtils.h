#pragma once

#include <global/types.h>

constexpr int INITIAL_SORT_VALUE_SIZE = 5;
constexpr const char* NO_SORT = "no";
constexpr const char* ASC_SORT = "asc";
constexpr const char* DESC_SORT = "desc";
constexpr const char* NO_SEARCH = "no";

void filterRatingQuery(routeParamsType& routeParams);

void sortRatingQuery(routeParamsType& routeParams);

void sortTitleQuery(routeParamsType& routeParams);

void searchTitleQuery(routeParamsType& routeParams);

void searchGenreQuery(routeParamsType& routeParams);
