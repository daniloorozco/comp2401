#ifndef STRUCT_HEADER  
#define STRUCT_HEADER
//structure of student
struct student{
	float tuitionFees;
	unsigned int numCourses: 6;
	unsigned int gpa: 4;
}student;
//structure of employee
struct employee{
	float salary;
	unsigned int yearsService: 6;
	unsigned int level: 4;
}employee;
//structure of person
struct person{
	char firstName[16];
	char familyName[16];
	char telephone;
	//discriminant 0 = employee, 1 = student
	unsigned int emplyeeOrStudent: 1;
	//union of student and employee structures
	union {
		struct student stu;
		struct employee emp;
		//access with obj.u.student
	}u;
}person[20];
#endif
