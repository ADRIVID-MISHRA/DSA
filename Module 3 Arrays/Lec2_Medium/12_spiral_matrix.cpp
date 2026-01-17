#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> ret;
    int top=0,bottom=n-1;
    int left=0,right=m-1;
    while(right>=left && top<=bottom){
        //right
        for(int i=left;i<=right;i++){
            ret.push_back(matrix[top][i]);
        }
        top++;
        //bottom
        for(int i=top;i<=bottom;i++){
            ret.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            //left
            for(int i=right;i>=left;i--){
                ret.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            //top
            for(int i=bottom;i>=top;i--){
                ret.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ret;
}

int main(){
    vector<vector<int>> arr={
        {23,98,12},
        {98,12,34},
        {34,0,23}
    };
    vector<int> ans=spiralOrder(arr);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}