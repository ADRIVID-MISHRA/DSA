//LC 994
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }

        int time=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int x=node.first+dx[j];
                    int y=node.second+dy[j];

                    if(x<n && x>=0 && y>=0 && y<m && grid[x][y]==1){
                        fresh--;
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            if(!q.empty()) time++;
        }
        return (fresh==0)?time:-1;
    }
};

int main(){
    vector<vector<int>> grid={  
        {1,1,0,0,2,2},
        {1,1,1,0,2,2},
        {0,0,1,1,1,0},
        {0,0,1,0,0,0},
        {0,0,1,1,1,1},
        {1,1,1,0,1,1}
    };

    Solution obj;
    cout<<obj.orangesRotting(grid);

    return 0;
}