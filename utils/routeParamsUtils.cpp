#include <utils/routeParamsUtils.h>

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
        cout << "Please type how you want to sort? "
             << "< " << ASC_SORT << " | "
             << DESC_SORT << " | "
             << NO_SORT << " >:";

        if (firstTry) {
            cin.ignore();
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

void searchTitleQuery(routeParamsType& routeParams, char* value) {
    delete[] routeParams.searchTitle;
    routeParams.searchTitle;
}

void searchGenreQuery(routeParamsType& routeParams, char* value) {
    delete[] routeParams.searchGenre;
    routeParams.searchGenre;
}