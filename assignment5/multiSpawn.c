#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

//prototypes
void morph(char*);
int numTotal(char *filename);
//main
int main(int argc, char *argv[]){
	int i, d, pid, status;
	//array to hold the ints
	char numChar[64];
	//num of elements in the file
	int total = numTotal(argv[1]);
	unsigned int arrayOfInts[total];
	int arrayChild[total];

	if (argc == 2){
		FILE *file = fopen(argv[1], "rb");
		//if file does not exist 
		if (!file){
			//cannot open 
			printf("Unable to open file\n");
			return -1;
		}
		else{
			int numInt;
			int seek;
			//read the file
			fread(arrayOfInts, sizeof(unsigned int), total, file);
			seek = fseek(file, (sizeof(unsigned int)), SEEK_SET);
			if (seek != 0){
				return -1;	
			}
			else{
				for (i = 0; i < total; i++){
					//store the ints
					sprintf(numChar, "%u", arrayOfInts[i]);
					//fork parent process
					pid = fork();
					arrayChild[i] = pid;
					if (pid == 0){
						morph(numChar);//morph
					}
				}
				int cpid;
				//loop through array
				while ((cpid = waitpid(-1,&status,0)) != -1){
					if (WIFEXITED(status) != 0){
						//check if it is prime
						if (WEXITSTATUS(status) == 1){
							int j = 0;
							while (cpid != arrayChild[j]){
								j++;
							}
							printf("%d is a prime number!\n", arrayOfInts[j]);
						}
					}
				}
				
			}
		}
    
	}
}
//cheack total number of ints in the file 
int numTotal(char *filename){
	int total, rc = 0;
	long pos;
	FILE *file = fopen(filename, "rb");
	fseek(file, 0 , SEEK_END);
	pos = ftell(file);
	total = pos/sizeof(unsigned int);
	fclose(file);
	return total;
}

//morhp function
void morph(char *number) {
    	char *args[80];
   	args[1] = number;
    	args[2] = NULL;
    	int rc = execv("./isPrime", args);
    	printf("rs=%d", rc);
}
