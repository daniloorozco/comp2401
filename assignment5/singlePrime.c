#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>


void morph(char*);


int main(int argc, char *argv[]) {
	char numChar[sizeof(unsigned int)];
	if(argc == 2){
		//open the file
		FILE *file = fopen(argv[1], "rb");
		//if the file does not exist
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
				//store the values
				sprintf(numChar, "%u", numInt);
				//amd print themm
				printf("%s", numChar);
			}
			
		}
		//morph
    		morph(numChar);

	}
}
//morph function
void morph(char *number) {
    	char *args[80];
   	args[1] = number;
    	args[2] = NULL;
    	int rc = execv("./isPrime", args);
    	printf("rs=%d", rc);
}
