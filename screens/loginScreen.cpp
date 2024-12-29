#include <screens/loginScreen.h>

#include <ui-components.h>
#include <constants.h>
#include <authController.h>
#include <errorCodes.h>

#include <iostream>
using namespace std;

void actionLoginScreen(const char* username, const char* password, int& result) {
    if (!username || !password) {
        return;
    }
    // api login
    result = loginUser(username, password);
}

void formLoginScreen() {
    int result = 0;

    do {
        char* username = printTextField("Enter username:");
        char* password = printTextField("Enter password:");

        actionLoginScreen(username, password, result);

        delete[] username;
        delete[] password;

        if (result == LOGIN_FAILED) {
            printError(result);
        }
    } while(result == LOGIN_FAILED);

    // success
    cout << result << endl;
}

void renderLoginScreen() {
    printScreenHeader("Login to IMDb -", 93, "Internet Movie Database!", 33);

    cin.ignore(); // discard newline character

    formLoginScreen();
}