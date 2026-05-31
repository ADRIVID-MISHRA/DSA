//LC 231
#include<iostream>

using namespace std;

bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    return (n&(n-1))==0;
}

int main(){
    int n=32;

    cout<<boolalpha<<isPowerOfTwo(n);

    return 0;
}