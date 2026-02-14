#include<iostream>
#include<vector>

using namespace std;

int ceil(vector<int> nums,int target){
    return nums[lower_bound(nums.begin(),nums.end(),target)-nums.begin()];
}

int floor(vector<int> nums,int target){
    int low=0;
    int high=nums.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]<=target){
            ans=nums[mid];
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,23,55,67,78,99};
    int target=65;   //in index 12
    cout<<ceil(arr,target)<<endl;
    cout<<floor(arr,target)<<endl;
    return 0;
}