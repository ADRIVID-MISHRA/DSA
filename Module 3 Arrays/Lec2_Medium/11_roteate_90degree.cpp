#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate_brute(vector<vector<int>>& matrix) {
    vector<vector<int>> mat=matrix;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            matrix[j][matrix.size()-1-i]=mat[i][j];
        }
    }
}

void rotate_optimal(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
            // int j=0;
            // while(j<n/2){
            //     swap(matrix[i][j],matrix[i][n-j-1]);
            //     j++;
            // }
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

void print_matrix(vector<vector<int>> &nums){
    for(auto it:nums){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> arr={
        {23,98,12},
        {98,12,34},
        {34,0,23}
    };
    vector<vector<int>> arr2=arr;
    rotate_brute(arr);
    print_matrix(arr);
    cout<<endl;
    rotate_optimal(arr2);
    print_matrix(arr2);
    return 0;
}