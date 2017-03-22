#ifndef MACHINEGUESS_H
#define MACHINEGUESS_H

/*
 * @brief Let machine do the trick
 *
 * @param secret_code The secret code given by the code maker
 * @param invalidCode[] A code set holding all the rulled out codes
 *
 * @return No return
 */
void gussByMachine(int secret_code, bool invalidCode[]);


/*
 * @brief Simple algorithm to give the next best guess
 *
 * @param invalidCode[] A code set holding all the rulled out codes
 * @param previous_guess The previous guess made by machine
 * @param previous_result The feedback of the previous guess
 *
 * @return The next best guess
 */
int giveBestGuess(bool invalidCode[], int previous_guess, int previous_result);

#endif  // MACHINEGUESS_H
