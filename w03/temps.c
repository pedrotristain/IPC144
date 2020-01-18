// Name: Pedro Zelada Souza
// Student Number: 116427188
// Email: pzelada-souza@myseneca.ca
// Section: Q
// Workshop: 03

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3

#include <stdio.h>

// Initialize the program
int main(void)
{
	int day, low, high; // Declare the integer variables for the for loop, the low temperature and high temperature
	int sum_low_temp = 0, sum_high_temp = 0; // Declare the integer variables for the for the sum of the temperatures
	double mean_temperature; // Declare an double to hold the average temperature

	printf("\n---=== IPC Temperature Analyzer ===---"); // 

	for (day = 0; day < NUMS; day++)
	{
		printf("\nEnter the high value for day %d: ", day + 1); // Prompts the user to input the HIGH temperature
		scanf("%d", &high); // Saves the user input in the HIGH temperature's variable

		printf("\nEnter the low value for day %d: ", day + 1); // Prompts the user to input the LOW temperature
		scanf("%d", &low); // Saves the user input in the LOW temperature's variable

		/* 
			If the user inputs a value lower than -40 or higher then 40
			Or if it inputs a LOW temperature that is higher than the HIGH temperature
			Prompt the user to input the values again, until he inputs acceptable values
		*/
		while ( (low < -40 || low > 40) || (high < -40 || high > 40) || low > high )
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

			printf("\nEnter the high value for day %d: ", day + 1); // Prompts the user to input the HIGH temperature
			scanf("%d", &high); // Saves the user input in the HIGH temperature's variable

			printf("\nEnter the low value for day %d: ", day + 1); // Prompts the user to input the LOW temperature
			scanf("%d", &low); // Saves the user input in the LOW temperature's variable

		} 
		
		sum_low_temp += low; // Add the low temperatures together to use them to calculate the mean temperature
		sum_high_temp += high; // Add the high temperatures together to use them to calculate the mean temperature
		
	}

	mean_temperature = (double) (sum_high_temp + sum_low_temp) / (NUMS * 2); // Calculates the mean temperature
	
	printf("\nThe average (mean) temperature was: %1.2lf\n", mean_temperature); // Outputs the mean temperature back to the user

	return 0; // Returns the default value to the compiler and ends the program
}