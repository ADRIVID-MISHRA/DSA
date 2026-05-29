//LC 50
#include<iostream>

using namespace std;

class Solution {
public:
    //can do iteratively also till while(n!=0)
    // long long myPow(long long x,long long n){   //integrate the edge cases
    //     long long ans=1;
    //     while(n!=0){
    //         if(n%2!=0){
    //             ans=(ans*x) % mod;
    //         }
    //         x=(x*x) % mod;
    //         n=n/2;
    //     }
    //     return ans;
    // }
    double myPow(double x, int n) {
        long long nn=n;
        if(nn<0){
            nn=-nn;
            x=1/x;
        }
        return recPow(x,nn);
    }

    double recPow(double x,long long n){
        
        if(n==0) return 1;

        double half=recPow(x*x,n/2);
        if(n%2==0) return half;
        else{
            // return x*recPow(x,n-1);
            return x*half;
        }
    }
};

int main(){
    Solution obj;
    cout<<obj.myPow(2,-648);
}