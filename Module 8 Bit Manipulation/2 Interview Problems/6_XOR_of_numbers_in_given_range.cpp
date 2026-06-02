#include<iostream>

using namespace std;

int xorTillN(int n){
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    return n;  //if(n%4==0)
}

int xorLtoR(int l,int r){
    return xorTillN(l-1)^xorTillN(r);
}

int main(){
    cout<<xorLtoR(3,5); //3^4^5=2
    return 0;
}