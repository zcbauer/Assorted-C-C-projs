#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;


int main(int argc,char *argv[]){
	int ULimit = atoi(argv[1]);
	vector<bool> arr(ULimit);
	int limit = pow(ULimit,0.5);
	for(int i=0; i<ULimit;++i){
		arr[i] = true;
	}
	for(int i=2; i<limit+1; i = (i==2?i+1:i+2)){
		if(arr[i] == true){
			int start = pow(i,2);
			for(int p = start;p<ULimit; p= p+i){
				arr[p] = false;
			} 
		}
	}
	int numprimes = 0;
	//bool endedLine = true;
	for(int i = 2; i<ULimit; ++i){
		if(arr[i] == true){
			//cout<<i<<", ";
			++numprimes;
			//endedLine =true;

		}
	}
	cout<<"\n\n";
	cout<<numprimes;
	cout<<"\n\n";
} 
