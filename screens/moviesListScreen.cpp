#include <screens/moviesListScreen.h>

#include <ui-components.h>
#include <utils/consoleUtils.h>
#include <utils/stringUtils.h>

#include <iostream>
using namespace std;

void renderMoviesListAdminScreen() {
    printScreenHeader("Movies List -", 93, "Internet Movie Database!", 33);
    
    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(32);
    cout << "1. Search movie by title" << endl;
    cout << "2. Search movie by genre" << endl;
    cout << "3. Rate a movie" << endl;
    cout << "4. Sort movies by rating" << endl;
    cout << "5. Sort movies by title" << endl;
    cout << "6. Filter movies by rating" << endl;
    cout << "7. Exit" << endl;
    resetConsoleColor();
}



void renderMoviesListUserScreen() {
    printScreenHeader("Movies List -", 93, "Internet Movie Database!", 33);

    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(32);
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
        renderMoviesListUserScreen();
    } else if (adminRoleCmp == 0) {
        renderMoviesListAdminScreen();
    } else {
        // Unathorized
    }
}