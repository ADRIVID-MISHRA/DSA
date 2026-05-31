#include<iostream>

using namespace std;

void oddEven(int n) {
    if(n&1) cout<<"ODD";
    else cout<<"EVEN";
}

int main(){
    int n=33;
    oddEven(n);

    return 0;
}