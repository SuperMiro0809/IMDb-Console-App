#include <screens/landingScreen.h>

#include <ui-components.h>
#include <utils/consoleUtils.h>
#include <navigation.h>
#include <routes.h>
#include <colors.h>

#include <iostream>
using namespace std;

void actionLandingScreen() {
    int operation;

    do {
        cin >> operation;
    } while (operation < 0 || operation > 3);

    switch (operation) {
        case LOGIN_OPERATION:
            useNavigation(LOGIN_PAGE);
            break;
        case REGISTER_OPERATION:
            useNavigation(REGISTER_PAGE);
            break;
        case EXIT_OPERATION:
            exit(0);
            break;
    }
}

void renderLandingScreen() {
    printScreenHeader("Welcome to IMDb -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    printScreenText("This is the place where you can find information about every movie in the universe.");
    printScreenDivider();

    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(SUCCESS_COLOR);
    cout << LOGIN_OPERATION << ". Already have account? Login" << endl;
    cout << REGISTER_OPERATION << ". Don't have account? Register" << endl;
    cout << EXIT_OPERATION << ". Exit" << endl;
    resetConsoleColor();

    actionLandingScreen();
}