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
* <Movies List Screen>
*
*/

#include <screens/moviesListScreen.h>

#include <screens/moviesListUserScreen.h>
#include <screens/moviesListAdminScreen.h>
#include <utils/stringUtils.h>

int renderMoviesListScreen(userType& user, routeParamsType& routeParams) {
    int userRoleCmp = myStrCmp(user.role, "User");
    int adminRoleCmp = myStrCmp(user.role, "Admin");

    if (userRoleCmp == 0) {
        return renderMoviesListUserScreen(user, routeParams);
    } else if (adminRoleCmp == 0) {
        return renderMoviesListAdminScreen(user, routeParams);
    }
    
    // Unathorized
    return -1;
}