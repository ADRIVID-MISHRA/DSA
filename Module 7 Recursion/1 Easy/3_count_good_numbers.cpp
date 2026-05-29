//LC 1922
#include<iostream>

using namespace std;

class Solution {
public:
    int mod=1000000007;
    int countGoodNumbersOptimal(long long n) {
        long long evens=(n+1)/2;  //ceil
        long long odds=n/2;   //floor
        return (myPow(5,evens)*myPow(4,odds))%mod;
    }
    long long myPow(long long x,long long n){
        long long ans=1;
        while(n!=0){
            if(n%2!=0){
                ans=(ans*x) % mod;
            }
            x=(x*x) % mod;
            n=n/2;
        }
        return ans;
    }

    //recursive brute approach
    int MOD=1000000007;
    int countGoodNumbersRecursive(long long n) {
        return countRec(0,n);
    }

    int countRec(int index,int n){
        if(index==n) return 1;
        int ans=0;
        if(index%2==0){
            for(int i=0;i<5;i++){
                ans+=countRec(index+1,n)%MOD;
            }
        }else{
            for(int i=0;i<4;i++){
                ans+=countRec(index+1,n)%MOD;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;

    cout<<obj.countGoodNumbersOptimal(5)<<endl;
    cout<<obj.countGoodNumbersRecursive(50);
    return 0;
}