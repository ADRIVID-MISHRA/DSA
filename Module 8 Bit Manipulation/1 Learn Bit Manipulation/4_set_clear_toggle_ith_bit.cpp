#include<iostream>

using namespace std;

void setIthBit(int &n,int i){
    n=n|(1<<i);
}

void clearIthBit(int &n,int i){
    n=n&(~(1<<i));
}

void toggle(int &n,int i){
    n=n^(1<<i); 
}

int main(){
    int n=9;
    int i=2;

    cout<<"Current value of n: "<<n<<endl;
    setIthBit(n,i);
    cout<<"After set value of n: "<<n<<endl;
    clearIthBit(n,i);
    cout<<"After clearing value of n: "<<n<<endl;

    toggle(n,i);
    cout<<"Toggled: "<<n<<endl;
    toggle(n,i);
    cout<<"Toggled: "<<n<<endl;
    toggle(n,i);
    cout<<"Toggled: "<<n<<endl;

    return 0;
}