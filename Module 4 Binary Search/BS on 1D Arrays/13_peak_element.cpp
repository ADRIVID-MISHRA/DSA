#include<iostream>
#include<vector>

using namespace std;

int findPeakLinearSearch(vector<int> nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(  (i==0 || nums[i-1]<nums[i]) && (i==n-1 || nums[i]>nums[i+1]) )
            return i;
    }
    return -1;
}

int findPeakBS(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
            return mid;
        if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    cout<<findPeakLinearSearch(arr)<<endl;
    cout<<findPeakBS(arr);
    return 0;
}