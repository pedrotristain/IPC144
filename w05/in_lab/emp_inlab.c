/*
	Name: Pedro Zelada Souza
	Student number: 116427188
	Email: pzelada-souza@myseneca.ca
	Workshop: 05 - Structures
	Section: SQQ
	Date: 10-10-2018
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Employee.h" // Include the header file that has the declaration of the structure Employee
#define SIZE 2 // Define Number of Employees "SIZE" to be 2

/* Start the program */
int main(void) {

	int option = 0; // Declare the variable to hold the user selected option
	int i; // Declare the variable for the loop in case 1
	int emp_number = 0; // Declare and initialize the control variable to hold the number of employee that were added to the program

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { { 0, 0, 0 }, { 0, 0, 0 } };
    
	printf("\n---=== EMPLOYEE DATA ===---\n\n"); // Outputs the Header of the program

	/*
		While the user selects an option that is different than 0, the program is gonna prompt him to select an option and execute a command.
		If the user inputs 0 as his option, the program ends.

		The options available to the user are:
		- 1: The user will see the list of added Employees
		- 2: The user will add a new Employee, if possible
		- 0: The user will see an exitting message and the program ends
		- Others: The user will get a message stating he chose an wrong option and be prompted to try again.
	*/
	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		// Capture input to option variable
		scanf("%d",&option);
		printf("\n"); // Print a new line for style
		
		switch (option) {
		case 0:	// Exit the program
			
			printf("Exiting Employee Data Program. Good Bye!!!\n"); // Print an exitting message to the user

			return 0; // Return the default value to the compiler and exit the program

			break;
		case 1: // For every employee added to the array emp, display their data back to the user
			printf("EMP ID  EMP AGE EMP SALARY\n"); // Outputs the header
			printf("======  ======= ==========\n"); // Header cot'd

			/*
				For every employee in the array emp, display the data inputed by the user.
				The data will be displayed in the format: <ID> <AGE> <SALARY>
				I.e:   100       30   10000.00
			*/
			for (i = 0; i < SIZE; i++) {
				if(emp[i].number > 0) // only display the data if the employee id is positive
					printf("%6d%9d%11.2lf\n", emp[i].number, emp[i].age, emp[i].salary);
			}

			break;
		case 2:	// Adding Employee
				// @IN-LAB
				
			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 

			if (emp_number < SIZE) {
				printf("Enter Employee ID: "); // Prompt the user to enter the employee ID
				scanf("%d", &emp[emp_number].number); // Save the value entered by the user in the ID(number) member of the Employee emp structure

				printf("Enter Employee Age: "); // Prompt the user to enter the employee age
				scanf("%d", &emp[emp_number].age); // Save the value entered by the user in the age member of the Employee emp structure

				printf("Enter Employee Salary: "); // Prompt the user to enter the employee salary
				scanf("%lf", &emp[emp_number].salary); // Save the value entered by the user in the salary member of the Employee emp structure

				emp_number++; // Increment the control variable so it reflects the addition of the new employee
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached"); // Let the user know that there is no more room to add employees
				printf("\n"); // Print a new line for style
			}

			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}
		
		printf("\n"); // Print a new line for style

	} while (option != 0);


	return 0; 
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
