//LC 136
#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    //HASHING APPROACH DONE IN ARRAYS
    // unordered_map<int,int> mpp;
    // for(auto it:nums){
    //     mpp[it]++;
    // }

    // for(auto it:mpp){
    //     if(it.second==1){
    //         return it.first;
    //     }
    // }

    // return -1;

    int XOR=0;
    for(int i=0;i<nums.size();i++){
        XOR=XOR^nums[i];
    }
    return XOR;
}

int main(){
    vector<int> nums={3,2,1,4,1,2,3};
    cout<<singleNumber(nums);
    return 0;
}