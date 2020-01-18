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

	double pay_amount, balance, gst; // initialize the variables that will hold the float point values for calculation
	int loonies, quarters, amount_due, dimes, nickels, pennies; // initialize the variables that will hold the integer values for calculation

	printf("\nPlease enter the amount to be paid: $"); // prompts the user to enter a numeric value
	scanf("%lf", &pay_amount); // gets the users numeric input

	gst = pay_amount * .13 + .005; // calculates the gst amount over the owing value
	balance = pay_amount + gst; // calculates the amount due by adding the user input with the gst

	printf("GST: %.2f", gst); // outputs the GST value to the user
	printf("\nBalance owing: $%1.2f", balance); // outputs the paying amount that is due to the user

	loonies = (int) balance; // Get the integer portion of pay_amount that equals the number of loonies
	balance -= loonies; // calculates the rest of the balance that is due

	balance = (balance + .005) * 100; // prepares the balance to be saved as integer
	amount_due = (int) balance; // gets the decimal part of the amount due and saves it as an integer
	
	printf("\nLoonies required: %d, balance owing $%1.2f", loonies, (float) amount_due / 100); // outputs the amount of loonies and the new balance to the user

	quarters = amount_due / 25; // calculate how many quarters will be needed to pay what is due
	amount_due %= 25; // gets the balance owing after accounting for the needed quarters
	
	printf("\nQuarters required: %d, balance owing $%1.2f", quarters, (float) amount_due / 100); // outputs the amount of quarters needed and the new balance to the user

	dimes = amount_due / 10; // gets the amount of dimes needed
	amount_due %= 10; // calculates the amount that is still due

	printf("\nDimes required: %d, balance owing $%1.2f", dimes, (float) amount_due / 100); // outputs the amount of dimes needed and the new balance to the user
	
	nickels = amount_due / 5; // gets the amount of nickels needed
	amount_due %= 5; // calculates the amount that is still due

	printf("\nNickels required: %d, balance owing $%1.2f", nickels, (float) amount_due / 100); // outputs the amount of nickels needed and the new balance to the user

	pennies = amount_due; // gets the amount of pennies needed
	amount_due -= pennies; // calculates the amount that is still due

	printf("\nPennies required: %d, balance owing $%1.2f\n", pennies, (float) amount_due / 100); // outputs the amount of pennies needed and the new balance to the user

	return 0; // returns 0 to the compiler, ending the program

}