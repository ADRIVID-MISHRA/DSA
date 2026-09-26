//LC 198
#include<iostream>
#include<vector>

using namespace std;

int houseRobberRecursive(vector<int> &nums,int index){
    if(index==0) return nums[0];   //pick 0th index
    if(index==-1) return 0;   //out of bounds after picking 1st index

    int take=nums[index]+houseRobberRecursive(nums,index-2);
    int notTake=houseRobberRecursive(nums,index-1);
    return max(take,notTake);
}

int houseRobberMemoization(vector<int> &nums,int index,vector<int> &dp){
    if(index==0) return nums[0];   //pick 0th index
    if(index==-1) return 0;   //out of bounds after picking 1st index

    if(dp[index]!=-1) return dp[index];
    int take=nums[index]+houseRobberMemoization(nums,index-2,dp);
    int notTake=houseRobberMemoization(nums,index-1,dp);
    return dp[index]=max(take,notTake);
}

int houseRobberTabulation(vector<int>& nums) {
    int n=nums.size();

    vector<int> dp(n,0);  //0 to n-1 th index
    dp[0]=nums[0]; //Base case 1, when 0th index is taken
    int neg=0;  //Base case 2, when 0th index is not taken

    for(int i=1;i<n;i++){
        int take;
        if(i!=1) take=nums[i]+dp[i-2]; //can't take i-1 th index;
        else take=nums[i]+neg;
        int notTake=dp[i-1];

        dp[i]=max(take,notTake);
    }
    return dp[n-1];
}

int houseRobberTabulationSpaceOptimized(vector<int>& nums) {
    int n=nums.size();

    int prev1=nums[0];
    int prev2=0; //index = -1

    for(int i=1;i<n;i++){
        int take=nums[i]+prev2; //can't take i-1 th index;
        int notTake=prev1;
        int curr=max(take,notTake);

        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){ 
    vector<int> nums={2,1,4,9};  //optimal pick-> index 0 and index 3, total=11
    int n=nums.size();

    cout<<houseRobberRecursive(nums,n-1)<<endl;  //n-1 is the last index

    vector<int> dp(n,-1);  //0 to n-1 th index
    cout<<houseRobberMemoization(nums,n-1,dp)<<endl;  //n-1 is the last index

    cout<<houseRobberTabulation(nums)<<endl;

    cout<<houseRobberTabulationSpaceOptimized(nums);
    return 0;
}