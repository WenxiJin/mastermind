#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "feedback.h"
#include "userguess.h"
#include "machineguess.h"

// *********************************************************************
int main(int argc, char *argv[]) {
    int secret_code = 0;
    int result = 0;
    // we need to keep track on the code we
    // have tried and we can eliminate
    bool invalidCode[9000] = {false};  // 1000...9999 => 9000

    printf("\n********************************************************\n");
    printf(  "**                Welcome to MasterMind               **\n");
    printf(  "********************************************************\n\n");

    // Ask for giving a secret code
    while (secret_code < 1000 || secret_code > 9999) {
        char *p = NULL;
        p = getpass("Enter 4-digit secret code [1000~9999]: ");
        secret_code = strtol(p, NULL, 10);
        if (secret_code < 1000 || secret_code > 9999) {
            printf("Invalid secret code, valid range [1000~9999]\n");
        } else {
            break;
        }
    }

    if (guessByUser(secret_code, &result)) {
        return 0;
    }
    printf("Unfortunately. You did not break the secret code :(\n\n");
    printf("********************************************************\n\n");
    printf("Now machine is guessing ...\n");
    gussByMachine(secret_code, invalidCode);

    return 0;
}
