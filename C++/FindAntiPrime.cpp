#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>

using namespace std;
int main(){
int UB; /// upper bound
int NumberFactors=0;
int BestNumberFactors = 0;
int BestNumber = 0;
int NumComposites=0;
cout <<"What is the maximum number you want to search for?"<< endl;
cin>>UB;
//UB=100000;
//int iterations =0;
vector <int> AntiPrimes;
vector <int> NumberFacts;

for(int n=1; n<=UB; ++n){
    NumberFactors = 0;
    for(int i=1; i<=n; ++i){
        if(n%i==0){
            ++NumberFactors;
        }
    //iterations +=1;
    }
    if(NumberFactors>BestNumberFactors){
    BestNumberFactors = NumberFactors;
    BestNumber = n;
    AntiPrimes.push_back(n);
    NumberFacts.push_back(NumberFactors);
    ++NumComposites;
    }
}
ofstream fout("AntiPrimes.txt");
fout <<"Found "<<NumComposites<< " Antiprimes"<< endl;
for(int i=0;i<AntiPrimes.size();++i){
    fout<<AntiPrimes[i]<<" has "<<NumberFacts[i]<<" factors "<<endl;
}
fout<<endl;
fout <<"The Best Antiprime is: " <<BestNumber<<endl;
fout <<"It has "<<BestNumberFactors<<" factors"<<endl;
fout.close();
//cout<<iterations;
}