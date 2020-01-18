/* -------------------------------------------
Name:				Pedro Zelada Souza
Student number:		116427188
Email:				pzelada-souza@myseneca.ca
Section:			SQQ
Date:				31-10-2018
----------------------------------------------
Assignment:			1
Milestone:			4
---------------------------------------------- */

/*
Structure type Name declaration

The Name Structure contains the following members :

-firstName : A string that will hold the person's first name. Maximum 30 characters.
- middleInitial : A string that will hold the person's middle name initials. Maximum 6 characters.
- lastName : A string that will hold the person's last name. Maximum 35 characters.
*/
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

/*
	Structure type Address declaration

	The Address Structure contains the following members:

	- streetNBumber : A positive street number.
	- street : A string that will hold the name of the street. Maximum 40 characters.
	- apartmentNumber : A positive apartment number.
	- postalCode : A string that will hold the postal code. Maximum 7 characters.
	- city : A string that will hold the name of the city. Maximum 40 characters.
*/
struct Address {
	unsigned int streetNumber;
	char street[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];
};

/*
	Structure type Numbers declaration

	The Numbers Structure contains the following members:

	- cell : A string that will hold the cellphone number. Maximum 10 characters.
	- home : A string that will hold the home (landline) phone number. Maximum 10 characters.
	- business : A string that will hold the business phone number. Maximum 10 characters.
*/
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

/*
	Structure type Contact declaration

	The Contact Structure contains the following members:

	- name : A structure that will hold the data relative to the contact's name.
	- address : A structure that will hold the data relative to the contact's address.
	- numbers : A structure that will hold the data relative to the contact's phone numbers.
*/
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
void getName(struct Name *);

// Get and store from standard input the values for Address
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers *);
