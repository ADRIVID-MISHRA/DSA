//EXACTLY SAME AS SPLIT ARRAY LARGEST SUM PROBLEM NUMBER 10(PREVIOUS PROBLEM)  ::: REFER THAT












#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

bool isPossible(vector<int> &nums, int k,int sum){
    int tempSum=0,divisions=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]+tempSum>sum){
            tempSum=nums[i];
            divisions++;
        }else{
            tempSum+=nums[i];
        }
    }
    return divisions<=k;
}

int splitArrayLS(vector<int> nums,int k){
    int maxi=*max_element(nums.begin(),nums.end());
    int sum=accumulate(nums.begin(),nums.end(),0);
    for(int i=maxi;i<=sum;i++){
        if(isPossible(nums,k,i)) return i;
    }
    return -1;
}

int splitArrayBS(vector<int>& nums, int k) {
    // if(nums.size()<k) return -1;
    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(nums,k,mid)) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    vector<int> arr={25,46,28,49,24};
    int k=4;
    cout<<splitArrayLS(arr,k)<<endl;
    cout<<splitArrayBS(arr,k);
    return 0;
}