#include<iostream>
#include<chrono>
#include<thread>
#include<cstdlib>
using std::cout;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

int main(){
    for(int i = 0;i<30;++i){
        if(i%2==0){
            sleep_for(500ms);
            cout<<'\r';
        }
        else{
            cout<<"\nhello";
            sleep_for(500ms);
            system("clear");
        }
    }
    cout<<"Done\n";
}