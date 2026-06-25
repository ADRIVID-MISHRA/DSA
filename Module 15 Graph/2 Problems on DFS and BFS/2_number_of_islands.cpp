//LC 200
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    vector<int> dx={0,1,1,1,0,-1,-1,-1};
    vector<int> dy={1,1,0,-1,-1,-1,0,1};
    void bfs(vector<vector<int>> &grid,vector<vector<int>> &vis,pair<int,int> node,int n,int m){
        queue<pair<int,int>> q;
        q.push(node);
        vis[node.first][node.second]=1;

        while(!q.empty()){
            auto pos=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int x=pos.first+dx[i];
                int y=pos.second+dy[i];

                if(x<n && x>=0 && y>=0 && y<m){ //within bounds
                    if(grid[x][y]==1 && !vis[x][y]){
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    bfs(grid,vis,{i,j},n,m);
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<int>> grid={   //3 islands are here
        {1,1,0,0,0,0},
        {1,1,0,0,0,0},
        {0,0,1,1,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,1,1},
        {1,1,0,0,1,1}
    };

    Solution obj;
    cout<<obj.numIslands(grid);

    return 0;
}


//LeetCode sollution without using an visited array, and just marking the elments in the grid '0' when they are visited
// class Solution {
//     const int dx[4]={0,1,0,-1};
//     const int dy[4]={1,0,-1,0};
//     void bfs(vector<vector<char>> &grid,pair<int,int> node,int n,int m){
//         queue<pair<int,int>> q;
//         q.push(node);
//         grid[node.first][node.second]='0';

//         while(!q.empty()){
//             auto pos=q.front();
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int x=pos.first+dx[i];
//                 int y=pos.second+dy[i];

//                 if(x<n && x>=0 && y>=0 && y<m){ //within bounds
//                     if(grid[x][y]=='1'){
//                         grid[x][y]=0;
//                         q.push({x,y});
//                     }
//                 }
//             }
//         }
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]=='1'){
//                     bfs(grid,{i,j},n,m);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };