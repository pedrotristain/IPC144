/*
	 Name:      Pedro Zelada Souza
	 E-mail:	pzelada-souza@myseneca.ca
	 Student#:  116427188
	 Section:   Q
*/

#include<stdio.h> // includes C's standard input and output library
#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

int main(void) { // Starts C's main function

	double pay_amount, balance; // initialize the variables that will hold the float point values for calculation
	int loonies, quarters; // initialize the variables that will hold the integer values for calculation

	printf("\nPlease enter the amount to be paid: $"); // prompts the user to enter a numeric value
	scanf("%lf", &pay_amount); // gets the users numeric input
	
	loonies = pay_amount; // Get the integer portion of pay_amount
	balance = pay_amount - loonies; // calculates the rest of the balance that is due
	
	printf("Loonies required: %d, balance owing $%.2f", loonies, balance); // outputs the information back to the user
	
	quarters = balance / 0.25; // calculate how many quarters will be needed to pay what is due
	balance -= quarters * 0.25; // gets the balance owing after accounting for the needed quarters
	
	printf("\nQuarters required: %d, balance owing $%.2f\n", quarters, balance); // outputs the information back to the user
	
	return 0; // returns 0 to the compiler, ending the program

}
