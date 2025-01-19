#include <global/navigation.h>

#include <global/routes.h>
#include <screens/landingScreen.h>
#include <screens/registerScreen.h>
#include <screens/loginScreen.h>
#include <screens/moviesListScreen.h>
#include <screens/moviesListAddScreen.h>
#include <utils/stringUtils.h>

#include <iostream>
using namespace std;

int useNavigation(int code, userType& user, routeParamsType& routeParams) {
    cout << "Navigation..." << endl;

    switch (code) {
        case LANDING_PAGE:
            return renderLandingScreen();
        case REGISTER_PAGE:
            return renderRegisterScreen(user);
        case LOGIN_PAGE:
            return renderLoginScreen(user);
        case MOVIES_LIST_PAGE:
            return renderMoviesListScreen(user, routeParams);
        case MOVIES_LIST_ADD_PAGE:
            return renderMoviesListAddScreen();
        default:
            return EXIT; // Exit code
    }
}