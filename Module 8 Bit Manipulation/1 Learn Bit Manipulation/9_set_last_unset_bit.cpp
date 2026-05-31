#include<iostream>

using namespace std;

void setLastBit(int &n){
    if(n&(n-1)==0) return;
    n=n|(n+1);
}

int main(){
    int n=11;

    cout<<"Current value of n: "<<n<<endl;
    setLastBit(n);
    cout<<"After setting last unset bit, value of n: "<<n<<endl;

    return 0;
}