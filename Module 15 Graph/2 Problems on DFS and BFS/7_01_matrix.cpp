//LC 542
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> ans(n,vector<int>(m,-1));
        // vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;   // {position}, distance enlapsed

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    // vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first.first;
            int col=node.first.second;
            int dist=node.second;
            for(int i=0;i<4;i++){
                int x=row+dx[i];
                int y=col+dy[i];

                if(x<n && x>=0 && y>=0 && y<m && ans[x][y]==-1){
                    // vis[x][y]=1;
                    ans[x][y]=dist+1;
                    q.push({{x,y},dist+1});
                }
            }            
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid={  
        {1,1,0,0,1,1},
        {1,1,1,0,1,1},
        {0,0,1,1,1,1},
        {0,0,1,1,1,1},
        {0,0,1,1,1,1},
        {1,1,1,1,1,1}
    };

    Solution obj;
    auto ans=obj.updateMatrix(grid);

    for(auto it:ans){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}