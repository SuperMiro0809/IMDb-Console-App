#include <global/navigation.h>
#include <global/routes.h>
#include <global/types.h>

void runApplication(userType& user);

int main() {
    // add global user session store
    userType currentUser = GUEST;

    // pass the session to every component
    runApplication(currentUser);

    return 0;
}

void runApplication(userType& user) {
    int currentPage = LANDING_PAGE; // start at the landing page

    routeParamsType routeParams = INITIAL_ROUTE_PARAMS; // start with initial route params

    while (currentPage != EXIT) {
        currentPage = useNavigation(currentPage, user, routeParams);
    }
}