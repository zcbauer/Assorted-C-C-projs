#include <iostream>
using namespace std;
double recursion(int n){
    if(n==0){
        return 1;
    }
    else{
        return n* recursion(n-1);
    }
}
int main(){
    double ans = recursion(20);
    cout<<"20 factorial is "<<ans<<'\n';
}