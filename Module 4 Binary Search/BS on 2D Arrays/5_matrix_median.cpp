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

int countElements(vector<vector<int>> &mat, int mid){
    int total=0;
    for(int i=0;i<mat.size();i++){
        total+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
    }
    return total;
}

int matrixMedianBS(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();

    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0;i<n;i++){    //scan left column for min and right column for max element
        low=min(low,mat[i][0]);
        high=max(high,mat[i][m-1]);
    }
    
    while(low<=high){
        int mid=(low+high)/2;
        if(countElements(mat,mid)>(m*n/2)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
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
    cout<<matrixMedianBS(mat);
    return 0;
}