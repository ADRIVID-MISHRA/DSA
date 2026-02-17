#include<iostream>
#include<vector>

using namespace std;

int singleNonDuplicateBrute(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];  //only one element in array
    if(nums[0]!=nums[1]) return nums[0];   //first element check
    if(nums[n-1]!=nums[n-2]) return nums[n-1];    //last element check
    for(int i=1;i<n-1;i++){
        if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) return nums[i];
    }
    return -1;
}


int singleNonDuplicateOptimal(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];   //if mid is answer
        if(mid%2==0){ //mid is even
            if(nums[mid]==nums[mid+1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }else{ //mid is odd
            if(nums[mid]==nums[mid-1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr={1,1,2,2,3,3,4,5,5};
    cout<<singleNonDuplicateBrute(arr)<<endl;
    cout<<singleNonDuplicateOptimal(arr);
    return 0;
}