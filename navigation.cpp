#include <navigation.h>

#include <routes.h>
#include <screens/landingScreen.h>
#include <screens/registerScreen.h>
#include <screens/loginScreen.h>

#include <iostream>
using namespace std;

void useNavigation(int code) {
    cout << "Navigation..." << endl;

    switch (code) {
        case LANDING_PAGE:
            renderLandingScreen();
            break;
        case REGISTER_PAGE:
            renderRegisterScreen();
            break;
        case LOGIN_PAGE:
            renderLoginScreen();
            break;
        default:
            break;
    }
}