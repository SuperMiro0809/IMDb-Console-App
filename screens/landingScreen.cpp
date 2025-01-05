#include <screens/landingScreen.h>

#include <ui-components.h>
#include <utils/consoleUtils.h>
#include <routes.h>
#include <colors.h>

#include <iostream>
using namespace std;

int actionLandingScreen() {
    int operation;

    do {
        cin >> operation;
    } while (operation < 0 || operation > 3);

    switch (operation) {
        case LOGIN_OPERATION:
            return LOGIN_PAGE;
        case REGISTER_OPERATION:
            return REGISTER_PAGE;
        case EXIT_OPERATION:
            return EXIT;
        default:
            return EXIT;
    }
}

int renderLandingScreen() {
    printScreenHeader("Welcome to IMDb -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    printScreenText("This is the place where you can find information about every movie in the universe.");
    printScreenDivider();

    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(SUCCESS_COLOR);
    cout << LOGIN_OPERATION << ". Already have account? Login" << endl;
    cout << REGISTER_OPERATION << ". Don't have account? Register" << endl;
    cout << EXIT_OPERATION << ". Exit" << endl;
    resetConsoleColor();

    return actionLandingScreen();
}