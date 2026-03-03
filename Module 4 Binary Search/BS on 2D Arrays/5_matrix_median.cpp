#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int matrixMedianBrute(vector<vector<int>> &mat){
    vector<int> nums;
    for(auto it:mat){
        for(auto e:it){
            nums.push_back(e);
        }
    }
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}

int main(){
    vector<vector<int>> mat={
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    cout<<matrixMedianBrute(mat)<<endl;
    return 0;
}