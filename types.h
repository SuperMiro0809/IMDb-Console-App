#pragma once

struct userType {
    int id;
    char* username;
    char* role;
};

constexpr userType GUEST = { -1, nullptr, nullptr };

struct routeParamsType {
    int filterRatingMin;
    int filterRatingMax;
    char* sortTitle; // nullptr | asc | desc
    char* sortRating; // nullptr | asc | desc
    char* searchTitle;
    char* searchGenre;
};

constexpr routeParamsType INITIAL_ROUTE_PARAMS = { -1, -1, nullptr, nullptr, nullptr, nullptr };

struct movieType {
    int id;
    char* title;
    int year;
    char* genre;
    char* director;
    char* rating;
    char** actors;
    int actorsCount;
};
