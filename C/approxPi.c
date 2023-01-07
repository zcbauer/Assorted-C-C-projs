#include <stdio.h>

int main(int argc, char* argv[]){
	float upper,middle,lower;
	upper = 100;
	lower = -100;
	middle = (upper+lower)/2;
	int passes = 0;
	while (upper-lower>0.000001){
		if(middle>3.141593){
			upper = middle;
			middle = (upper + lower)/2;
			passes = passes+1;
		}
		else{
			lower = middle;
			middle = (upper+lower)/2;
			passes = passes+1;
		}
	}
	printf("%d passes\n",passes);
	
}
