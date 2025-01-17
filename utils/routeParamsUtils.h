#pragma once

#include <types.h>

constexpr int INITIAL_SORT_VALUE_SIZE = 5;
constexpr const char* NO_SORT = "no";
constexpr const char* ASC_SORT = "asc";
constexpr const char* DESC_SORT = "desc";

void filterRatingQuery(routeParamsType& routeParams, int min, int max);

void sortRatingQuery(routeParamsType& routeParams, char* value);

void sortTitleQuery(routeParamsType& routeParams);

void searchTitleQuery(routeParamsType& routeParams);

void searchGenreQuery(routeParamsType& routeParams, char* value);
