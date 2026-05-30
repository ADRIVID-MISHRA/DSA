#include<iostream>

using namespace std;

void removeLastBit(int &n){
    n=n&(n-1);
}

int main(){
    int n=40;

    cout<<"Current value of n: "<<n<<endl;
    removeLastBit(n);
    cout<<"After removing last set bit, value of n: "<<n<<endl;

    return 0;
}