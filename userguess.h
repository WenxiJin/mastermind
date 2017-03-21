#ifndef USERGUESS_H
#define USERGUESS_H

#include <stdbool.h>

/*
 * @brief Gets the user's input from the console
 *
 * @param count The number of times the user tried
 *
 * @return The guess code given by the user
 */
int getUserGuess(int count);

/*
 * @brief Let the user manually break the code
 *
 * @param secret_code The secret code given by the code maker
 * @param *result a pointer to the corresponding feedback
 *
 * @return TRUE, if the user guessed the correct secret code
 *         FALSE, if the user failed
 */
bool guessByUser(int secret_code, int *result);

#endif  // USERGUESS_H
