//LC 191
#include<iostream>

using namespace std;

int countBits(int n) {
    int count=0;
    while(n!=0){
        if(n&1) count++;
        n=n>>1;
    }
    return count;
}

int countBitsOptimal(int n){   //Kernighan's method (Brian Kernighan)
    int count=0;
    while(n!=0){
        count++;
        n=n&(n-1);
    }
    return count;
}

int main(){
    int n=32;

    cout<<__builtin_popcount(n)<<endl;
    cout<<countBits(n)<<endl;
    cout<<countBitsOptimal(n);

    return 0;
}