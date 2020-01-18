/* -------------------------------------------
Name:				Pedro Zelada Souza
Student number:		116427188
Email:				pzelada-souza@myseneca.ca
Section:			SQQ
Date:				14-11-2018
----------------------------------------------
Assignment:         2
Milestone:          2
---------------------------------------------- */

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition
void clearKeyboard(void) {
    while (getchar() != '\n')   ; // empty execution code block on purpose
} // End clearKeyboard()

// pause: Empty function definition goes here:
void pause(void) {
    //char c;
    printf("(Press Enter to Continue)"); //Prompt the user to press Enter to return control to the main program.
    //printf("\nPre Clear Keyboard");
    clearKeyboard(); // Clear the Input Buffer since it won't be needed at this moment.
    //printf("\nPos Clear Keyboard");
    //printf("\nPre Getchar");
    //getchar();
    //printf("\nPos Getchar");
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

    return input; // Return the inputted value.
} // End menu()

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void) {
    int option = 1; // Integer variable to hold the menu input.

    // While the user input a value different than 0, prompt him to enter a new value.
    do {
        option = menu(); // Call the menu function and receive the inputted value.

        switch(option){
        case 1:
            printf("\n<<< Feature %d is unavailable >>>\n\n", option); // Output the message to the user.
            pause(); // Pause the program until Enter is pressed.

            break;
        case 2:
            printf("\n<<< Feature %d is unavailable >>>\n\n", option); // Output the message to the user.
            pause(); // Pause the program until Enter is pressed.

            break;
        case 3:
            printf("\n<<< Feature %d is unavailable >>>\n\n", option); // Output the message to the user.
            pause(); // Pause the program until Enter is pressed.

            break;
        case 4:
            printf("\n<<< Feature %d is unavailable >>>\n\n", option); // Output the message to the user.
            pause(); // Pause the program until Enter is pressed.

            break;
        case 5:
            printf("\n<<< Feature %d is unavailable >>>\n\n", option); // Output the message to the user.
            pause(); // Pause the program until Enter is pressed.

            break;
        case 6:
            printf("\n<<< Feature %d is unavailable >>>\n\n", option); // Output the message to the user.
            pause(); // Pause the program until Enter is pressed.

            break;
        case 0:
            printf("\nExit the program? (Y)es/(N)o: "); // Ask if the user wishes to exit the program.

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
