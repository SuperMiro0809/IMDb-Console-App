#include <utils/moviesUtils.h>

#include <utils/stringUtils.h>
#include <utils/routeParamsUtils.h>

void sortMoviesByTitle(movieType* movies, int moviesCount, const char* direction) {
    if (!movies || !direction) {
        return;
    }

    // bubble sort
    for (int i = 0; i < moviesCount - 1; i++) {
        for (int j = 0; j < moviesCount - i - 1; j++) {
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

void sortMoviesByRating(movieType* movies, int moviesCount, const char* direction) {
    if (!movies || !direction) {
        return;
    }

    // bubble sort
    for (int i = 0; i < moviesCount - 1; i++) {
        for (int j = 0; j < moviesCount - i - 1; j++) {
            bool shouldSwap = false;

            if (myStrCmp(direction, ASC_SORT) == 0) {
                if (movies[j].rating > movies[j + 1].rating) {
                    shouldSwap = true;
                }
            } else if (myStrCmp(direction, DESC_SORT) == 0) {
                if (movies[j].rating < movies[j + 1].rating) {
                    shouldSwap = true;
                }
            }

            if (shouldSwap) {
                movieType temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}
