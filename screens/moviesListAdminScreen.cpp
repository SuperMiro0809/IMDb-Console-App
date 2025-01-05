#include <screens/moviesListAdminScreen.h>

#include <ui-components.h>
#include <utils/consoleUtils.h>
#include <colors.h>
#include <routes.h>

#include <iostream>
using namespace std;

int actionMoviesListAdminScreen() {
    int operation;

    do {
        cin >> operation;
    } while (operation < ADMIN_SEARCH_TITLE_OPERATION || operation > ADMIN_LOGOUT_OPERATION);

    switch (operation) {
        case ADMIN_ADD_OPERATION:
            return MOVIES_LIST_ADD_PAGE;
        default:
            return EXIT;
    }
}

int renderMoviesListAdminScreen(userType user, routeParamsType& routeParams) {
    printScreenHeader("Movies List -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);
    
    printUserInfo(user.username, user.role);
    printScreenDivider();
    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(SUCCESS_COLOR);
    cout << ADMIN_SEARCH_TITLE_OPERATION << ". Search movie by title" << endl;
    cout << ADMIN_SEARCH_GENRE_OPERATION << ". Search movie by genre" << endl;
    cout << ADMIN_RATE_OPERATION << ". Rate a movie" << endl;
    cout << ADMIN_SORT_RATING_OPERATION << ". Sort movies by rating" << endl;
    cout << ADMIN_SORT_TITLE_OPERATION << ". Sort movies by title" << endl;
    cout << ADMIN_FILTER_RATING_OPERATION << ". Filter movies by rating" << endl;
    cout << ADMIN_ADD_OPERATION << ". Add new movie" << endl;
    cout << ADMIN_UPDATE_OPERATION << ". Update a movie" << endl;
    cout << ADMIN_DELETE_OPERATION << ". Delete a movie" << endl;
    cout << ADMIN_LOGOUT_OPERATION << ". Logout" << endl;
    resetConsoleColor();

    return actionMoviesListAdminScreen();
}