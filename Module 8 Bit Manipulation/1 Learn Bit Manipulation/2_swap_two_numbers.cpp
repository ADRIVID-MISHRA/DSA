#include<iostream>

using namespace std;

void swapWithoutTemp(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

int main(){
    int a=23;
    int b=532;
    cout<<"Before swap: a="<<a<<"  b="<<b<<endl;
    swapWithoutTemp(a,b);
    cout<<"After swap: a="<<a<<"  b="<<b;
    return 0;
}