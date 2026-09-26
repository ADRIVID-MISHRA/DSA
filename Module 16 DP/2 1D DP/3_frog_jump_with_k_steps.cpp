#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int frogJumpKRecursive(int n,int k,vector<int> &heights){  //stairs 1 to n, heights[i-1] -> height of i th stair
    if(n==1) return 0;

    int mini=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i<1) break;
        mini=min(mini,frogJumpKRecursive(n-i,k,heights)+abs(heights[n-1]-heights[n-i-1]));
    }
    return mini;
}

int frogJumpKMemoization(int n,int k,vector<int> &heights,vector<int> &dp){
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];

    int mini=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i<1) break;
        mini=min(mini,frogJumpKMemoization(n-i,k,heights,dp)+abs(heights[n-1]-heights[n-i-1]));
    }
    return dp[n]=mini;
}

int frogJumpKTabulation(int n,int k,vector<int> &heights){
    vector<int> dp(n+1);
    dp[1]=0;

    for(int i=2;i<=n;i++){
        int minSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j<1) break;
            minSteps=min(minSteps,dp[i-j]+abs(heights[i-1]-heights[i-j-1]));
        }
        dp[i]=minSteps;
    }
    return dp[n];
}

int frogJumpKTabulationSpaceOptimized(int n,int k,vector<int> &heights){
    if(n==1) return 0;
    deque<int> lastKSteps(k);  // i th step(index 0) to kth step(index k-1)
    for(int i=2;i<=n;i++){
        int curr=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j<1) break;
            curr=min(curr,lastKSteps[k-j]+abs(heights[i-1]-heights[i-j-1]));  //k-j goes from index k-1 to index 0 when iteration->(j==k)
        }
        lastKSteps.push_back(curr);
        lastKSteps.pop_front();
    }
    return lastKSteps.back();
}

int main(){
    int n=4;
    int k=2;
    vector<int> heights={10, 20, 30, 10};

    //recursive solution
    cout<<frogJumpKRecursive(n,k,heights)<<endl;

    //DP memoization
    vector<int> dp(n+1,-1); //dp[i] holds the min energy path to i th stair
    cout<<frogJumpKMemoization(n,k,heights,dp)<<endl;

    cout<<frogJumpKTabulation(n,k,heights)<<endl;

    cout<<frogJumpKTabulationSpaceOptimized(n,k,heights);
    return 0;
}