/*
 * =============================================================================
 *
 *       Filename:  workout.h
 *
 *    Description:  Header file for workout program
 *
 *        Version:  1.0
 *        Created:  10/06/2017 12:57:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Maitski (KM), kevin.maitski@gmail.com
 *   Organization:  42
 *
 * =============================================================================
 */

#ifndef WORKOUT_H
# define WORKOUT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main(int argc, char **argv);
int **create2dArray(FILE *workoutFilePtr);

#endif
