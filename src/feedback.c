#include "feedback.h"

int feedback(int guess, int secret_code) {
    int a[4];
    int b[4];
    int m = 0, n = 0;
    int checkSecret[4] = {1,1,1,1};
    int checkGuess[4] = {1,1,1,1};

    for (int i = 3; i >= 0; i--) {
        a[i] = guess % 10;
        b[i] = secret_code % 10;
        guess /= 10;
        secret_code /= 10;
    }

    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i]) {
            // color and position
            m++;
            checkSecret[i] = checkGuess[i] = 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i] == b[j] && checkGuess[i] && checkSecret[j] && i != j) {
                n++;
                checkGuess[i] = checkSecret[j] = 0;
            }
        }
    }
    return m * 10 + n;
}

bool checkGuess(int secret_code, int guess, int *result) {
    if (secret_code == guess) {
        // color and position are all correct
        *result = 40;
    } else {
        // other scenario
        *result = feedback(guess, secret_code);
    }
    return *result == 40 ? true : false;
}
