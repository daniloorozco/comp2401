#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

//prototype for morph function
void morph(char*);

int main(int argc, char *argv[]){
	char userMax[80];
	char numChar[sizeof(unsigned int)];
   	int pid, rc;
	if (argc == 2){
		//open the file 
		FILE *file = fopen(argv[1], "rb");
		if (!file){
			printf("error");
			return -1;
		}
		else{
			int numInt;
			int seek;
			//read the file
			fread(&numInt, sizeof(unsigned int), 1, file);
			seek = fseek(file, (sizeof(unsigned int)), SEEK_SET);
			if (seek != 0){
				return -1;	
			}
			else{
				//store the vslues
				sprintf(numChar, "%u", numInt);
			}
			
		}
    		//strcpy(userMax, numChar);
    		pid = fork();
    		if (pid==0) { //if it's child process
        		morph(numChar);
    		} 	
		else if (pid > 0) { //if parent process
	    		int status;
	    		wait(&status); //let child process to finish executing
           		if (WIFEXITED(status) != 0) { 
            			if (WEXITSTATUS(status) == 1){  //chek the return of Morph
                    			printf("%s is a prime number\n", numChar);
				}
                		if (WEXITSTATUS(status) == 0){
                    			printf("%s is not a prime number\n", numChar);
				}	
       			}
		}
            
        }
    	return 1;
}

void morph(char *number){
	char *args[80];
   	args[1] = number;
    	args[2] = NULL;
    	int rc = execv("./isPrime", args);
    	printf("rs=%d", rc);
}
