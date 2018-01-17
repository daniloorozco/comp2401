#include "stdio.h"
#include "stdlib.h"
#include "employee.h"
#include "populateRecords.h"
#include "string.h"

void printEmployees(struct person *person, int size){
	int i;
	printf("Printing Employees: \n");
	for (i = 0; i < size; i++){
		//check if person is employee
		if (person[i].emplyeeOrStudent == 0){
			//print all employees using string format
			printf("\t%-10s %-20s Years: %d, Level: %d, Salary: $%.2f\n",
			person[i].firstName, person[i].familyName, person[i].u.emp.yearsService,
			person[i].u.emp.level, person[i].u.emp.salary);
		}
	}
}

