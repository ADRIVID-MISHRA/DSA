//LC 137
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int singleNumberBetter(vector<int>& nums) {
    int ans=0;
    for(int bitIndex=0;bitIndex<32;bitIndex++){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & (1<<bitIndex)) count++;
        }
        if(count%3){
            ans=ans|(1<<bitIndex);   //setting the ith bit in ans ||| ans+=(1<<bitIndex)
        }
    }
    return ans;
}

int singleNumberOptimal(vector<int> &nums){
    sort(nums.begin(),nums.end());

    for(int i=1;i<nums.size();i+=3){
        if(nums[i]!=nums[i-1]) return nums[i-1];
    }
    return nums[nums.size()-1];
}

int singleNumberBest(vector<int> &nums){
    int ones=0;
    int twos=0;
    for(int i=0;i<nums.size();i++){
        ones=(nums[i]^ones)&(~twos);
        twos=(nums[i]^twos)&(~ones);
    }
    return ones;
}

int main(){
    vector<int> nums={5,6,5,5,4,1,1,4,1,4};

    cout<<singleNumberBetter(nums)<<endl;
    cout<<singleNumberOptimal(nums)<<endl;
    cout<<singleNumberBest(nums);
    
    return 0;
}