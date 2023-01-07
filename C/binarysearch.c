#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
	int upper, lower, middle,record,recordnum;
	record =0;
	recordnum=0;
	for(int i = 0; i<atoi(argv[1]); ++i){
		lower =0;
		upper = atoi(argv[1]);
		middle = (lower + upper)/2;
		for(int it =0;middle !=i;++it){
			if(middle <i){
				lower = middle;
			}
			else{
				upper = middle;
			}
			middle = (lower + upper)/2;
			//printf("i:%d,it:%d,middle:%d\n",i,it,middle);
			if(it>recordnum){
				recordnum = it;
				record = i;
			}
		}

	}
	printf("The most iterations taken was %d, to find the number %d\n",recordnum,record);
	
}
