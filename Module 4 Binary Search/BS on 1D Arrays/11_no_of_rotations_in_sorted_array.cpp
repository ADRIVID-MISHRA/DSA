#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int findMin(vector<int>& nums) {
    int low=0;
    int high=nums.size()-1;
    int ans=numeric_limits<int>::max();
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<=nums[high]){
            // ans=min(ans,nums[low]);
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
            }
            break;
        }
        //left is sorted
        if(nums[mid]>=nums[low]){
            // ans=min(ans,nums[low]);
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
            }
            low=mid+1;
        }
        //right is sorted
        else{
            // ans=min(ans,nums[mid]);
            if(nums[mid]<ans){
                ans=nums[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
}

int main(){
    vector<int> arr={4,5,1,2,3};
    cout<<findMin(arr);
    return 0;
}