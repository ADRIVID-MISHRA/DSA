#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int upperBound(vector<int> nums,int target){
    int ans=nums.size();
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,23,55,67,78,99};
    int target=67;   //in index 12
    cout<<arr[upperBound(arr,target)]<<endl;
    cout<<arr[upper_bound(arr.begin(),arr.end(),target)-arr.begin()];
    return 0;
}