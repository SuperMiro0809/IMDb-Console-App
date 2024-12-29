#include <screens/moviesListScreen.h>

#include <ui-components.h>
#include <utils/consoleUtils.h>
#include <utils/stringUtils.h>
#include <colors.h>

#include <iostream>
using namespace std;

void renderMoviesListAdminScreen(userType user) {
    printScreenHeader("Movies List -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);
    
    printUserInfo(user.username, user.role);
    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(SUCCESS_COLOR);
    cout << "1. Search movie by title" << endl;
    cout << "2. Search movie by genre" << endl;
    cout << "3. Rate a movie" << endl;
    cout << "4. Sort movies by rating" << endl;
    cout << "5. Sort movies by title" << endl;
    cout << "6. Filter movies by rating" << endl;
    cout << "7. Exit" << endl;
    resetConsoleColor();
}



void renderMoviesListUserScreen(userType user) {
    printScreenHeader("Movies List -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    printUserInfo(user.username, user.role);
    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(SUCCESS_COLOR);
    cout << "1. Search movie by title" << endl;
    cout << "2. Search movie by genre" << endl;
    cout << "3. Rate a movie" << endl;
    cout << "4. Sort movies by rating" << endl;
    cout << "5. Sort movies by title" << endl;
    cout << "6. Filter movies by rating" << endl;
    cout << "7. Exit" << endl;
    resetConsoleColor();
}

void renderMoviesListScreen(userType user) {
    int userRoleCmp = myStrCmp(user.role, "User");
    int adminRoleCmp = myStrCmp(user.role, "Admin");

    if (userRoleCmp == 0) {
        renderMoviesListUserScreen(user);
    } else if (adminRoleCmp == 0) {
        renderMoviesListAdminScreen(user);
    } else {
        // Unathorized
    }
}