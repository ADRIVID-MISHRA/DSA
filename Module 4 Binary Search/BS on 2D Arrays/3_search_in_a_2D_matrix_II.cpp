#include<iostream>
#include<vector>

using namespace std;

vector<int> searchMatrixBrute(vector<vector<int>>& matrix, int target) {
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==target) return {i,j};
        }
    }
    return {-1,-1};
}

vector<int> searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        if(target<matrix[i][0] || target>matrix[i][m-1]) continue;

        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[i][mid]==target) return {i,mid};
            else if(matrix[i][mid]>target) high=mid-1;
            else low=mid+1;
        }
    }
    return {-1,-1};
}

vector<int> searchMatrixOptimal(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();

    int row=0;
    int col=m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target) return {row,col};
        else if(matrix[row][col]>target) col--;
        else row++;
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
    int target=11;

    vector<int> ans;
    ans=searchMatrixBrute(mat,target);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

    ans=searchMatrixBetter(mat,target);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

    ans=searchMatrixOptimal(mat,target);
    for(auto it:ans){
        cout<<it<<" ";
    }
    
    return 0;
}