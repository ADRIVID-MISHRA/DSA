//LC 260
#include<iostream>
#include<vector>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    long long num=0;
    for(auto it:nums){
        num=num^it;
    }
    int mask=(num&(num-1))^num;   // (num-1) may overflow when num==INT_MIN, so num is taken as long long

    int bucket1=0,bucket2=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]&mask) bucket1^=nums[i];
        else bucket2^=nums[i];
    } 
    return {bucket1,bucket2};
}

int main(){
    vector<int> nums={1,2,1,3,2,5};
    vector<int> ans=singleNumber(nums);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}