#include <errorCodes.h>

#include <ui-components.h>

void printError(int errorCode) {

    switch (errorCode) {
        case LOGIN_FAILED:
            printScreenText("Wrong username or password. Please, try again.", 91);
            break;
        case USER_ALREDY_EXISTS:
            printScreenText("There is a already a user, registerd with that username. Please, try again.", 91);
            break;
        case PASSWORDS_NOT_MATCH:
            printScreenText("The two passwords don't match. Please, try again.", 91);
            break;
    }
}