#include <iostream>
#include <ui-components.h>
#include <console-utils.h>
using namespace std;

void printLandingScreen() {
    printScreenHeader("Welcome to IMDb -", 93, "Internet Movie Database!", 33);

    printScreenText("This is the place where you can find information about every movie in the universe.");
    printScreenDivider();

    printScreenText("Please sellect how you want to procceed:");

    setConsoleColor(32);
    cout << "1. Already have account? Login" << endl;
    cout << "2. Don't have account? Register" << endl;
    cout << "3. Exit" << endl;
    resetConsoleColor();
}