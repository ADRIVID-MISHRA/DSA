#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
    void addShape(vector<vector<int>> &grid,vector<vector<int>> &vis,
        vector<pair<int,int>> &shape,int &baseRow,int &baseCol,int row,int col,int n,int m){
        
        vis[row][col]=1;
        shape.push_back({row-baseRow,col-baseCol});

        for(int i=0;i<4;i++){
            int x=row+dx[i];
            int y=col+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1){
                addShape(grid,vis,shape,baseRow,baseCol,x,y,n,m);
            }
        }
    }

public:
    int distinctIslands(vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){ 
                    vector<pair<int,int>> shape;
                    addShape(grid,vis,shape,i,j,i,j,n,m);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};

int main(){
    vector<vector<int>> grid = {   //3 distinct islands
        {1,1,0,0,0,1},  
        {1,1,1,0,1,0},
        {0,0,0,0,1,0},
        {0,1,1,0,0,0},
        {0,1,1,1,0,1},
        {0,0,0,0,0,1}
    };

    Solution obj;
    cout<<obj.distinctIslands(grid);

    return 0;
}