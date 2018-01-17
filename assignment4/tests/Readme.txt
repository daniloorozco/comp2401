READ_ME file

Danilo Orozco
101035548
2017-11-21

Purpose:
	Your team was tasked to manipulate records of all the employees at Carleton. 
	Code a required set of linked list functions, applying the knowledge of linked lists and memory 
	allocation.

File Organization:
	linked_list.h: this file contains the definition of the linked link functions
	linked_list.c: this file contains the code of the linked list functions
	main.c: an example code for testing the linked list functions.  Note that this is not a 
		comprehensive set. A more comprehensive test program may be provided later.
	Bubblesort.o: a sorting file that can be used to test the removeDuplicates() function.
	Makefile: a makefile for generating the code

Compiling:
	compile and link the test program with your code and the bubblesort function.  
	For example use:
		gcc -g main.c linked_list.c bubble_sort.o
	Alternatively you can use the makeFile
	For example:
		make clean (when you change anything to file and delete *.o files)
		make (to compile)
		./a.out (to run)
Issues and Limitations:
	No known limitations

Instructions:
	Once the program compiles enter (./a.out) to run the program. The program will print a list of people 
	and prompt the user to input enter to continue with searching and deleting. Once the program has finished 
	with the remove duplicates function, it will end.
