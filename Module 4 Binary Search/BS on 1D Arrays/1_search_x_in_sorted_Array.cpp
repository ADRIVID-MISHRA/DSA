#include<iostream>
#include<vector>

using namespace std;

int binarySearchIterative(vector<int>& nums, int target) {
    int i=0;
    int j=nums.size()-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(target==nums[mid]) return mid;
        else if(target<nums[mid]) j=mid-1;
        else i=mid+1;
    }
    return -1;
}

int BS_recursive(vector<int> &nums,int low,int high,int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]>target) return BS_recursive(nums,low,mid-1,target);
    else return BS_recursive(nums,mid+1,high,target);
}

int search(vector<int>& nums, int target) {
    return BS_recursive(nums,0,nums.size()-1,target);
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,23,55,67,78,99};
    int target=67;   //in index 12
    cout<<binarySearchIterative(arr,target)<<endl;
    cout<<search(arr,target);
    return 0;
}