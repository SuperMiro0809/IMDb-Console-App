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
* <Definition of Route Params Utility functions>
*
*/

#include <utils/routeParamsUtils.h>

#include <global/constants.h>
#include <utils/stringUtils.h>

#include <iostream>
using namespace std;

void filterRatingQuery(routeParamsType& routeParams) {
    int value = 1;
    do {
        cout << "Please enter rating filter criteria (1 - 10): ";
        cin >> value;
    } while (value < 1 || value > 10);

    routeParams.filterRating = value;
}

void sortRatingQuery(routeParamsType& routeParams) {
    // remove other sorting if there is one
    if (routeParams.sortTitle) {
        delete[] routeParams.sortTitle;
        routeParams.sortTitle = nullptr;
    }

    if (routeParams.sortRating) {
        delete[] routeParams.sortRating;
    }

    char* value = new char[INITIAL_SORT_VALUE_SIZE];
    bool firstTry = true;

    do {
        cout << "Please enter how you want to sort? < "
             << ASC_SORT << " | "
             << DESC_SORT << " | "
             << NO_SORT << " >:";

        if (firstTry) {
            cin.ignore(); // discard newline character
        }

        cin.getline(value, INITIAL_SORT_VALUE_SIZE);

        firstTry = false;
    } while(myStrCmp(value, ASC_SORT) != 0 && myStrCmp(value, DESC_SORT) != 0 && myStrCmp(value, NO_SORT) != 0);

    if (myStrCmp(value, NO_SORT) == 0) {
        delete[] value;
        routeParams.sortRating = nullptr;
    } else {
        routeParams.sortRating = value;
    }
}

void sortTitleQuery(routeParamsType& routeParams) {
    // remove other sorting if there is one
    if (routeParams.sortRating) {
        delete[] routeParams.sortRating;
        routeParams.sortRating = nullptr;
    }

    if (routeParams.sortTitle) {
        delete[] routeParams.sortTitle;
    }

    char* value = new char[INITIAL_SORT_VALUE_SIZE];
    bool firstTry = true;

    do {
        cout << "Please enter how you want to sort? < "
             << ASC_SORT << " | "
             << DESC_SORT << " | "
             << NO_SORT << " >:";

        if (firstTry) {
            cin.ignore(); // discard newline character
        }

        cin.getline(value, INITIAL_SORT_VALUE_SIZE);

        firstTry = false;
    } while(myStrCmp(value, ASC_SORT) != 0 && myStrCmp(value, DESC_SORT) != 0 && myStrCmp(value, NO_SORT) != 0);

    if (myStrCmp(value, NO_SORT) == 0) {
        delete[] value;
        routeParams.sortTitle = nullptr;
    } else {
        routeParams.sortTitle = value;
    }
}

void searchTitleQuery(routeParamsType& routeParams) {
    if (routeParams.searchTitle) {
        delete[] routeParams.searchTitle;
    }

    char* value = new char[DEFAULT_TEXT_FIELD_LENGTH];

    cout << "Please enter title search query? " << "< type \"no\" to remove existing filter >: ";
    cin.ignore(); // discard newline character

    cin.getline(value, DEFAULT_TEXT_FIELD_LENGTH);

    if (myStrCmp(value, NO_SEARCH) == 0) {
        delete[] value;
        routeParams.searchTitle = nullptr;
    } else {
        routeParams.searchTitle = value;
    }
}

void searchGenreQuery(routeParamsType& routeParams) {
    if (routeParams.searchGenre) {
        delete[] routeParams.searchGenre;
    }

    char* value = new char[DEFAULT_TEXT_FIELD_LENGTH];

    cout << "Please enter genre search query? " << "< type \"no\" to remove existing filter >: ";
    cin.ignore(); // discard newline character

    cin.getline(value, DEFAULT_TEXT_FIELD_LENGTH);

    if (myStrCmp(value, NO_SEARCH) == 0) {
        delete[] value;
        routeParams.searchGenre = nullptr;
    } else {
        routeParams.searchGenre = value;
    }
}

void resetRouteParams(routeParamsType& routeParams) {
    if (routeParams.searchTitle) {
        delete[] routeParams.searchTitle;
    }

    if (routeParams.searchGenre) {
        delete[] routeParams.searchGenre;
    }

    if (routeParams.sortTitle) {
        delete[] routeParams.sortTitle;
    }

    if (routeParams.sortRating) {
        delete[] routeParams.sortRating;
    }

    routeParams = INITIAL_ROUTE_PARAMS;
}
