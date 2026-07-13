//LC 1091
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0) return {-1};
        if(n==1) return 1;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int, pair<int,int>>> q; 

        dist[0][0]=1;
        q.push({1,{0,0}}); //dist,(row,col);   //Taking iniial distance as 1

        vector<int> dx={0,1,1,1,0,-1,-1,-1};
        vector<int> dy={1,1,0,-1,-1,-1,0,1};

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int d=node.first;
            int row=node.second.first;
            int col=node.second.second;

            for(int i=0;i<8;i++){
                int x=row+dx[i];
                int y=col+dy[i];

                if(x<n && x>=0 && y>=0 && y<n){ //within bounds
                    if(grid[x][y]==0 && d+1<dist[x][y]){
                        if(x==n-1 && y==n-1) return d+1;  //The destination is found
                        dist[x][y]=d+1;
                        q.push({d+1,{x,y}});
                    }
                }

            }
        }
        // if(dist[n-1][n-1]==INT_MAX) return {-1};
        return -1;   //not reachable
    }
};

int main(){
    vector<vector<int>> grid={
        {0,1,0,0,0,1,0,0},
        {0,0,0,1,0,1,0,1},
        {1,1,0,1,0,0,0,0},
        {0,0,0,0,1,1,1,0},
        {1,1,1,0,0,0,1,0},
        {0,0,1,1,1,0,0,0},
        {0,1,0,0,0,1,1,0},
        {1,0,0,1,0,0,0,0}
    };

    Solution obj;
    cout<<obj.shortestPathBinaryMatrix(grid);
    return 0;
}