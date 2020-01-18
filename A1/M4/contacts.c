/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// Get and store from standard input the values for Name
void getName(struct Name* name) {
	// ---------------------------------------
	// Contact Name Input:
	// ---------------------------------------

	// Declare the control variable that will tell if the user wants to input the middle name initial(s) to the program
	char opt_middle_initial = 'n';

	// Prompt the user to input a string containing the first name and store it in contact_name.firstName.
	printf("\nPlease enter the contact\'s first name: ");
	scanf(" %30[^\n]s", name->firstName);

	// Asks the user if he wants to input middle initial(s) and saves the inputed value in the control variable opt_middle_initial
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &opt_middle_initial);

	// Evaluates if the user wants to input middle initial(s).
	if (opt_middle_initial == 'y' || opt_middle_initial == 'Y') {
		// If positive, prompts the user to input the initial(s) and store the inputed string in contact_name.middleInitial .
		printf("Please enter the contact\'s middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
	}

	// Prompt the user to input a string containing the last name and store it in contact_name.lastName
	printf("Please enter the contact\'s last name: ");
	scanf(" %35[^\n]s", name->lastName);
}

// Get and store from standard input the values for Address
void getAddress(struct Address* address) {
	// ---------------------------------------
	// Contact Address Input:
	// ---------------------------------------

	// Declare the control variable that will tell if the user wants to input an apartment number to the program
	char opt_apartment_number = 'n'; 

	// Prompt the user to enter the address' street number and store it in contact_address.streetNumber
	printf("Please enter the contact\'s street number: ");
	scanf("%u", &address->streetNumber);

	// Prompt the user to enter the address' street name and store it in contact_address.street
	printf("Please enter the contact\'s street name: ");
	scanf(" %40[^\n]", address->street);

	// Asks the user if he wants to input an apartment number and saves the inputed value in the control variable opt_apartment_number
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &opt_apartment_number);

	// Evaluates if the user wants to input appartment number
	if (opt_apartment_number == 'y' || opt_apartment_number == 'Y') {
		// If positive, prompts the user to input the number and store the inputed data in contact_address.apartmentNumber .
		printf("Please enter the contact\'s apartment number: ");
		scanf("%u", &address->apartmentNumber);
	}

	// Prompt the user to enter the address' postal code and store it in contact_address.postalCode
	printf("Please enter the contact\'s postal code: ");
	scanf(" %7[^\n]", address->postalCode);

	// Prompt the user to enter the address' city name and store it in contact_address.street
	printf("Please enter the contact\'s city: ");
	scanf(" %40[^\n]", address->city);
}

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers) {
	// ---------------------------------------
	// Contact Numbers Input:
	// ---------------------------------------

	// Declare the control variables that will tell if the user wants to input the optional phone numbers
	char opt_cell_phone = 'n';
	char opt_home_phone = 'n';
	char opt_business_phone = 'n';

	// Asks the user if he wants to input cell phone / mobile number and saves the inputed value in the control variable opt_cell_phone
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &opt_cell_phone);

	// Evaluates if the user wants to input a cell phone number.
	if (opt_cell_phone == 'y' || opt_cell_phone == 'Y') {
		// If positive, prompts the user to input the number and store the inputed data in contact_phones.cell .
		printf("Please enter the contact\'s cell phone number: ");
		scanf(" %10s", numbers->cell);
	}

	// Asks the user if he wants to input home phone / landline number and saves the inputed value in the control variable opt_home_phone.
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &opt_home_phone);

	// Evaluates if the user wants to input a home phone number.
	if (opt_home_phone == 'y' || opt_home_phone == 'Y') {
		// If positive, prompts the user to input the number and store the inputed data in contact_phones.home .
		printf("Please enter the contact\'s home phone number: ");
		scanf(" %10s", numbers->home);
	}

	// Asks the user if he wants to input a busiess phone number and saves the inputed value in the control variable opt_business_phone.
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &opt_business_phone);

	// Evaluates if the user wants to input a busniess phone number.
	if (opt_business_phone == 'y' || opt_business_phone == 'Y') {
		// If positive, prompts the user to input the number and store the inputed data in contact_phones.business .
		printf("Please enter the contact\'s business phone number: ");
		scanf(" %10s", numbers->business);
	}
}


