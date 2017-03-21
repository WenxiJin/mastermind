#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <stdbool.h>

/*
 * @brief Generates feedback given a user's guess
 *
 * @param guess User's guess
 * @param secret_code The secret code
 *
 * @return Feedback is given in a format as "m * 10 + n" where
 *         m = color and position are all correct
 *         n = color is correct, but not position
 */
int feedback(int guess, int secret_code);

/*
 * @brief Checks if the guess is matching the secret code
 *
 * @param secret_code The secret code given by the codemaker
 * @param guess The guess code given by the user or machine
 * @param *result a pointer to the feedback
 *
 * @return TRUE, if the guess matches the secret code
 *         FALSE, if the guess does not match
 */
bool checkGuess(int secret_code, int guess, int *result);

#endif  // FEEDBACK_H
