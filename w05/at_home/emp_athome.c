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
#define SIZE 4 // Define Number of Employees "SIZE" to be 2

/* Start the program */
int main(void) {

	int option = 0; // Declare the variable to hold the user selected option
	int i; // Declare the variable for the loop in case 1
	int emp_count = 0; // Declare and initialize the control variable to hold the number of employee that were added to the program
	int employee_found = 0; // Declare and initialize the control variable to use in case 3. If the employee is found, the value will change to 1.
	int emp_id; // Declare the variable to hold the input from the user in case 3. The variable will hold an integer that is supposed to be an employee ID.
	int emp_index; // Declare the variable to hold the index position of the employee that is to be manipulated by case 3.

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0}, { 0, 0, 0 } };

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
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
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
				if (emp[i].number > 0) // only display the data if the employee id is positive
					printf("%6d%9d%11.2lf\n", emp[i].number, emp[i].age, emp[i].salary);
			}

			break;
		case 2:	// Adding Employee

			printf("Adding Employee\n"); // Output the header
			printf("===============\n"); // Header cot'd

			/* 
				Check if there is enough room to add a new employee in the array emp.
				If there is, prompt the user for the employee data and save it in the first available spot in the array.
				If there is no more room, output a message to the user stating that the maximum number of employees has been reached.
			*/
			if (emp_count < SIZE) {

				/*
					Loop through the array 'emp' to see if there where the new employee can be added.
					If an ID is equal 0, it means there is no employee data in that index.
					The program then gets the data from the user and save them in the array index.
					After saving the data, the loop should be interrupted.
					To exit the loop, the control variable 'i' is increased to a value that would end the loop.
				*/
				for (i = 0; i < SIZE; i++) {
					if (emp[i].number == 0) {
						printf("Enter Employee ID: "); // Prompt the user to enter the employee ID
						scanf("%d", &emp[i].number); // Save the value entered by the user in the ID(number) member of the Employee emp structure

						printf("Enter Employee Age: "); // Prompt the user to enter the employee age
						scanf("%d", &emp[i].age); // Save the value entered by the user in the age member of the Employee emp structure

						printf("Enter Employee Salary: "); // Prompt the user to enter the employee salary
						scanf("%lf", &emp[i].salary); // Save the value entered by the user in the salary member of the Employee emp structure

						emp_count++; // Increment the control variable so it reflects the addition of the new employee
						i = SIZE; // Change the loop control variable so the program exit the loop
					}
				}				
			}
			else { // No more room in the array emp
				printf("ERROR!!! Maximum Number of Employees Reached\n"); // Let the user know that there is no more room to add employees
			}

			break;
		case 3: // Updating an employee salary

			printf("Update Employee Salary\n"); // Outputs the header
			printf("======================\n"); // Header cot'd

			/*
				Prompt the user to enter an employee ID.
				If it is not found, keep prompting the user until he enters a valid ID.
				When the employee is found, change the control variable employee_found to 1.
			*/
			do {
				printf("Enter Employee ID: "); // Prompt the user to enter an ID
				scanf("%d", &emp_id); // Save the user input in the variable to check if it is a valid ID

				/*
					We check the inputed ID against each registered employee ID so far.
					If there is a match, we change the control variable so the program can leave the loop.
					The array index is also saved to be used to display the current salary and to save the new one.
				*/
				for (i = 0; i < SIZE; i++) {
					if (emp[i].number == emp_id) {
						emp_index = i;
						employee_found = 1;
					}
				}

				// If no employee is found, the program displays an error message to the user.
				if (employee_found == 0) {
					printf("*** ERROR: Employee ID not found! ***\n"); // Outputs an error message to the user stating that no employee was found
				}

			} while ( employee_found == 0); // Repeat if no employee was found

			printf("The current salary is %.2f\n", emp[emp_index].salary); // Display the employee current salary
			printf("Enter Employee New Salary: "); // Prompt the user to enter a new salary for the employee
			scanf("%lf", &emp[emp_index].salary); // Save the new salary inputed by the user

			// Reset the control variables
			employee_found = 0; 
			emp_index = 0;  

			break;
		case 4: // Removing an employee
			printf("Remove Employee\n"); // Outputs the header
			printf("===============\n"); // Header cot'd

			/*
				Prompt the user to enter an employee ID.
				If it is not found, keep prompting the user until he enters a valid ID.
				When the employee is found, change the control variable employee_found to 1.
			*/
			do {
				printf("Enter Employee ID: "); // Prompt the user to enter an ID
				scanf("%d", &emp_id); // Save the user input in the variable to check if it is a valid ID

				/*
					We check the inputed ID against each registered employee ID so far.
					If there is a match, we change the control variable so the program can leave the loop.
					The array index is also saved to be used to display the current salary and to save the new one.
				*/
				for (i = 0; i < SIZE; i++) {
					if (emp[i].number == emp_id) {
						emp_index = i;
						employee_found = 1;
					}
				}

				// If no employee is found, the program displays an error message to the user.
				if (employee_found == 0) {
					printf("*** ERROR: Employee ID not found! ***\n"); // Outputs an error message to the user stating that no employee was found
				}

			} while (employee_found == 0); // Repeat if no employee was found

			printf("Employee %d will be removed\n", emp_id); // Display the employee id that will be removed
			
			// Resets the employee data to 0
			emp[emp_index].number = 0;
			emp[emp_index].age = 0;
			emp[emp_index].salary = 0;
			
			emp_count--; // Decrease the variable that holds the number of employees that have been registered

			// Reset the control variables
			employee_found = 0;
			emp_index = 0;

			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n");
		}

		printf("\n"); // Print a new line for style

	} while (option != 0);


	return 0; // Return the default value to the compiler and end the program
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




// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 222
Enter Employee Age: 22
Enter Employee Salary: 22222.22

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 333
Enter Employee Age: 33
Enter Employee Salary: 33333.33

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 444
Enter Employee Age: 44
Enter Employee Salary: 44444.44

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 555
Enter Employee Age: 55
Enter Employee Salary: 55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   33333.33
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 123
*** ERROR: Employee ID not found! ***
Enter Employee ID: 321
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
The current salary is 33333.33
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   99999.99
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 789
*** ERROR: Employee ID not found! ***
Enter Employee ID: 987
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
Employee 333 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 666
Enter Employee Age: 66
Enter Employee Salary: 66666.66

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
666       66   66666.66
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
