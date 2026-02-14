#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> occuranceBS_optimal(vector<int>& nums, int target) {
    int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    if(first==nums.size() || nums[first]!=target) return {-1,-1};
    int last=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
    return {first,last};
}

int noOfOccurances(vector<int> arr,int target){
    vector<int> nums=occuranceBS_optimal(arr,target);
    if(nums[0]==-1) return 0;
    else return(nums[1]-nums[0]+1);
}

int main(){
    vector<int> arr={1,2,3,4,4,4,4,4,5,6,7,8,9,10,23,55,67,78,99};
    int target=4;   
    
    cout<<noOfOccurances(arr,target);
    return 0;
}