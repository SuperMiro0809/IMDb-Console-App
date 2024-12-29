#include <screens/registerScreen.h>

#include <ui-components.h>
#include <constants.h>
#include <authController.h>
#include <errorCodes.h>

#include <iostream>
using namespace std;

void actionRegisterPage(const char* username, const char* password, const char* repeatPassword, int& result) {
    if (!username || !password || !repeatPassword) {
        return;
    }

    // api register
    result = registerUser(username, password, repeatPassword);
}

void formRegisterPage() {
    int result = 0;

    do {
        char* username = printTextField("Enter username:");
        char* password = printTextField("Enter password:");
        char* repeatPassword = printTextField("Repeat password:");

        actionRegisterPage(username, password, repeatPassword, result);

        delete[] username;
        delete[] password;
        delete[] repeatPassword;

        if (result == PASSWORDS_NOT_MATCH || result == USER_ALREDY_EXISTS) {
            printError(result);
        }
    } while (result == PASSWORDS_NOT_MATCH || result == USER_ALREDY_EXISTS);

    // success
}

void renderRegisterScreen() {
    printScreenHeader("Register to IMDb -", 93, "Internet Movie Database!", 33);

    cin.ignore(); // discard newline character

    formRegisterPage();
}