#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
using namespace std::chrono;


unsigned long long primes(unsigned long long max){
    //int total = 0;
    vector <unsigned long long> primes = {2, 3};

    for(unsigned long long i = 6; i <= max; i = i + 6){                //Start at 6, increment by 6
        unsigned long long check1 = i - 1;                             //Find the numbers next to the multiple of 6
        unsigned long long check2 = i + 1;
        long double max_check = sqrt(check2);                     //Set the max prime it can check
        bool prime1 = 1;
        bool prime2 = 1;

        for(unsigned long long j = 0; primes[j] <= max_check; ++j){    //For all known primes
            if(check1 % primes[j] == 0){   //Check for composite
                prime1 = 0;
                break;
            }
            if(check2 % primes[j] == 0){
                prime2 = 0; 
                break;
            }         
        }
        if(prime1 == 1){                //Add primes to list
                primes.push_back(check1);
            }
            if(prime2 == 1){
                primes.push_back(check2);
            }   
    }
    return primes.size();
}

int main(int arc, char* argv[]){

    //Ask max, open file, print start time to file

    unsigned long long max;
    max = (long long)atoi(argv[1]); 
    /*
    cout << "What would you like to sim up to (by millions)? ";
    cin >> max; 
    cout << endl;
    */
    ofstream data("prime_runtime_data_2.txt");

    if(data.is_open()){
        cout << "The file has opened!" << endl << endl;
    }
    else{
        return 1;
    }

    time_t rawtime;
    struct tm * timeinfo;

    for(unsigned long long n = 1000000; n <= max; n = n + 1000000){
        time (&rawtime);
        timeinfo = localtime (&rawtime);
        data << "Searched up to " << n << " and found " << primes(n) << " primes. Finished at: " << asctime(timeinfo);
        cout << n*1.0/max*100 << "% done" << endl;
    }
    
    cout << primes(max)<<'\n';
    cout << "The program has finished!" << endl << endl;

    return 0;
}