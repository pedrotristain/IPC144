/* -------------------------------------------
Name:				Pedro Zelada Souza
Student number:		116427188
Email:				pzelada-souza@myseneca.ca
Section:			SQQ
Date:				14-11-2018
----------------------------------------------
Assignment:         2
Milestone:          1
---------------------------------------------- */

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

void getName(struct Name* name) {
	// ---------------------------------------
	// Contact Name Input:
	// ---------------------------------------

	// Prompt the user to input a string containing the first name and store it in contact_name.firstName.
	printf("Please enter the contact\'s first name: ");
	scanf(" %30[^\n]s", name->firstName);

	// Asks the user if he wants to input middle initial(s) and saves the inputed value in the control variable opt_middle_initial
	printf("Do you want to enter a middle initial(s)? (y or n): ");

	// Evaluates if the user wants to input middle initial(s).
	if ( yes() == 1 ) {
		// If positive, prompts the user to input the initial(s) and store the inputed string in contact_name.middleInitial .
		printf("Please enter the contact\'s middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);

		clearKeyboard(); // Get rid of excess input
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
	int positive_number = 0; // Control variable to tell if the inputed number is positive.

	// Prompt the user to enter the address' street number and store it in contact_address.streetNumber
	printf("Please enter the contact\'s street number: ");

	// While the user inputs a negative number, ask him to input a positive number until he does.
    do {
        positive_number = getInt(); // Save the input from the user to evaluate.

        // Evaluate if the inputed value is positive. If not, display an error message.
        if( positive_number < 0 )
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");// Outputs the error message.

    } while( positive_number < 0 );

    // If the inputed value is positive, we store it into the address structure.
	address->streetNumber = positive_number;

	// Prompt the user to enter the address' street name and store it in contact_address.street
	printf("Please enter the contact\'s street name: ");
	scanf(" %40[^\n]", address->street);

	// Asks the user if he wants to input an apartment number.
	printf("Do you want to enter an apartment number? (y or n): ");

	// Evaluates if the user wants to input apartment number
	if ( yes() == 1 ) {
		// If positive, prompts the user to input the number and store the inputed data in contact_address.apartmentNumber .
		printf("Please enter the contact\'s apartment number: ");

        // While the user inputs a negative number, ask him to input a positive number until he does.
        do {
            positive_number = getInt(); // Save the input from the user to evaluate.

            // Evaluate if the inputed value is positive. If not, display an error message.
            if( positive_number < 0 )
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: "); // Outputs the error message.

        } while( positive_number < 0 );

        // If the inputed value is positive, we store it into the address structure.
		address->apartmentNumber = positive_number;
	}

	// Prompt the user to enter the address' postal code and store it in contact_address.postalCode
	printf("Please enter the contact\'s postal code: ");
	scanf(" %7[^\n]", address->postalCode);

	clearKeyboard(); // Get rid of excess input

	// Prompt the user to enter the address' city name and store it in contact_address.street
	printf("Please enter the contact\'s city: ");
	scanf(" %40[^\n]", address->city);
}

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers) {
	// ---------------------------------------
	// Contact Numbers Input:
	// ---------------------------------------

    printf("Please enter the contact\'s cell phone number: ");
	scanf(" %10s", numbers->cell);

	// Asks the user if he wants to input home phone / landline number.
	printf("Do you want to enter a home phone number? (y or n): ");

	// Evaluates if the user wants to input a home phone number.
	if ( yes() == 1 ) {
		// If positive, prompts the user to input the number.
		printf("Please enter the contact\'s home phone number: ");
		scanf(" %10s", numbers->home);
	}

	// Asks the user if he wants to input a business phone number.
	printf("Do you want to enter a business phone number? (y or n): ");

	// Evaluates if the user wants to input a business phone number.
	if ( yes() == 1 ) {
		// If positive, prompts the user to input the number and store the inputed data in contact_phones.business .
		printf("Please enter the contact\'s business phone number: ");
		scanf(" %10s", numbers->business);
	}
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
void getContact(struct Contact* contact) {
    getName(&contact->name); // Calls the function to receive the info from the user relative to the contact's name
    getAddress(&contact->address); // Calls the function to receive the info from the user relative to the contact's address
    getNumbers(&contact->numbers); // Calls the function to receive the info from the user relative to the contact's phone numbers
}
