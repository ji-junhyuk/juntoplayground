#include <stdio.h> 
#include <string.h>
salute(char *temp1,char *temp2){ 
	char name[400]; 
	strcpy(name, temp2); 
	printf("Hello %s %s\n", temp1, name); 
}
main(int argc, char * argv[]){ 
	salute(argv[1], argv[2]); 
	printf("Bye %s %s\n", argv[1], argv[2]); 
}
