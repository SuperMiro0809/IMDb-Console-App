#include <screens/loginScreen.h>

#include <controllers/authController.h>
#include <global/uiComponents.h>
#include <global/constants.h>
#include <global/errorCodes.h>
#include <global/routes.h>
#include <global/colors.h>

#include <iostream>
using namespace std;

void actionLoginScreen(const char* username, const char* password, int& result) {
    if (!username || !password) {
        return;
    }
    // api login
    result = loginUser(username, password);
}

int formLoginScreen(userType& user) {
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
    user = getUserById(result);

    // navigate to Movies List
    return MOVIES_LIST_PAGE;
}

int renderLoginScreen(userType& user) {
    printScreenHeader("Login to IMDb -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    cin.ignore(); // discard newline character

    return formLoginScreen(user);
}