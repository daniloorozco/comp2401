#include "stdio.h"
#include "stdlib.h"
#include "student.h"
#include "populateRecords.h"
#include "string.h"

void printStudents(struct person *person, int size){
	//printall students using loop and accessing data
	int i;
	printf("Printing Students: \n");
	for (i = 0; i < size; i++){
		if (person[i].emplyeeOrStudent == 1){
			printf("\t%-10s %-20s GPA: %d, Courses: %d, Tuition: $%.2f\n", 
			person[i].firstName, person[i].familyName, person[i].u.stu.gpa, 
			person[i].u.stu.numCourses, person[i].u.stu.tuitionFees);
		}
	}
}

void searchName(struct person *person, int size){
	int i;
	char name[size];
	printf("Please enter a student name to search: \n");
	scanf("%s", name);
	for (i = 0; i < size; i++){
		if (strcmp(person[i].familyName, name) == 0){
			//if person searched is a student
			if (person[i].emplyeeOrStudent == 1){
				printf("Student found\n");
				printf("\t%-5s %-20s GPA: %d, Courses: %d, Tuition: $%.2f\n", 
				person[i].firstName, person[i].familyName, person[i].u.stu.gpa, 
				person[i].u.stu.numCourses, person[i].u.stu.tuitionFees);
			}
		}
	}
	
}

