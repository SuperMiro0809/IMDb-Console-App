#include <navigation.h>

#include <routes.h>
#include <screens/landingScreen.h>
#include <screens/registerScreen.h>
#include <screens/loginScreen.h>
#include <screens/moviesListScreen.h>
#include <screens/moviesListAddScreen.h>
#include <utils/stringUtils.h>

#include <iostream>
using namespace std;

int useNavigation(int code, userType& user) {
    cout << "Navigation..." << endl;

    switch (code) {
        case LANDING_PAGE:
            return renderLandingScreen();
        case REGISTER_PAGE:
            return renderRegisterScreen(user);
        case LOGIN_PAGE:
            return renderLoginScreen(user);
        // case MOVIES_LIST_PAGE:
        //     return renderMoviesListScreen(user);
        //     break;
        // case MOVIES_LIST_ADD_PAGE:
        //     return renderMoviesListAddScreen();
        //     break;
        default:
            return EXIT; // Exit code
    }
}