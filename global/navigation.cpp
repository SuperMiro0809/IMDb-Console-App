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
* <Application Navigation>
*
*/

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