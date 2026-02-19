#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool isPossible(vector<int> &nums,int threshold,int divisor){   //if sum of division less than/equal to threshold
    int count=0;
    for(int i=0;i<nums.size();i++){
        count+=ceil((double)nums[i]/divisor);
    }
    return count<=threshold;
}

int smallestDivisorBS(vector<int>& nums, int threshold) {
    if(threshold<nums.size()) return -1;
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(nums,threshold,mid)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int smallestDivisorLS(vector<int>& nums, int threshold) {
    if(threshold<nums.size()) return -1;
    int maxi=*max_element(nums.begin(),nums.end());
    for(int i=1;i<maxi;i++){
        if(isPossible(nums,threshold,i)){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> nums={1,2,5,9};
    int threshold=6;
    cout<<smallestDivisorLS(nums,threshold)<<endl;
    cout<<smallestDivisorBS(nums,threshold);
    return 0;
}