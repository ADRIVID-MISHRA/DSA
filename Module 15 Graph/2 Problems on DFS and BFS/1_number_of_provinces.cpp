//LC 547
#include<iostream>
#include<vector>

using namespace std;

class Solution {
    void dfs(vector<vector<int>> &adj,vector<int> &vis,int node){
        vis[node]=1;
        for(int i=0;i<adj.size();i++){
            if(adj[node][i] && !vis[i]){
                dfs(adj,vis,i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                provinces++;
            }
        }
        return provinces;
    }
};

int main(){
    int n=6,m=3;

    vector<vector<int>> isConnected={
        {1,1,0,0,0,0},
        {1,1,0,0,0,0},
        {0,0,1,1,0,0},
        {0,0,1,1,0,0},
        {0,0,0,0,1,1},
        {0,0,0,0,1,1}
    };

    //     1---2
    //
    //     3---4
    //
    //     5---6

    Solution obj;
    cout<<obj.findCircleNum(isConnected);

    return 0;
}