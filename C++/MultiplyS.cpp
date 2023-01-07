#include<iostream>
#include<string>
using namespace std;
void Multiply_nums(char *arr,int &counter){
    double newN = *arr - '0';
    char *ptr = arr;
    ++ptr;
    while(*ptr){
        if(*ptr == '.'){
            break;
        }
        newN *= (*ptr-'0');
        ++ptr;
    }
    cout<<newN<<endl;
    if(newN>9){
       string holder = to_string(newN);
       char H[holder.length()];
       for(int i =0; i<holder.length();++i){
           H[i]=holder[i];
       }
       ++counter;
       Multiply_nums(H,counter);
    }
}
int main(int argc,char *argv[]){
    int counter =0;
    cout.precision(30);
    Multiply_nums(argv[1],counter);
    cout<<"Persistence: "<< counter <<'\n';
}