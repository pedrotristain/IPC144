//--------------------------------------------------
// Name:           Pedro Zelada Souza
// Student Number: 116427188
// Email:          pzelada-souza@myseneca.ca
// Section:        SQQ
// Workshop:       04
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#define _MAX 10 // Defining a control constant variable

#include <stdio.h> // Include the default input and ouput controls

int main(void) {

	int high_temp[_MAX], low_temp[_MAX]; // Declaration of the arrays to store the temperatures and the days
	int track_days; // Declare the variable that will hold the number of days
	int i; // Declare the for control variable

	printf("\n---=== IPC Temperature Calculator V2.0 ===---"); // Output the header of the program

	printf("\nPlease enter the number of days, between 3 and 10, inclusive: "); // Prompts the user the enter the number of days
	scanf("%d", &track_days); // Saves the user input into the variable

	// If the user inputs an invalid value, prompt him to input again until he does a valid value.
	while (track_days > 10 || track_days < 3) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &track_days);
	}

	printf("\n"); // Output a line break (needed for this workshop)
	
	// Prompts the user a number of times as was inputed previously to the variable track_days
	for (i = 0; i < track_days; i++) {
		printf("Day %d - High: ", i + 1); // Prompts the user to enter the current day's high temperature
		scanf("%d", &high_temp[i]); // Saves the input value to the current index of the high_temp array

		printf("Day %d - Low: ", i + 1); // Prompts the user to enter the current day's low temperature
		scanf("%d", &low_temp[i]); // Saves the input value to the current index of the low_temp array
	}

	printf("\n\nDay\tHi\tLow"); // Ouput the header for the following part

	// Display all the values inputed by the user in a formatted table
	for (i = 0; i < track_days; i++) {
		printf("\n%d\t%d\t%d", track_days + 1, high_temp[i], low_temp[i]); // Output the current day, it's high temperature and it's low temperature
	}

	printf("\n"); // Ouputs a line break (for style)

	return 0; // Return the default value to the compiler and end the program
}