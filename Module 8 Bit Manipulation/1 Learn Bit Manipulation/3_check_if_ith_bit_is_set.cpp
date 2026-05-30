#include<iostream>

using namespace std;

bool isIthBitSetLeftShift(int n,int i){
    return (n & (1<<i))!=0;   //true ig not zero(set)
}

bool isIthBitSetRightShift(int n,int i){
    return ((n>>i)&1)==1;
}

int main(){
    int n=13;
    int i=2;
    cout<<boolalpha<<isIthBitSetLeftShift(n,i)<<endl;
    cout<<boolalpha<<isIthBitSetRightShift(n,i)<<endl;
    return 0;
}