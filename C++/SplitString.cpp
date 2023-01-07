#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void split_string(char *dst, const char *src, int pos){
    const char * newstart = src+pos;
    bool toEnd = false;
    while(!toEnd){
        if(*(newstart)=='\0'){
            toEnd = true;
        }
        else{
            *dst = *newstart;
            ++dst;
            ++newstart;
        }
    }
    for(const char *ptr = src; ptr<(src+pos);++ptr,++dst){
        if(*ptr == '\0'){
            return;
        }
        *dst = *ptr;
    }
    *dst = '\0';
}

int main(){
    char old[] = "hello";
    char New[6];
    split_string(New,old,2);
    cout<<New<<endl;

}