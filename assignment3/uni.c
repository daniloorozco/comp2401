#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "populateRecords.h"
#include "string.h"
#include "student.h"
#include "employee.h"

#define NUM_RECORDS 20
//prototype for menu() function
void menu();
void summary();

int main(){
	printf("--Carleton University Records Program--\n\n\n");
	printf("Please select an option:\n\n");
	//array that holds 20 records of person
	struct person person[NUM_RECORDS];
	//populate the array
	populateRecords(person, NUM_RECORDS);
	int quit = 0;
	//while loop to control when program quits
	while (quit == 0){
		int y = 0;
		int number = 0;
		//while loop used to see if input is valid 
		while (y == 0){
			menu();
			scanf("%d", &number);
			if (number < 0 || number > 4){
				printf("Please enter a valid input\n\n");
			}
			else{
				y = 1;
			}

		}
		int number2 = 0;
		int loop = 0;
		//switch statement to control command of user
		//calls functions to print / search info
		switch (number){
			case 1:
				printEmployees(person, NUM_RECORDS);
				break;
			case 2:
				printStudents(person, NUM_RECORDS);
				break;
			case 3:
				searchName(person, NUM_RECORDS);
				break;
			case 4:
				summary(person, NUM_RECORDS);
				break;
			case 0: 
				printf("Are you sure you want to quit?\n");
				while (loop == 0){
					printf("\t1. Yes\n");
					printf("\t2. No\n");
					scanf("%d", &number2);
					if (number2 < 1 || number2 > 2){
						printf("Please enter a valid input\n\n");
					}else if (number2 == 2){
						loop = 1;	
					}else{
						loop = 1;
						quit =1;
					}
				}
				break;
		}
	}
	return 0;
}

void menu(){
	//print the menu
	printf("MENU:\n");
	printf("\t1. Print all employees\n");
	printf("\t2. Print all Students\n");
	printf("\t3. Search Students using Family Name\n");
	printf("\t4. Summary of Data\n");
	printf("\t0. Quit\n");


}
void summary(struct person *person, int size){
	printf("Printing Summary: \n");
	printf("\tTotal number of records: %d\n", NUM_RECORDS);
	//display summary of students
	printf("Student Stats:\n");
	int i;
	int counter = 0;
	float sumGPA = 0.0, sumCourses = 0.0, sumTuition = 0.0, avgGPA, avgCourses, avgTuition;
	for (i = 0; i < size; i++){
		if (person[i].emplyeeOrStudent == 1){
			//counting number of students
			counter++;
			//accessing the info
			//adding all values together
			sumGPA += person[i].u.stu.gpa;
			sumCourses += person[i].u.stu.numCourses;
			sumTuition += person[i].u.stu.tuitionFees;
		}
	}
	printf("\tNumber of Students: %d\n", counter);
	//calculate averages 
	avgGPA = sumGPA/counter; avgCourses = sumCourses/counter; avgTuition = sumTuition/counter;
	//print averages calculated
	printf("\tAverage GPA: %.2f, Average Number of Courses: %.2f, Average Tuition Fees: $%.2f\n",avgGPA, avgCourses, avgTuition);
	//display summary of employees
	printf("Employee Stats:\n");
	int j, k;
	int min;
	//for loop that breakes when has an employee with a level (used to calculate min)
	for (k = 0; k < size; k++){
		if (person[k].emplyeeOrStudent == 0){
			min = person[k].u.emp.level;
			break;
		}
	}
	//intialise vars 
	int max = 0;
	int counter2 = 0;
	float sumService = 0.0, sumSalary = 0.0, avgService, avgSalary; 
	for (j = 0; j < size; j++){
		if (person[j].emplyeeOrStudent == 0){
			//counting employees
			counter2++;
			//adding all values together
			sumService += person[j].u.emp.yearsService;
			sumSalary += person[j].u.emp.salary;
			//find min and maxes
			if (person[j].u.emp.level > max){
				max = person[j].u.emp.level;
			}
			if (person[j].u.emp.level < min){
				min = person[j].u.emp.level;
			}
		}
	}
	//calculate average
	avgService = sumService/counter2, avgSalary = sumSalary/counter2;
	//prinintg info 
	printf("\tNumber of Employees: %d, Min Level: %d, Max Level: %d\n",counter2, min, max);
	printf("\tAverage Years of Service: %.2f, Average Salary: $%.2f\n", avgService, avgSalary);
	
}








