#include <stdio.h>
#include <stdbool.h>
#include "machineguess.h"
#include "feedback.h"

void gussByMachine(int secret_code, bool invalidCode[]) {
    // Now let the computer to break this secret code
    int best_guess = 1122;  // Best initial guess
    int result = 0;

    printf("Trying initial guess code: %d\n", best_guess);
    while (!checkGuess(secret_code, best_guess, &result)) {
        best_guess = giveBestGuess(invalidCode ,best_guess, result);
        printf("Trying guess code: %d\n", best_guess);
    }

    printf("The secret code: %d\n", secret_code);
}

int giveBestGuess(bool invalidCode[], int previous_guess, int previous_result) {
    for (int i = 1000; i <= 9999; i++) {
        if (!invalidCode[i-1000] && feedback(previous_guess, i) != previous_result) {
            invalidCode[i-1000] = true;
        }
    }
    int i = 0;
    while (invalidCode[i]) {
        i++;
    }
    return i + 1000;
}
