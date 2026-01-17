#include<iostream>
#include<vector>
#include<map>
using namespace std;

int majority_brute(vector<int> nums){
    for(int i=0;i<nums.size();i++){
        int count=0;
        for(int j=i;j<nums.size();j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count>nums.size()/2) return nums[i];
    }
    return -1;
}

int majority_better(vector<int> nums){
    map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }
    for(auto i:mpp){
        if(i.second>nums.size()/2){
            return i.first;
        }
    }
    return -1;
}

int majority_optimal(vector<int> nums){
    int majority;
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(count==0){
            majority=nums[i];
            count=1;
        }
        else if(nums[i]==majority){
            count++;
        }else{
            count--;
        }
    }
    return majority;
}

int main(){
    vector<int> nums={2,2,3,3,5,6,3,3,3,3,3,3,3,3,2,2};

    cout<<majority_brute(nums)<<endl;
    cout<<majority_better(nums)<<endl;
    cout<<majority_optimal(nums)<<endl;


    return 0;
}