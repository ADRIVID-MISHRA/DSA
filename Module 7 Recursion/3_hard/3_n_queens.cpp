//LC 51
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> curr(n,string(n,'.'));

        vector<int> leftRow(n,0);            //Declaring the hash arrays for all three directions
        vector<int> upperDiagonal(2*n-1,0);
        vector<int> lowerDiagonal(2*n-1,0);
        
        helper(result,curr,0,n,leftRow,upperDiagonal,lowerDiagonal); 
        return result;
    }
    void helper(vector<vector<string>> &result,vector<string> &curr,int col,int &n,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal){
        if(col==n){
            result.push_back(curr);
            return;
        }
        for(int row=0;row<n;row++){
            if(!leftRow[row] && !upperDiagonal[row+col] && !lowerDiagonal[n-1+col-row]){
                //mark hashes
                leftRow[row]=1;
                upperDiagonal[row+col]=1;
                lowerDiagonal[n-1+col-row]=1;

                //call recursve function
                curr[row][col]='Q';
                helper(result,curr,col+1,n,leftRow,upperDiagonal,lowerDiagonal);
                curr[row][col]='.';

                //unmark hashes
                leftRow[row]=0;
                upperDiagonal[row+col]=0;
                lowerDiagonal[n-1+col-row]=0;
            }
        }
    }

    //O(3n) placebility check instead of O(1)-> hash arrays
    // bool isPlaceble(vector<string> &curr,int row,int col,int n){
    //     int left=col;
    //     int right=col;
    //     for(int i=row;i>=0;i--){
    //         if(curr[i][col]=='Q') return false;
    //         if(left>=0 && curr[i][left--]=='Q') return false;
    //         if(right<n && curr[i][right++]=='Q') return false;
    //     }
    //     return true;
    // }
};

int main(){
    Solution sol;
    vector<vector<string>> result=sol.solveNQueens(4);
    for(auto it:result){
        for(auto s:it){
            cout<<s<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}