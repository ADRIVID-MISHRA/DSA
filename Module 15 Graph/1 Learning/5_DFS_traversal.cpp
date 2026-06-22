#include<iostream>
#include<vector>

using namespace std;

class Solution{
    private:
    void dfs(vector<vector<int>> &adj,vector<int> &result,vector<int> &vis,int node){
        vis[node]=1;
        result.push_back(node);
        for(int neighbour:adj[node]){
            if(!vis[neighbour]){
                dfs(adj,result,vis,neighbour);
            }
        }
    }

    public:
    vector<int> dfsOfGraph(vector<vector<int>> &adj,int startNode,int n){
        vector<int> vis(n+1,0);
        vector<int> result;
        dfs(adj,result,vis,startNode);
        return result;
    }
};

int main(){
    int n=8,m=8;

    vector<pair<int,int>> edges={
        {1,2},{1,3},{2,5},{2,6},
        {3,4},{3,7},{4,8},{7,8}
    };

    vector<vector<int>> adj(n+1);

    for(auto [u,v]:edges){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //         1
    //       /   \
    //      2     3---4
    //     / \    |   |
    //    5   6   7---8

    Solution obj;
    vector<int> traversal=obj.dfsOfGraph(adj,1,n);
    for(int it:traversal){
        cout<<it<<" ";
    }
    return 0;
} 