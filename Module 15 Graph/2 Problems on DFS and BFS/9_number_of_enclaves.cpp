//LC 1020
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
    void mark(vector<vector<int>>& grid,int row,int col,int n, int m){
        grid[row][col]=0;   
        for(int i=0;i<4;i++){
            int x=row+dx[i];
            int y=col+dy[i];

            if(x<n && x>=0 && y>=0 && y<m && grid[x][y]==1){
                mark(grid,x,y,n,m);
            } 
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        //Treverse first and last row
        for(int j=0;j<m;j++){
            //first row
            if(grid[0][j]==1) mark(grid,0,j,n,m);
            //last row
            if(grid[n-1][j]==1) mark(grid,n-1,j,n,m);
        }

        //Treverse first and last column
        for(int i=1;i<n-1;i++){
            //firat column
            if(grid[i][0]==1) mark(grid,i,0,n,m);
            //last column
            if(grid[i][m-1]==1) mark(grid,i,m-1,n,m);
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};

int main(){
    vector<vector<int>> grid = {
        {0,0,0,0,0,0},
        {0,1,1,0,1,0},
        {0,1,0,0,1,0},
        {0,1,1,0,1,0},
        {0,0,0,0,1,0},
        {0,0,0,0,1,0}
    };

    Solution obj;
    cout<<obj.numEnclaves(grid);

    return 0;
}