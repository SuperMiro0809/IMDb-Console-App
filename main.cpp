#include <navigation.h>
#include <routes.h>
#include <types.h>

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

    while (currentPage != EXIT) {
        currentPage = useNavigation(currentPage, user);
    }
}