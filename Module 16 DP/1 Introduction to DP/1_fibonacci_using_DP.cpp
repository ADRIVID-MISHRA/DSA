#include<iostream>
#include<vector>

using namespace std;

int fibonacciMemoization(int n,vector<int> &dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonacciMemoization(n-1,dp)+fibonacciMemoization(n-2,dp);
}

int fibonacciTabulation(int n){
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fibonacciTabulationSpaceOptimized(int n){
    int prev2=0;
    int prev1=1;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    int n=5;
    vector<int> dp(n+1,-1);
    cout<<fibonacciMemoization(n,dp)<<endl;
    
    cout<<fibonacciTabulation(n)<<endl;
    cout<<fibonacciTabulationSpaceOptimized(n);
    return 0;
}