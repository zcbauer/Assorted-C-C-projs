#include <iostream>
#include<fstream>
#include<vector>
using namespace std;

void allNumbers(vector<int> &numbers, int &limit){
    for(int i=0; i<=limit; ++i){
        numbers.push_back(i);
    }
}
int main(){

vector <int> numberList;
int limit;
cout<<"What is the max that you want? "<<endl;
cin>> limit;
allNumbers(numberList,limit);
ofstream fout("numbers.txt");
int counter =0;
for(int i=0;i<numberList.size();++i){
   
    fout<<numberList[i]<<" ";
    if(counter%10==0){ fout<<endl;}
 ++counter;
}
}
