#include<iostream>
#include<vector>

using namespace std;

vector<int> peakElementBS(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();

    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=(low+high)/2;

        int maxElement=-1;
        int maxIndex=0;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxElement){
                maxElement=mat[i][mid];
                maxIndex=i;
            }
        }
        int left=(mid>0)?mat[maxIndex][mid-1] : -1;
        int right=(mid<m-1)?mat[maxIndex][mid+1]:-1;

        // if(mid>0){
        //     left=mat[maxIndex][mid-1];
        // }
        // if(mid<mat[0].size()-1){
        //     right=mat[maxIndex][mid+1];
        // }

        if(left<maxElement && right<maxElement) return {maxIndex,mid};
        else if(left>maxElement) high=mid-1;
        else low=mid+1; 
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat={
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    vector<int> ans=peakElementBS(mat);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
