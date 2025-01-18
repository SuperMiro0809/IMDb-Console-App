#include <utils/routeParamsUtils.h>

#include <constants.h>
#include <utils/stringUtils.h>

#include <iostream>
using namespace std;

void filterRatingQuery(routeParamsType& routeParams, int min, int max) {
    routeParams.filterRatingMin = min;
    routeParams.filterRatingMax = max;
}

void sortRatingQuery(routeParamsType& routeParams, char* value) {
    routeParams.sortRating = value;
}

void sortTitleQuery(routeParamsType& routeParams) {
    if (routeParams.sortTitle) {
        delete[] routeParams.sortTitle;
    }

    char* value = new char[INITIAL_SORT_VALUE_SIZE];
    bool firstTry = true;

    do {
        cout << "Please enter how you want to sort? "
             << "< " << ASC_SORT << " | "
             << DESC_SORT << " | "
             << NO_SORT << " >:";

        if (firstTry) {
            cin.ignore(); // discard newline character
        }

        cin.getline(value, INITIAL_SORT_VALUE_SIZE);

        firstTry = false;
    } while(myStrCmp(value, ASC_SORT) != 0 && myStrCmp(value, DESC_SORT) != 0 && myStrCmp(value, NO_SORT) != 0);

    if (myStrCmp(value, NO_SORT) == 0) {
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

    cout << "Please enter title search query: ";
    cin.ignore(); // discard newline character

    cin.getline(value, DEFAULT_TEXT_FIELD_LENGTH);

    routeParams.searchTitle = value;
}

void searchGenreQuery(routeParamsType& routeParams) {
    if (routeParams.searchGenre) {
        delete[] routeParams.searchGenre;
    }

    char* value = new char[DEFAULT_TEXT_FIELD_LENGTH];

    cout << "Please enter genre search query: ";
    cin.ignore(); // discard newline character

    cin.getline(value, DEFAULT_TEXT_FIELD_LENGTH);

    routeParams.searchGenre = value;
}
