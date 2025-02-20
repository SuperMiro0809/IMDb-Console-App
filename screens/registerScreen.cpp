/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
*
* @author Miroslav Balev
* @idnumber 9MI0600470
* @compiler GCC
*
* <Register Screen>
*
*/

#include <screens/registerScreen.h>

#include <controllers/authController.h>
#include <global/uiComponents.h>
#include <global/constants.h>
#include <global/errorCodes.h>
#include <global/routes.h>
#include <global/colors.h>

#include <iostream>
using namespace std;

void actionRegisterPage(const char* username, const char* password, const char* repeatPassword, int& result) {
    if (!username || !password || !repeatPassword) {
        return;
    }

    // api register
    result = registerUser(username, password, repeatPassword);
}

int formRegisterPage(userType& user) {
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
    user = getUserById(result);

    // navigate to Movies List
    return MOVIES_LIST_PAGE;
}

int renderRegisterScreen(userType& user) {
    printScreenHeader("Register to IMDb -", PRIMARY_YELLOW_COLOR, "Internet Movie Database!", SECONDARY_YELLOW_COLOR);

    cin.ignore(); // discard newline character

    return formRegisterPage(user);
}