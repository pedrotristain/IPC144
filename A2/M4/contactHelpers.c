/* -------------------------------------------
Name:               Pedro Zelada Souza
Student number:     116427188
Email:              pzelada-souza@myseneca.ca
Section:            SQQ
Date:               29-11-2018
----------------------------------------------
Assignment:         2
Milestone:          4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <ctype.h>
#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

void clearKeyboard(void) {
    while (getchar() != '\n')   ; // empty execution code block on purpose
} // End clearKeyboard()

// pause: Empty function definition goes here:
void pause(void) {
    printf("(Press Enter to Continue)"); //Prompt the user to press Enter to return control to the main program.
    clearKeyboard(); // Clear the Input Buffer since it won't be needed at this moment.
} // End pause();

// getInt: Empty function definition goes here:
int getInt(void) {
    int input; // Integer value to be inputed.
    char validation = 'x'; // Control variable to see if input was valid.

    // While input is invalid, output an error message and prompt the user to input a new value.
    while( validation != '\n' ) {
        scanf("%d%c", &input, &validation); // Call the input function.

        // Verify if the input is valid. If validation is different than \n, the input is invalid.
        if( validation != '\n' ) {
            printf("*** INVALID INTEGER *** <Please enter an integer>: "); // Outputs the error message
            clearKeyboard(); // Get rid of excess inputs to avoid errors.
        }
    }

    // If input is valid, return it.
    return input;
} // End getInt()

// getIntInRange: Empty function definition goes here:
int getIntInRange(int lower, int higher) {
    int input; // Integer value to be inputed.

    // While input is invalid, output an error message and prompt the user to input a new value.
    do {
        input = getInt(); // Calls the function to receive a valid integer.

        // Verify if the input is valid. If validation is different than \n, the input is invalid.
        if( input < lower || input > higher ) {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lower, higher); // Outputs the error message
        }
    } while( input < lower || input > higher );

    // If input is valid, return it.
    return input;
} // End getIntInRange()

// yes: Empty function definition goes here:
// Returns 1 for Yes or 0 for No
int yes(void) {
    char input, new_line; // Char value to be inputed.
    int is_valid = 0; // Control variable to verify if the input is valid. Initialize it as 0, which means invalid (false).
    int return_value = 0; // Integer to return. It will hold 1 if the user inputs y or Y. It will hold 0 if the user inputs n or N.
    // While input is invalid, output an error message and prompt the user to input a new value.
    do {
        is_valid = 0; // Reset the control variable.
        scanf(" %c%c", &input, &new_line); // Call the input function.

        /*  Verify if the input is valid. If it is, we change the control variable is_valid to 1.

            The input is only valid if both the IF statements conditions are met:
            - The second key pressed MUST be a new line (1st IF statement)
            - The first key pressed MUST be one of the four values: y, Y, n or N.   */
        if( new_line == '\n' && (input == 'y' || input == 'Y' || input == 'n' || input == 'N') ) {
                is_valid = 1;
        }

        // If the control variable is equal to 0, the input is invalid. Output the error message to the user.
        if( is_valid == 0 ) {
            clearKeyboard(); // Clear the input buffer to avoid mistakes.
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: "); // Outputs the error message
        }

    } while( is_valid == 0 );

    // If the input is equal to y or Y, set the return value to 1. Otherwise, set it to 0.
    return_value = ( input == 'y' || input == 'Y' ) ? 1 : 0;

    return return_value; // Return the value.
} // End yes()

// menu: Empty function definition goes here:
int menu(void) {

    char input; // Char value to be inputed.

    // Outputs the menu
    printf("Contact Management System");
    printf("\n-------------------------");
    printf("\n1. Display contacts");
    printf("\n2. Add a contact");
    printf("\n3. Update a contact");
    printf("\n4. Delete a contact");
    printf("\n5. Search contacts by cell phone number");
    printf("\n6. Sort contacts by cell phone number");
    printf("\n0. Exit");

    printf("\n\nSelect an option:> ");
    input = getIntInRange(0, 6); // Calls the function to return an inputted value in the range between 0 and 6.

    printf("\n"); // Display a new line for style.

    return input; // Return the inputted value.
} // End menu()

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {
    int option = 1; // Integer variable to hold the menu input.
    struct Contact contacts[MAXCONTACTS] = {
        {
            { "Rick", {'\0'}, "Grimes" },
            { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
            { "4161112222", "4162223333", "4163334444" }
        },
        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" }
        },
        {
            { "Morgan", "A.", "Jones" },{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
            { "7051112222", "7052223333", "7053334444" }
        },
        {
            { "Sasha", {'\0'}, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" }
        }
    };
    // While the user input a value different than 0, prompt him to enter a new value.
    do {
        option = menu(); // Call the menu function and receive the inputted value.

        switch(option){
        case 1:
            displayContacts(contacts, MAXCONTACTS);
            pause(); // Pause the program until Enter is pressed.

            break;
        case 2:
            addContact(contacts, MAXCONTACTS);
            pause(); // Pause the program until Enter is pressed.

            break;
        case 3:
            updateContact(contacts, MAXCONTACTS);
            pause(); // Pause the program until Enter is pressed.

            break;
        case 4:
            deleteContact(contacts, MAXCONTACTS);
            pause(); // Pause the program until Enter is pressed.

            break;
        case 5:
            searchContacts(contacts, MAXCONTACTS);
            pause(); // Pause the program until Enter is pressed.

            break;
        case 6:
            sortContacts(contacts, MAXCONTACTS);
            pause(); // Pause the program until Enter is pressed.

            break;
        case 0:
            printf("Exit the program? (Y)es/(N)o: "); // Ask if the user wishes to exit the program.

            // If the user inputs y or Y, output a message stating the program is over and close it.
            if( yes() == 1 ) {
                printf("\nContact Management System: terminated"); // Output the ending message.
                //exit(); // Close the application.
            } else
                option = 1; // Change the option so the menu loop executes again.

            break;
        default:
            // Optional default case not (yet) needed.
            break;
        }

        printf("\n"); // Print a new line for style
    } while( option != 0 );
} // End contactManagerSystem()


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[]) {
    int needInput = 1; // Control variable to tell if the user needs to input a new value
    int isNumeric = 1; // Control variable to tell if the inputed value is numeric.

    while (needInput == 1) {
        isNumeric = 1; // Reset the control variable
        scanf("%10s", telNum);
        clearKeyboard();

        // We check each character to see if the input is numeric.
        // If any of them is not a digit, we stop checking and change the control variable.
        int i;
        for(i = 0; i < strlen(telNum); i++) {
            if( isdigit( telNum[i] ) == 0 ){ // Check if the character is a digit.
                isNumeric = 0; // Change the control variable to 'False'
                i = strlen(telNum); // Break the iteration.
            }
        }

        // (String Length Function: validate entry of 10 characters)
        // If the length is correct and the input is numeric, we return the value.
        // If not, we display an error message and repeat the code.
        if (strlen(telNum) == 10 && isNumeric == 1)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
} // end getTenDigitPhone()

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]){
    int index = -1; // The return value. It will hold the index if there is a match, or -1 if not.

    // Iterate through the contacts array to see if there is a match.
    // If there is, store the index in the control variable.
    int i;
    for( i = 0; i < size; i++ ){
        if( strcmp( contacts[i].numbers.cell, cellNum ) == 0 ) // Check if the current number is a match with the search pattern.
            index = i; // Store the matched number's index.
    }

    return index; // Return the matched index or -1 if there was no match.
}

// displayContactHeader
void displayContactHeader(void){
    printf("+-----------------------------------------------------------------------------+");
    printf("\n|                              Contacts Listing                               |");
    printf("\n+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter:
void displayContactFooter(int contacts){
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", contacts);
}

// displayContact:
// Display the contact information
void displayContact(const struct Contact *contact){

    // Display contact's name information.
    // Check if there are middle initials and format the display accordingly
    if( strlen(contact->name.middleInitial) > 0 ) // If there are initials, add an empty space before displaying them.
        printf(" %s %s %s", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    else
        printf(" %s %s", contact->name.firstName, contact->name.lastName);

    // Display the contact's address information.
    printf("\n    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

    if( contact->address.apartmentNumber > 0 ) // If there is a registered apartment number, display it.
        printf("Apt# %d, ", contact->address.apartmentNumber);

    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
} // end displayContact()

// displayContacts:
void displayContacts(const struct Contact contacts[], int size){
    int valid_contacts = 0; // Control variable that will hold the amount of valid contacts in the array.

    displayContactHeader(); // Display a header

    // Iterate through the contacts array and check if each item is a valid contact.
    // If it is, display its information.
    int i;
    for(i = 0; i < size; i++){
        if( strlen(contacts[i].numbers.cell) > 0 ) {// Verify if the current contact is valid (cellphone > 0)
            displayContact(&contacts[i]); // Display the contact's information
            valid_contacts++; // Increment the control variable.
        }
    }

    displayContactFooter(valid_contacts); // Display a footer
} // end displayContacts()

// searchContacts:
void searchContacts(const struct Contact contacts[], int size){
    char tel_num[11]; // String variable to hold the user input
    int contact_index = -1; // Integer variable that will hold the contact index in case of a match or -1 otherwise.

    printf("Enter the cell number for the contact: "); // Prompt the user to enter a 10 digit number.
    getTenDigitPhone(tel_num); // Call the function that will receive the input from the user and validate it.

    contact_index = findContactIndex(contacts, size, tel_num); // Store the found index.

    // Verify if there was a match.
    // Display the contact information in case there was and an error message otherwise.
    if(contact_index > -1){
        printf("\n"); // Display a new line for style.
        displayContact(&contacts[contact_index]); // Call function to display the contact's information
    } else
        printf("*** Contact NOT FOUND ***\n"); // Display an error message

    printf("\n"); // Display a new line for style purposes.
} // end searchContacts()

// addContact:
void addContact(struct Contact contacts[], int size){
    int available = -1; // Control variable that will hold the available element index or -1 in case there are no available elements.

    // Iterate through the contacts array checking for an available element.
    // If there is, store the index in the control variable 'available'
    int i;
    for(i = 0; i < size; i++) {
        if( strlen(contacts[i].numbers.cell) == 0 ) { // Verify if the current iterated element is available.
            available = i; // Store the index in the control variable.
            i = size; // Break the loop.
        }
    }

    // If available is greater than -1,
    // Display a message alerting that the array is full otherwise.
    if( available > -1 ) {
        getContact(&contacts[available]); // Add a new contact in the current iterated element.
        printf("--- New contact added! ---\n\n"); // Display a conclusion message.
    } else
        printf("*** ERROR: The contact list is full! ***\n\n"); // Display an error message
} // end addContact()

// updateContact:
void updateContact(struct Contact contacts[], int size){
    char tel_num[11]; // String variable to hold the user input
    int contact_index = -1; // Integer variable that will hold the contact index in case of a match or -1 otherwise.

    printf("Enter the cell number for the contact: "); // Prompt the user to enter a 10 digit number.
    getTenDigitPhone(tel_num); // Call the function that will receive the input from the user and validate it.

    contact_index = findContactIndex(contacts, size, tel_num); // Store the found index.

    // If no contact was found, display a message stating that no contact was found.
    // Otherwise, display the contact's information and ask the user if he wants to update the contact's information.
    if( contact_index == -1 )
        printf("*** Contact NOT FOUND ***\n\n"); // Display a message stating that no contact was found.
    else {
        printf("\nContact found:\n"); // Display a message stating that a contact was found.
        displayContact(&contacts[contact_index]); // Display the contact's information.
        printf("\n"); // Display a new line for style.

        printf("Do you want to update the name? (y or n): "); // Ask the user if he wishes to update the contact's name.
        if( yes() == 1 ) // Check if the user wishes to update the contact's name.
            getName(&contacts[contact_index].name); // Call the function to update the contacts name

        printf("Do you want to update the address? (y or n): "); // Ask the user if he wishes to update the contact's address.
        if( yes() == 1 ) // Check if the user wishes to update the contact's name.
            getAddress(&contacts[contact_index].address); // Call the function to update the contacts address

        printf("Do you want to update the numbers? (y or n): "); // Ask the user if he wishes to update the contact's numbers.
        if( yes() == 1 ) // Check if the user wishes to update the contact's name.
            getNumbers(&contacts[contact_index].numbers); // Call the function to update the contacts numbers

        printf("--- Contact Updated! ---\n\n"); // Display a conclusion message.
    } // end if
} // end updateContact()

// deleteContact:
void deleteContact(struct Contact contacts[], int size){
    char tel_num[11]; // String variable to hold the user input
    int contact_index = -1; // Integer variable that will hold the contact index in case of a match or -1 otherwise.

    printf("Enter the cell number for the contact: "); // Prompt the user to enter a 10 digit number.
    getTenDigitPhone(tel_num); // Call the function that will receive the input from the user and validate it.

    contact_index = findContactIndex(contacts, size, tel_num); // Store the found index.

    // If no contact was found, display a message stating that no contact was found.
    // Otherwise, display the contact's information and ask the user if he wants to delete the contact's information.
    if( contact_index == -1 )
        printf("*** Contact NOT FOUND ***\n"); // Display a message stating that no contact was found.
    else {
        printf("\nContact found:\n"); // Display a message stating that a contact was found.
        displayContact(&contacts[contact_index]); // Display the contact's information.
        printf("\n"); // Display a new line for style.

        printf("CONFIRM: Delete this contact? (y or n): "); // Ask the user if he wishes to delete the contact's information.
        if( yes() == 1 ){ // Check if the user wishes to delete the contact's information.
            contacts[contact_index].numbers.cell[0] = '\0'; // Set the contact's cell number to nothing.
            printf("--- Contact deleted! ---\n"); // Display a conclusion message.
        } // end if( yes )

        printf("\n"); // Print a new line for style.
    } // end if( contact_index )
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size){
    struct Contact temp_contact; // Create a temporary contact variable to help sort the array.

    // Iterate through the array in a Bubble Sorting manner.
    int i;
    for (i = size - 1; i > 0; i--) {
        int j;
        for (j = 0; j < i; j++) {

            // Compare the current element with the next one.
            // If it is 'higher', flip the order of both elements.
            if ( strcmp(contacts[j].numbers.cell, contacts[j+1].numbers.cell) > 0 ) {

                temp_contact = contacts[j]; // Store the current element in the control variable.
                contacts[j] = contacts[j+1]; // Replace the current element by the next one.
                contacts[j+1] = temp_contact; // Replace the next element by the control variable.

            } // end if
        } // end for(j)
    } // end for(i)

    printf("--- Contacts sorted! ---\n\n"); // Display a conclusion message.
} // end sortContacts()
