#include <utils/moviesUtils.h>

#include <utils/stringUtils.h>
#include <utils/routeParamsUtils.h>

void sortMoviesByTitle(movieType* movies, int movieCount, const char* direction) {
    if (!movies || !direction) {
        return;
    }

    // bubble sort
    for (int i = 0; i < movieCount - 1; i++) {
        for (int j = 0; j < movieCount - i - 1; j++) {
            int result = myStrCmp(movies[j].title, movies[j + 1].title);

            if ((myStrCmp(direction, ASC_SORT) == 0 && result > 0) || 
                (myStrCmp(direction, DESC_SORT) == 0 && result < 0)) {
                movieType temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}
