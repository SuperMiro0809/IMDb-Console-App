#include <navigation.h>

#include <routes.h>
#include <screens/landingScreen.h>
#include <screens/registerScreen.h>
#include <screens/loginScreen.h>
#include <screens/moviesListScreen.h>
#include <utils/stringUtils.h>

#include <iostream>
using namespace std;

void useNavigation(int code, userType user) {
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
        case MOVIES_LIST_PAGE:
            renderMoviesListScreen(user);
            break;
        default:
            break;
    }
}