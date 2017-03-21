#include <stdio.h>
#include "userguess.h"
#include "feedback.h"

int getUserGuess(int count) {
    int code = 0;
    printf("%d. Enter 4-digit guess code: ", count+1);

    while (code < 1000 || code > 9999) {
        if (scanf("%d", &code) == 0 || code < 1000 || code > 9999) {
            {
                // consume all the dirty charactar
                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }
            code = 0;
            printf("Invalid code!\n");
            printf("%d. Enter 4-digit guess code: ", count+1);
        }
    }
    return code;
}

bool guessByUser(int secret_code, int *result) {
    int try_count = 0;
    const int MAX_TRY = 8;
    // Now let the user to break this secret code
    while (try_count < MAX_TRY) {
        int user_guess = getUserGuess(try_count);
        if (checkGuess(secret_code, user_guess, result)) {
            printf("Congratulations! You break the secret code: %d\n", secret_code);
            return true;
        }
        printf("=========> %02d\n", *result);
        try_count++;
    }
    return false;
}
