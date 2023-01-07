#include <iostream>
#include <vector>
using namespace std;
void prep1(vector<vector<int> > &in){
    vector<int> first;
    first.push_back(1);
    in.push_back(first);
}
void prep2(vector<vector<int> > &in){
    vector<int> sec;
    sec.push_back(1);
    sec.push_back(1);
    in.push_back(sec);
}
int main(){
    vector< vector<int> > pasc;
    prep1(pasc);
    prep2(pasc);    
    cout<<"How many rows? (greater than 1)"<<'\n';
    int rows;
    cin>>rows;
    cout<<endl;
    for(int r = 2;r<rows;++r){
        vector<int> temp;
        for(int c=0;c<=r;++c){
            if(c==0){
                temp.push_back(1);
            }
            else if(c==r){
                temp.push_back(1);   
            }
            else{
                temp.push_back(pasc[r-1][c-1]+pasc[r-1][c]);   
            }
        }
        pasc.push_back(temp);
    }
    for(int r = 0;r<pasc.size();++r){
        for(int s = 0; s<(((pasc[pasc.size()-1].size()-1)*2)-r);++s){
            cout<<" ";
        }
        for(int c = 0; c<pasc[r].size();++c){
            
            cout<<pasc[r][c]<<" ";
        }
        cout<<endl;
    }   
}