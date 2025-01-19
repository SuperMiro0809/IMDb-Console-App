/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
*
* @author Miroslav Balev
* @idnumber 9MI0600470
* @compiler GCC
*
* <Types>
*
*/

#pragma once

struct userType {
    int id;
    char* username;
    char* role;
};

constexpr userType GUEST = { -1, nullptr, nullptr };

struct routeParamsType {
    int filterRating;
    char* sortTitle; // nullptr | asc | desc
    char* sortRating; // nullptr | asc | desc
    char* searchTitle;
    char* searchGenre;
};

constexpr routeParamsType INITIAL_ROUTE_PARAMS = { 1, nullptr, nullptr, nullptr, nullptr };

struct movieType {
    int id;
    char* title;
    int year;
    char* genre;
    char* director;
    double rating;
    char** actors;
    int actorsCount;
};
