#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){
	int InNum = atoi(argv[1]);
	for(int i =2; i< (int)sqrt(InNum); ++i){
		if(InNum %i == 0){
			printf("Not prime\n");
			return 1;
		}
	}
	printf("Prime\n");
	return 0;
}
