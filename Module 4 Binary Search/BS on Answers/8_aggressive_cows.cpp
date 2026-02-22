#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool canWePlace(vector<int> nums,int cows,int gap){
    int placed=1;
    int lastPlacedIndex=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]-nums[lastPlacedIndex]>=gap){
            placed++;
            lastPlacedIndex=i;
        }
        if(placed>=cows) return true;
    }
    return placed>=cows;
}

int aggressiveCowsLS(vector<int> nums,int cows){
    sort(nums.begin(),nums.end());
    int min=nums[0];
    int max=nums[nums.size()-1];
    for(int i=1;i<=(max-min);i++){
        if(!canWePlace(nums,cows,i)) return i-1;
    }
    return (max-min);
}

int aggressiveCowsBS(vector<int> nums,int cows){
    sort(nums.begin(),nums.end());
    int low=1;
    int high=nums[nums.size()-1]-nums[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(canWePlace(nums,cows,mid)) low=mid+1;
        else high=mid-1;
    }
    return high;
}
int main(){
    vector<int> arr={0,3,4,7,10,9};
    int cows=4;
    cout<<aggressiveCowsLS(arr,cows)<<endl;
    cout<<aggressiveCowsBS(arr,cows);
    return 0;
}