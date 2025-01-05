#include <screens/moviesListUserScreen.h>

#include <ui-components.h>
#include <utils/consoleUtils.h>
#include <colors.h>
#include <routes.h>

#include <iostream>
using namespace std;

int actionMoviesListUserScreen() {
    int operation;

    do {
        cin >> operation;
    } while (operation < SEARCH_TITLE_OPERATION || operation > LOGOUT_OPERATION);

    switch (operation) {
        default:
            return EXIT;
    }
}

int renderMoviesListUserScreen(userType user, routeParamsType& routeParams) {
    printScreenHeader("Movies List -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    printUserInfo(user.username, user.role);
    printScreenDivider();
    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(SUCCESS_COLOR);
    cout << SEARCH_TITLE_OPERATION << ". Search movie by title" << endl;
    cout << SEARCH_GENRE_OPERATION << ". Search movie by genre" << endl;
    cout << RATE_OPERATION << ". Rate a movie" << endl;
    cout << SORT_RATING_OPERATION << ". Sort movies by rating" << endl;
    cout << SORT_TITLE_OPERATION << ". Sort movies by title" << endl;
    cout << FILTER_RATING_OPERATION << ". Filter movies by rating" << endl;
    cout << LOGOUT_OPERATION << ". Logout" << endl;
    resetConsoleColor();

    return actionMoviesListUserScreen();
}