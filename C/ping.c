#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]){
	char command[20] = "ls";
	char *args[3];
	char arg1[3] = "-c";
	char arg2[3] = "1";
	char arg3[20] = "142.250.80.46";
	args[0] = command;
	args[1] = NULL;
	args[2] = NULL;
	execvp(command,args);

}
