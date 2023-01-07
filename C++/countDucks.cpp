#include <iostream>
using namespace std;

// REQUIRES: n >= 0
// EFFECTS: computes the number of ducks at month n
int numDucks(int n/*,int &stackframes*/) {
  if(n<=1){
    return 5;
  }
 // cout<<stackframes<<" Stackframes"<<endl;
  //++stackframes;
  return numDucks(n-1/*,stackframes*/)+3*numDucks(n-2/*,stackframes*/);
}

int main() {
    int stackframes = 0;
    cout << numDucks(20/*,stackframes*/) << endl;
}