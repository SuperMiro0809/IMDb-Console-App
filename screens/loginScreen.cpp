#include <screens/loginScreen.h>

#include <ui-components.h>
#include <constants.h>
#include <controllers/authController.h>
#include <errorCodes.h>
#include <routes.h>
#include <navigation.h>
#include <colors.h>

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
    userType user = getUserById(result);

    useNavigation(MOVIES_LIST_PAGE, user);
}

void renderLoginScreen() {
    printScreenHeader("Login to IMDb -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    cin.ignore(); // discard newline character

    formLoginScreen();
}