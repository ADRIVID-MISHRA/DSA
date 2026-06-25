#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    bool detectCycle(vector<vector<int>> &adj,int node,int parent,vector<int> &vis){
        vis[node]=1;
        for(int neighbour:adj[node]){
            if(neighbour!=parent){
                if(vis[neighbour]) return true;
                if(detectCycle(adj,neighbour,node,vis)) return true;
            }
        }
        return false;
    }
public:
    bool detectCycleConnectedComponents(vector<vector<int>> &adj){
        int n=adj.size();
        vector<int> vis(n,0);
        for(int i=1;i<n;i++){
            if(!vis[i]){
                if(detectCycle(adj,i,-1,vis)) return true;
            }
        }
        return false;
    }
};

int main(){
    int n=10,m=14;

    vector<pair<int,int>> edges={
        {1,2},{1,3},{2,4},{2,5},{3,5},{3,6},{4,7},
        {5,7},{5,8},{6,8},{7,9},{8,9},{8,10},{9,10}
    };

    vector<vector<int>> adj(n+1);

    for(auto [u,v]:edges){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4    5   6
    //     \ / \ /
    //      7   8
    //       \ / \
    //        9   10

    Solution sol;
    cout<<boolalpha<<sol.detectCycleConnectedComponents(adj);
    return 0;
}