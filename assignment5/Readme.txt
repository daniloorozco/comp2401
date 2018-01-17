README:
COMP 2401 Assignment 5

Danilo Orozco
ID: 101035548
2017/12/03

Files:
	isPrime.c: the base program for checking whether a number is a prime number
	prime.bin: a file that contains 12 unsigned numbers in binary format
	prime.txt: file that contains 12 unsigned numbers in ASCII format.  The number 
			correspond to the numbers in the file prime.bin
	createBinary.c: program that creates a binary file from a given set of numbers. Assuming 
			that the executable is a.out the usage is: a.out filename num1 num2 etc. 
			where filename is the binary file name, num1 is the first unsigned number 
			num2 is the second unsigned number etc.
	singlePrime.c:  read from a binary file the first unsigned integer and then morph 
			itself to the isPrime program.  The file name will be given as a 
			command line parameter.
	singleSpawn.c:  A program that will spawn a child process.  The child process will morph 
			itself into the isPrime program. The parent program will wait until the
			child program completes its task and printout whether the given input number 
			is a prime number using the return code from the child process.
	multiSpawn.c: A program that will spawn multiple child processes. Each child process will 
			morph itself into the isPrime program.  The parent program will wait until 
			all the child processes have completed their work and then printsall the prime 
			numbers.
	Makefile: A makefile whih  facilitates compilation of singlePrime.c
	Makefile1: A makefile which facilitates compilation of singleSpawn.c
	Makefile2: A makefile which facilitates compilation of multiSpawn.c

Compiling:
	Compile using the Makefiles.
	Example.
		make -f Makefile	(singlePrime.c)
		make -f Makefile2	(singleSpawn.c)	
		make -f Makefile3	(multiSpawn.c)
Instructions:
	To run the executable, enter ./fliename prime.bin 
	Make sure to include a binary file in the commandline, which is prime.bin
	For example if u wanted to run singleSpawn.c you would compile using the makefile and then 
	run using:
		./singleSpawn prime.bin
	
