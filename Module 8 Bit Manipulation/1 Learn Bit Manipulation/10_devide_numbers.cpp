//LC 231
#include<iostream>

using namespace std;

int divide(int dividend, int divisor) {
    // long long ans=(long long)dividend/divisor;
    // if(ans>INT_MAX) return INT_MAX;
    // if(ans<INT_MIN) return INT_MIN;
    // return ans;

    

    // if(dividend == INT_MIN && divisor == -1){
    //         return INT_MAX;
    //     }
    //     return dividend/divisor;



    if(dividend==divisor) return 1;
    bool sign=true;     //true means posetive
    if(dividend<0 && divisor>0) sign=false;    //false means negetive
    if(dividend>0 && divisor<0) sign=false;

    long long n=abs((long long)dividend);
    long long d=abs((long long)divisor);
    long long ans=0;
    while(n>=d){
        long long count=0;
        while(n >= ( d<<(count+1) ) ) count++;   //d*pow(2,count+1)

        ans+=(1<<count);   //ans=ans+pow(2,count)
        n-=(d<<count);  //d*pow(2,count)
    }
    if(ans==(1<<31)){
        if(sign) return INT_MAX;
        else return INT_MIN;
    }
    return sign?ans:-ans;
}

int main(){
    cout<<divide(7,-3);

    return 0;
}