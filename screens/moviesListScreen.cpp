#include <screens/moviesListScreen.h>

#include <screens/moviesListUserScreen.h>
#include <screens/moviesListAdminScreen.h>
#include <utils/stringUtils.h>

void renderMoviesListScreen(userType user) {
    int userRoleCmp = myStrCmp(user.role, "User");
    int adminRoleCmp = myStrCmp(user.role, "Admin");

    if (userRoleCmp == 0) {
        renderMoviesListUserScreen(user);
    } else if (adminRoleCmp == 0) {
        renderMoviesListAdminScreen(user);
    } else {
        // Unathorized
    }
}