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
	int highest_temp, lowest_temp, highest_day, lowest_day; // Declare the variables to hold the extremest temperatures and the day they happened
	int mean_counter; // Declare the variable that will hold the amount of days to calculate the mean temperature
	int high = 0, low = 0; // Declare and Initialize the variables used to calculate the mean temperature
	int i; // Declare the for control variable

	float mean_temperature; // Declare a variable to hold the mean temperature after calculation

	highest_temp = -32767; // Initialize the variable to get rid of trash values and ensure the user can override it
	lowest_temp = 32768; // Initialize the variable to get rid of trash values and ensure the user can override it

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

		// Verify if the inputed temperature is higher than the previous saved highest temperature
		if (high_temp[i] > highest_temp) {
			highest_temp = high_temp[i]; // Saves the new highest temperature
			highest_day = i + 1; // Saves the day of the highest tempearture
		}

		// Verify if the inputed temperature is lower than the previous saved lowest temperature
		if (low_temp[i] < lowest_temp) {
			lowest_temp = low_temp[i]; // Saves the new lowest temperature
			lowest_day = i + 1; // Saves the day of the lowest tempearture
		}
	}

	printf("\nDay  Hi  Low"); // Ouput the header for the following part

	// Display all the values inputed by the user in a formatted table
	for (i = 0; i < track_days; i++) {
		printf("\n%d    %d    %d", i + 1, high_temp[i], low_temp[i]); // Output the current day, it's high temperature and it's low temperature
	}

	printf("\n\nThe highest temperature was %d, on day %d", highest_temp, highest_day); // Outputs the highest temperature and the day it occurred
	printf("\nThe lowest temperature was %d, on day %d\n", lowest_temp, lowest_day); // Outputs the lowest temperature and the day it occurred

	// Prompts the user to input a day range to calculate the average temperature until he inputs a negative value. If he does, finish the program
	do {
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", track_days); // Prompts the user to enter a number between 1 and the previously inputed track_days
		scanf("%d", &mean_counter); // Saves the user input into the variable

		// If the user inputs an invalid value, prompt him to input again until he does input a valid value.
		while (mean_counter > track_days || mean_counter == 0) {
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", track_days); // Prompts the user to input a valid value
			scanf("%d", &mean_counter); // Saves the input into the variable
		}

		// If the user inputs a valid input that is not negative, calculate the average temperature. Otherwise, skip this part
		if( mean_counter > 0 ) {
			
			// Reset the variables used in the calculation of the mean temperature
			high = 0;
			low = 0;
		
			// Get the temperature values to calculate the average
			for (i = 0; i < mean_counter; i++) {
				high += high_temp[i];
				low += low_temp[i];
			}

			mean_temperature = (float) (high + low) / (mean_counter * 2); // Calculates the mean temperature
		
			printf("\nThe average temperature up to day %d is: %1.2f", mean_counter, mean_temperature); // Outputs the mean temperature
			printf("\n"); // Ouputs a line break (for style)
		}

	} while (mean_counter > -1); // While the user inputs a number that is not negative, repeat the process

	printf("\nGoodbye!\n"); // Ouputs the ending message to the user

	return 0; // Return the default value to the compiler and end the program
}
