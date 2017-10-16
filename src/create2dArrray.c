/*
 * =============================================================================
 *
 *       Filename:  create2dArrray.c
 *
 *    Description: Creates a 2D array from a text file with data.
 *
 *        Version:  1.0
 *        Created:  10/06/2017 12:47:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Maitski (KM), kevin.maitski@gmail.com
 *   Organization:  42
 *
 * =============================================================================
 */

#include "workout.h"

/******************************************************
**               funtion prototypes                 ***
*******************************************************/
int **create2dArray (FILE *workoutFilePtr);
static int **allocateMemoryFor2dArray (int** workoutValues);
static int **fill2dArray (int ***workoutValues, FILE *workoutFIlePtr);

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  create2dArray
 *  Description:  Creates a 2D array from a text file with data.
 * =============================================================================
 */
int	**create2dArray (FILE *workoutFilePtr)
{
	int		**workoutValues;

	workoutValues = malloc(sizeof(int*) * 10);	//creates the 2d array
	allocateMemoryFor2dArray(workoutValues);
	fill2dArray(&workoutValues, workoutFilePtr);
	fclose(workoutFilePtr);
	return (workoutValues);
}		/* -----  end of function create2dArray  ----- */


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  allocateMemoryFor2dArray
 *  Description:  Allocates enough memory for the data file.  In this case it is
 *  			  known how much data there is.
 * =============================================================================
 */
static int	**allocateMemoryFor2dArray (int** workoutValues)
{
	size_t	workout = 0;

	while (workout < 10) {
		workoutValues[workout] = malloc(sizeof(int) * 3); //gets memory for each workout
		workout++;
	}
	return (workoutValues);

}		/* -----  end of function allocateMemoryFor2dArray  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  fill2dArray
 *  Description:  Fills in the values of the array from the txt file.
 * =====================================================================================
 */
static int	**fill2dArray (int ***workoutValues, FILE *workoutFilePtr)
{
	char	*workoutStringPtr = malloc(sizeof(*workoutStringPtr) * 10);
	size_t	workout = 0;
	size_t	exercise = 0;
	size_t	i = 0;

	while (workout < 10) {
		fgets(workoutStringPtr, 9, workoutFilePtr); //gets the next line from the txt file
		/* places the values from the txt file into the 2d array */
		while (exercise < 3) {
			workoutValues[0][workout][exercise] = atoi(&workoutStringPtr[i]);
			if (workoutValues[0][workout][exercise] == 10) {
				i += 3;
			}
			else {
				i += 2;
			}
			exercise++;
		}
		i = 0;
		exercise = 0;
		workout++;
	}
	free(workoutStringPtr);
	return (workoutValues[0]);

}		/* -----  end of function fill2dArray  ----- */
