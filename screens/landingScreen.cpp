#include <screens/landingScreen.h>

#include <ui-components.h>
#include <console-utils.h>
#include <navigation.h>
#include <routes.h>

#include <iostream>
using namespace std;

void actionLandingScreen() {
    int operation;

    do {
        cin >> operation;
    } while (operation < 0 || operation > 3);

    switch (operation) {
        case 1:
            useNavigation(LOGIN_PAGE);
            break;
        case 2:
            useNavigation(REGISTER_PAGE);
            break;
        case 3:
            exit(0);
            break;
    }
}

void renderLandingScreen() {
    printScreenHeader("Welcome to IMDb -", 93, "Internet Movie Database!", 33);

    printScreenText("This is the place where you can find information about every movie in the universe.");
    printScreenDivider();

    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(32);
    cout << "1. Already have account? Login" << endl;
    cout << "2. Don't have account? Register" << endl;
    cout << "3. Exit" << endl;
    resetConsoleColor();

    actionLandingScreen();
}