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