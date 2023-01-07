#include <iostream>
using namespace std;
int main(){
    double ans = 1;
    for(int i = 1;i<=20;++i){
        ans = ans * i;
    }
    cout<<"20 factorial is "<<ans<<'\n';
}