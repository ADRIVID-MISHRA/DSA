//LC 213
#include<iostream>
#include<vector>

using namespace std;

int houseRobberTabulationSpaceOptimized(vector<int>& nums){   //Optimal approach of House Robber 1 problem(previous problem)
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

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];

    vector<int> temp1,temp2;
 
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
    }
    return max(houseRobberTabulationSpaceOptimized(temp1),houseRobberTabulationSpaceOptimized(temp2));
}

int main(){
    vector<int> nums={1,2,3,1};
    cout<<rob(nums);
    
    return 0;
}