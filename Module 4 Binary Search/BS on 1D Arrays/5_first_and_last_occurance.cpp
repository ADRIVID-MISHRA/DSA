#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> occuranceBrute(vector<int> nums,int target){
    int first=-1;
    int last=-1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            if(first==-1) first=i;
            last=i;
        }
    }
    return {first,last};
}

vector<int> occuranceBS_optimal(vector<int>& nums, int target) {
    int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    if(first==nums.size() || nums[first]!=target) return {-1,-1};
    int last=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
    return {first,last};
}

int main(){
    vector<int> arr={1,2,3,4,4,4,4,5,6,7,8,9,10,23,55,67,78,99};
    int target=4;   
    vector<int> ans1=occuranceBrute(arr,target);
    cout<<ans1[0]<<"  "<<ans1[1]<<endl;

    vector<int> ans2=occuranceBS_optimal(arr,target);
    cout<<ans2[0]<<"  "<<ans2[1]<<endl;
    return 0;
}