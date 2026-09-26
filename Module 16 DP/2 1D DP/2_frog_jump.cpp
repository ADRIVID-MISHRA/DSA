#include<iostream>
#include<vector>

using namespace std;

int frogJumpRecursive(int n,vector<int> &heights){  //stairs 1 to n, heights[i-1] -> height of i th stair
    if(n==1) return 0;
    if(n==2) return abs(heights[1]-heights[0]);

    return min(frogJumpRecursive(n-1,heights)+abs(heights[n-1]-heights[n-2]),frogJumpRecursive(n-2,heights)+abs(heights[n-1]-heights[n-3]));
}

int frogJumpMemoization(int n,vector<int> &heights,vector<int> &dp){
    if(dp[n]!=-1) return dp[n];
    
    if(n==1) return dp[1]=0;
    if(n==2) return dp[2]=abs(heights[1]-heights[0]);

    return dp[n]=min(frogJumpMemoization(n-1,heights,dp)+abs(heights[n-1]-heights[n-2]),frogJumpMemoization(n-2,heights,dp)+abs(heights[n-1]-heights[n-3]));
}

int frogJumpTabulation(int n,vector<int> &heights){
    vector<int> dp(n+1);
    dp[1]=0;
    if(n>=2) dp[2]=abs(heights[1]-heights[0]);
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(heights[i-1]-heights[i-2]), dp[i-2]+abs(heights[i-1]-heights[i-3]));
    }
    return dp[n];
}

int frogJumpTabulationSpaceOptimized(int n,vector<int> &heights){
    if(n==1) return 0;
    int prev2=0;   // 1st stair
    int prev1=abs(heights[1]-heights[0]);  //2nd stair
    for(int i=3;i<=n;i++){
        int curr=min(prev1+abs(heights[i-1]-heights[i-2]), prev2+abs(heights[i-1]-heights[i-3]));
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    int n=4;
    vector<int> heights={10, 20, 30, 10};

    //recursive solution
    cout<<frogJumpRecursive(n,heights)<<endl;

    //DP memoization
    vector<int> dp(n+1,-1); //dp[i] holds the min energy path to i th stair
    cout<<frogJumpMemoization(n,heights,dp)<<endl;

    cout<<frogJumpTabulation(n,heights)<<endl;

    cout<<frogJumpTabulationSpaceOptimized(n,heights);
    return 0;
}