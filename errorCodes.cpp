#include <errorCodes.h>

#include <ui-components.h>
#include <colors.h>

void printError(int errorCode) {

    switch (errorCode) {
        case LOGIN_FAILED:
            printScreenText("Wrong username or password. Please, try again.", ERROR_COLOR);
            break;
        case USER_ALREDY_EXISTS:
            printScreenText("There is a already a user, registerd with that username. Please, try again.", ERROR_COLOR);
            break;
        case PASSWORDS_NOT_MATCH:
            printScreenText("The two passwords don't match. Please, try again.", ERROR_COLOR);
            break;
        case MOVIE_NOT_FOUND:
            printScreenText("Movie with such id or title wasn't found. Please, try again.", ERROR_COLOR);
            break;
        case INVALID_RATING:
            printScreenText("You entered invalid rating value. Please, try again.", ERROR_COLOR);
            break;
    }
}