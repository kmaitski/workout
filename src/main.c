/*
 * =============================================================================
 *       Filename:  main.c
 *
 *    Description:  This program records your workout and spits out the next
 *    				recommended workout.
 *
 *        Version:  1.0
 *        Created:  09/19/2017 13:55:03
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
static void printWorkout(int **workoutValues);
static void constructNextWorkout(int ***workoutValues);
static void writeNextWorkoutToFile(int **workoutValues);

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  main
 *  Description: The main will open the files print todays workout 
 * =============================================================================
 */
int	main(int argc, char **argv)
{
	FILE	*workoutFilePtr = fopen("doc/workout.txt", "r");
	int		**workoutValues = create2dArray(workoutFilePtr);
	size_t	workout = 0;

	if (argc == 2) {
		if (argv[1][0] == 't' || argv[1][0] == 'T') {  //If we just want to print
			printWorkout(workoutValues);
		}
		if (argv[1][0] == 'd' || argv[1][0] == 'D') { //Runs once the workout is complete
			constructNextWorkout(&workoutValues); //Increaes the difficulty of the workout
			writeNextWorkoutToFile(workoutValues);
		}
	}
	while (workout < 10) {
		free(workoutValues[workout]);
		workout++;
	}
	free(workoutValues);
}

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  printWorkout
 *  Description:  Prints the workout.
 * =============================================================================
 */
static void	printWorkout(int **workoutValues)
{
	size_t	workout = 0;

	while (workoutValues[workout][0] != 0) { //Loop that prints as long as there is value to print
		printf("Workout %lu is %i squats, %i pushups, and %i pullups\n", workout + 1, workoutValues[workout][0], workoutValues[workout][1], workoutValues[workout][2]);
		workout++;
	}
}		/* -----  end of function printWorkout  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  constructNextWorkout
 *  Description:  Increases the difficulty by adding one to the same workout if
 *  			  an exercise is not equal with the other exercise in the
 *  			  workout or adds to a new workout if the the first workout is
 *  			  equal and above higher than 1 exercise above the next workout.
 * =====================================================================================
 */
static void	constructNextWorkout(int ***workoutValues)
{
	int	workout = 0;

	while (workout < 10){ //checks to see if all the exercise on the same workout are even and if not adds one to equal them out
		if (workoutValues[0][workout][0] != workoutValues[0][workout][1]) {
			workoutValues[0][workout][1] += 1;
			return;
		}
		if (workoutValues[0][workout][0] != workoutValues[0][workout][2]) {
			workoutValues[0][workout][2] += 1;
			return;
		}
		++workout;
	}
	--workout;
	while (workout) { //checks to see if it is possible to add one to a later workout (the differnce between the first exericse of each workout must be 2
		if ((workoutValues[0][workout - 1][0] - workoutValues[0][workout][0]) == 2) {
			workoutValues[0][workout][0] += 1;
			return;
		}
		--workout;
	}

	workoutValues[0][0][0] += 1; //If all else fails add one to the first exercise on the first workout
}		/* -----  end of function constructNextWorkout  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  writeNextWorkoutToFile
 *  Description:  Writes the next workout to the workout txt file.
 * =====================================================================================
 */
static void	writeNextWorkoutToFile(int **workoutValues)
{
	size_t	workout = 0;
	size_t	exercise = 0;
	FILE	*workoutFilePtr = fopen("doc/workout.txt", "w");

	while (workout < 10) {
		while (exercise < 3) {
			fprintf(workoutFilePtr, "%i ", workoutValues[workout][exercise]);
			exercise++;
		}
		fprintf(workoutFilePtr, "\n");
		exercise = 0;
		workout++;
	}
	fclose(workoutFilePtr);
}		/* -----  end of function writeNextWorkoutToFile  ----- */
