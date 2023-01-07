#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ofstream fout("cards.txt");
    for(int i=2;i<=14;++i){
        fout<<"Spades "<<"Clubs "<<"Hearts "<<"Diamonds"<<endl;
    }
fout.close();
}