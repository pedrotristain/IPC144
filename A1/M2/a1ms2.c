/* -------------------------------------------
Name:				Pedro Zelada Souza
Student number:		116427188
Email:				pzelada-souza@myseneca.ca
Section:			SQQ
Date:				31-10-2018
----------------------------------------------
Assignment:			1
Milestone:			2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // Include the default input and output C library

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// Main function to start the program
int main (void)
{
	// Declare variables here:
    /* 
		Struct Variables
		The variables contact_name, contact_address and contact_phones are structures that will hold the data from the contact.

		- contact_name is to hold: The first, middle and last name of the contact.
		- contact_address is to hold: The street name, street number, apartment number, postal code and city name of the contact's address.
		- contact_phones is to hold: The cellphone / mobile, home phone / landline and business phone numbers of the contact.
	*/
	struct Name contact_name = {"", "", ""};
	struct Address contact_address = { 0 };
	struct Numbers contact_phones = { "" };
	
	/*
		Declaration and initialization of the control variables.

		- opt_middle_initial: Tells if the user wants to input middle initial(s) to the program
		- opt_apartment_number: Tells if the user wants to input an apartment number to the program
		- opt_cell_phone: Tells if the user wants to input a cellphone number to the program
		- opt_home_phone: Tells if the user wants to input a home / landline phone number to the program
		- opt_business_phone: Tells if the user wants to input a business phone number to the program
	*/
	char opt_middle_initial = 'n';
	char opt_apartment_number = 'n';
	char opt_cell_phone = 'n';
	char opt_home_phone = 'n';
	char opt_business_phone = 'n';

    // Display the title
	printf("Contact Management System");
	printf("\n-------------------------");
	
	// ---------------------------------------
    // Contact Name Input:
	// ---------------------------------------

	// Prompt the user to input a string containing the first name and store it in contact_name.firstName.
	printf("\nPlease enter the contact\'s first name: ");
	scanf("%30s", contact_name.firstName);

	// Asks the user if he wants to input middle initial(s) and saves the inputed value in the control variable opt_middle_initial
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &opt_middle_initial);
	
	// Evaluates if the user wants to input middle initial(s).
	if ( opt_middle_initial == 'y' || opt_middle_initial == 'Y' ) {
		// If positive, prompts the user to input the initial(s) and store the inputed string in contact_name.middleInitial .
		printf("Please enter the contact\'s middle initial(s): ");
		scanf(" %6[^\n]", contact_name.middleInitial);
	}
	
	// Prompt the user to input a string containing the last name and store it in contact_name.lastName
	printf("Please enter the contact\'s last name: ");
	scanf(" %35[^\n]s", contact_name.lastName);

	// ---------------------------------------
    // Contact Address Input:
	// ---------------------------------------

	// Prompt the user to enter the address' street number and store it in contact_address.streetNumber
	printf("Please enter the contact\'s street number: ");
	scanf("%u", &contact_address.streetNumber);

	// Prompt the user to enter the address' street name and store it in contact_address.street
	printf("Please enter the contact\'s street name: ");
	scanf(" %40[^\n]", contact_address.street);

	// Asks the user if he wants to input an apartment number and saves the inputed value in the control variable opt_apartment_number
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &opt_apartment_number);

	// Evaluates if the user wants to input appartment number
	if (opt_apartment_number == 'y' || opt_apartment_number == 'Y') {
		// If positive, prompts the user to input the number and store the inputed data in contact_address.apartmentNumber .
		printf("Please enter the contact\'s apartment number: ");
		scanf("%u", &contact_address.apartmentNumber);
	}

	// Prompt the user to enter the address' postal code and store it in contact_address.postalCode
	printf("Please enter the contact\'s postal code: ");
	scanf(" %7[^\n]", contact_address.postalCode);

	// Prompt the user to enter the address' city name and store it in contact_address.street
	printf("Please enter the contact\'s city: ");
	scanf(" %40[^\n]", contact_address.city);

	// ---------------------------------------
    // Contact Numbers Input:
	// ---------------------------------------

	// Asks the user if he wants to input cell phone / mobile number and saves the inputed value in the control variable opt_cell_phone
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &opt_cell_phone);

	// Evaluates if the user wants to input a cell phone number.
	if (opt_cell_phone == 'y' || opt_cell_phone == 'Y') {
		// If positive, prompts the user to input the number and store the inputed data in contact_phones.cell .
		printf("Please enter the contact\'s cell phone number: ");
		scanf(" %10s", contact_phones.cell);
	}

	// Asks the user if he wants to input home phone / landline number and saves the inputed value in the control variable opt_home_phone.
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &opt_home_phone);

	// Evaluates if the user wants to input a home phone number.
	if (opt_home_phone == 'y' || opt_home_phone == 'Y') {
		// If positive, prompts the user to input the number and store the inputed data in contact_phones.home .
		printf("Please enter the contact\'s home phone number: ");
		scanf(" %10s", contact_phones.home);
	}

	// Asks the user if he wants to input a busiess phone number and saves the inputed value in the control variable opt_business_phone.
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &opt_business_phone);

	// Evaluates if the user wants to input a busniess phone number.
	if (opt_business_phone == 'y' || opt_business_phone == 'Y') {
		// If positive, prompts the user to input the number and store the inputed data in contact_phones.business .
		printf("Please enter the contact\'s business phone number: ");
		scanf(" %10s", contact_phones.business);
	}

	// ---------------------------------------
    // Display Contact Summary Details
	// ---------------------------------------

	// Prints the header
	printf("\nContact Details");
	printf("\n---------------");
	
	// Prints the contact's name data stored in the contact_name structure
	printf("\nName Details");
	printf("\nFirst name: %s", contact_name.firstName);
	printf("\nMiddle initial(s): %s", contact_name.middleInitial);
	printf("\nLast name: %s", contact_name.lastName);

	// Prints the contact's address data stored in the contact_address structure
	printf("\n\nAddress Details");
	printf("\nStreet number: %u", contact_address.streetNumber);
	printf("\nStreet name: %s", contact_address.street);
	printf("\nApartment: %u", contact_address.apartmentNumber);
	printf("\nPostal code: %s", contact_address.postalCode);
	printf("\nCity: %s", contact_address.city);

	// Prints the contact's phone data stored in the contact_phones structure
	printf("\n\nPhone Numbers:");
	printf("\nCell phone number: %s", contact_phones.cell);
	printf("\nHome phone number: %s", contact_phones.home);
	printf("\nBusiness phone number: %s", contact_phones.business);

	// ---------------------------------------
	// Display Completion Message
	// ---------------------------------------

	printf("\n\nStructure test for Name, Address, and Numbers Done!\n");

	// Returns the default value to the compiler and finish the program.
    return 0;
}

/*  SAMPLE OUTPUT:
    
    Contact Management System
    -------------------------
    Please enter the contact's first name: Tom
    Do you want to enter a middle initial(s)? (y or n): y
    Please enter the contact's middle initial(s): L. A.
    Please enter the contact's last name: Wong Song
    Please enter the contact's street number: 20
    Please enter the contact's street name: Keele Street
    Do you want to enter an apartment number? (y or n): y
    Please enter the contact's apartment number: 40
    Please enter the contact's postal code: A8A 4J4
    Please enter the contact's city: North York
    Do you want to enter a cell phone number? (y or n): Y
    Please enter the contact's cell phone number: 9051116666
    Do you want to enter a home phone number? (y or n): Y
    Please enter the contact's home phone number: 7052227777
    Do you want to enter a business phone number? (y or n): Y
    Please enter the contact's business phone number: 4163338888

    Contact Details
    ---------------
    Name Details
    First name: Tom
    Middle initial(s): L. A.
    Last name: Wong Song

    Address Details
    Street number: 20
    Street name: Keele Street
    Apartment: 40
    Postal code: A8A 4J4
    City: North York

    Phone Numbers:
    Cell phone number: 9051116666
    Home phone number: 7052227777
    Business phone number: 4163338888

    Structure test for Name, Address, and Numbers Done!
*/