#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

string decimalToBinary(int num){
    if(num==0) return "0";
    string res;
    while(num>0){
        if(num%2==0) res+="0";
        else res+="1";

        num/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int binaryToDecimal(string bin){
    int num=0;
    int p2=1;
    // reverse
    for(int i=bin.size()-1;i>=0;i--){
        if(bin[i]=='1'){
            // num+=pow(2,(bin.size()-i-1));
            num+=p2;
        }
        p2=p2*2;   //Do the power of 2 calculation automatically
    }
    return num;
}

int main(){
    int decimal=13;
    string binary=decimalToBinary(decimal);
    cout<<binary<<endl;

    int convertedDecimal=binaryToDecimal(binary);
    cout<<convertedDecimal<<endl;
    return 0;
}