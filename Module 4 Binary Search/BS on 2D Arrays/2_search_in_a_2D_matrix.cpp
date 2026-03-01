#include<iostream>
#include<vector>

using namespace std;

bool searchMatrixBrute(vector<vector<int>>& matrix, int target) {
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==target) return true;
        }
    }
    return false;
}

bool searchMatrixBS(vector<vector<int>>& matrix, int target) {
    int n=matrix.size(),m=matrix[0].size();
    int low=0;
    int high=m*n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int midElement=matrix[mid/m][mid%m];
        if(midElement==target) return true;
        else if(midElement>target) high=mid-1;
        else low=mid+1;
    }
    return false;
}

int main(){
    vector<vector<int>> mat={
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target=11;

    cout<<boolalpha;
    cout<<searchMatrixBrute(mat,target)<<endl;
    cout<<searchMatrixBS(mat,target);
    return 0;
}