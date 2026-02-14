#include<iostream>
#include<vector>

using namespace std;

int searchInsertPosition(vector<int>& nums, int target) {
    return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
}

int main(){
    vector<int> arr={1,2,3,4,4,4,4,4,5,6,7,8,9,10,23,55,67,78,99};
    int target=4;

    cout<<searchInsertPosition(arr,target);
    return 0;
}