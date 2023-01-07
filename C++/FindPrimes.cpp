#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool checkPrimeEven(int &input){

}
bool checkPrimeOdd(int &input){

}
int main(){
    ifstream in("prime.txt");
    string input;
    in>>input;
    in.close();
    int num = stoi(input);
    ofstream out("prime.txt");
    if(checkPrimeOdd(num)){
        out<<num;
    }
    out.close();
}