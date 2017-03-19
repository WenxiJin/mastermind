#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define bool int
#define true 1
#define false 0

bool guessByUser(int secret_code, int *result);
int getUserGuess(int count);

void gussByMachine(int secret_code, bool hasCodeTried[]);

bool checkGuess(int secret_code, int guess, int *result);
int giveBestGuess(bool hasCodeTried[], int previous_guess, int previous_result);
int compare(int secret_code, int guess);


// ************************************************************************
int main(int argc, char *argv[]) {
  int secret_code = 0;
  int result = 0;
  bool hasCodeTried[9000] = {false};  // we need to keep track on the code we
                                      // have tried and we can eliminate

  // Ask for giving a secret code
  while (secret_code < 1000 || secret_code > 9999) {
    char *p = NULL;
    p = getpass("Enter 4-digit secret code: ");
    secret_code = atoi(p);
  }

  if (guessByUser(secret_code, &result)) {
    return 0;
  }
  printf("You failed at breaking the code :(\n\n");

  gussByMachine(secret_code, hasCodeTried);

  return 0;
}

// ************************************************************************
bool checkGuess(int secret_code, int guess, int *result) {
  if (secret_code == guess) {
    // color and position are all correct
    *result = 40;
  } else {
    // other scenario
    *result = compare(secret_code, guess);
  }
  return *result == 40 ? true : false;
}

int giveBestGuess(bool hasCodeTried[], int previous_guess, int previous_result) {
  for (int i = 1000; i <= 9999; i++) {
    if (!hasCodeTried[i-1000] && compare(i , previous_guess) != previous_result) {
      hasCodeTried[i-1000] = true;
    }
  }

  int i = 0;
  while (hasCodeTried[i]) {
    i++;
  }
  return i + 1000;
}

int compare(int secret_code, int guess) {
  int a[4];
  int b[4];
  int m = 0, n = 0;

  for (int i = 3; i >= 0; i--) {
    a[i] = guess % 10;
    b[i] = secret_code % 10;
    guess /= 10;
    secret_code /= 10;
  }

  for (int i = 0; i < 4; i++) {
    if (a[i] == b[i]) {  // color && position
      m++;
      continue;
    }
    for (int j = 0; j < 4; j++) {
      if (a[i] == b[j]) {  // color only
        n++;
        break;
      }
    }
  }
  return m * 10 + n;
}

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
    printf("---------> %d\n", *result);
    try_count++;
  }
  return false;
}

void gussByMachine(int secret_code, bool hasCodeTried[]) {
  // Now let the computer to break this secret code
  int best_guess = 1122;  // Best initial guess
  int result = 0;

  printf("Trying initial guess with code: %d\n", best_guess);
  while (!checkGuess(secret_code, best_guess, &result)) {
    best_guess = giveBestGuess(hasCodeTried ,best_guess, result);
    printf("Trying guess with code: %d\n", best_guess);
  }

  printf("The secret code: %d\n", secret_code);
}