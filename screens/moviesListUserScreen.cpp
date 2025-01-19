#include <screens/moviesListUserScreen.h>

#include <global/uiComponents.h>
#include <global/colors.h>
#include <global/routes.h>
#include <global/appOperations.h>
#include <utils/consoleUtils.h>
#include <utils/routeParamsUtils.h>
#include <utils/moviesListUtils.h>
#include <controllers/moviesController.h>
#include <controllers/authController.h>

#include <iostream>
using namespace std;

int actionMoviesListUserScreen(userType& user, routeParamsType& routeParams) {
    int operation;

    do {
        cin >> operation;
    } while (operation < SEARCH_TITLE_OPERATION || operation > USER_LOGOUT_OPERATION);

    switch (operation) {
        case SEARCH_TITLE_OPERATION:
            searchTitleQuery(routeParams);
            return MOVIES_LIST_PAGE;
        case SEARCH_GENRE_OPERATION:
            searchGenreQuery(routeParams);
            return MOVIES_LIST_PAGE;
        case RATE_OPERATION:
            rateMovieAction(user.id);
            return MOVIES_LIST_PAGE;
        case SORT_RATING_OPERATION:
            sortRatingQuery(routeParams);
            return MOVIES_LIST_PAGE;
        case SORT_TITLE_OPERATION:
            sortTitleQuery(routeParams);
            return MOVIES_LIST_PAGE;
        case FILTER_RATING_OPERATION:
            filterRatingQuery(routeParams);
            return MOVIES_LIST_PAGE;
        case USER_LOGOUT_OPERATION:
            logoutUser(user);
            return LANDING_PAGE;
        default:
            return EXIT;
    }
}

int renderMoviesListUserScreen(userType& user, routeParamsType& routeParams) {
    printScreenHeader("Movies List -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    printUserInfo(user.username, user.role);
    printScreenDivider();

    printRouteParams(routeParams);

    movieType* movies = getMovies(routeParams);
    int moviesCount = getMoviesCount(routeParams);

    printMoviesTable(movies, moviesCount);

    // free up memory used by movies
    freeUpMoviesSpace(movies, moviesCount);

    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(SUCCESS_COLOR);
    cout << SEARCH_TITLE_OPERATION << ". Search movie by title" << endl;
    cout << SEARCH_GENRE_OPERATION << ". Search movie by genre" << endl;
    cout << RATE_OPERATION << ". Rate a movie" << endl;
    cout << SORT_RATING_OPERATION << ". Sort movies by rating" << endl;
    cout << SORT_TITLE_OPERATION << ". Sort movies by title" << endl;
    cout << FILTER_RATING_OPERATION << ". Filter movies by rating" << endl;
    cout << USER_LOGOUT_OPERATION << ". Logout" << endl;
    resetConsoleColor();

    return actionMoviesListUserScreen(user, routeParams);
}