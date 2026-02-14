#include<iostream>
#include<vector>

using namespace std;

bool search(vector<int>& nums, int target) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return true;
        //Edge case
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
        }
        //left side is sorted
        else if(nums[low]<=nums[mid]){
            //if target present in left
            if(nums[low]<=target && nums[mid]>=target){
                high=mid-1;
            }else{    //target present in right
                low=mid+1;
            }
        }
        //right side is sorted
        else{
            //if target present in right
            if(nums[mid]<=target && nums[high]>=target){
                low=mid+1;
            }else{   //target present in left
                high=mid-1;
            }
        }
    }
    return false;
}


int main(){
    vector<int> arr={100,101,134,167,1,2,3,4,5,6,7,8,9,10,23,55,67,78,99};
    int target=4;  //at index 7

    cout<<boolalpha<<search(arr,target);
    return 0;
}