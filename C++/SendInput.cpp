#include <ApplicationServices/ApplicationServices.h>
void Press(int key);
void Release(int key);
void Click(int key);

int main(){
    Press(56);
    Click(6);
    Release(56);
}
void Press(int key){
    CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);

    CGEventRef evt 
}
