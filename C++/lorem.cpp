#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
   vector<string> essay;
    ifstream in("Lorem.txt");
    while(in){
       string word;
       in>>word;
        essay.push_back(word);
    }
    in.close();
    ofstream fout("Essay");
    for(int i=0; i<essay.size();++i){
        fout<<essay[i]<<" ";
        if(i%10==0&&i>0){
            fout<<endl;
        }
    }
}