#include <screens/moviesListScreen.h>

#include <screens/moviesListUserScreen.h>
#include <screens/moviesListAdminScreen.h>
#include <utils/stringUtils.h>

int renderMoviesListScreen(userType user) {
    int userRoleCmp = myStrCmp(user.role, "User");
    int adminRoleCmp = myStrCmp(user.role, "Admin");

    if (userRoleCmp == 0) {
        return renderMoviesListUserScreen(user);
    } else if (adminRoleCmp == 0) {
        return renderMoviesListAdminScreen(user);
    } else {
        // Unathorized
        return -1;
    }
}