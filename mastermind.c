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

    // Ask for giving a secret code
    while (secret_code < 1000 || secret_code > 9999) {
        char *p = NULL;
        p = getpass("Enter 4-digit secret code: ");
        secret_code = strtol(p, NULL, 10);
    }

    if (guessByUser(secret_code, &result)) {
        return 0;
    }
    printf("You failed at breaking the code :(\n\n");

    gussByMachine(secret_code, invalidCode);

    return 0;
}
