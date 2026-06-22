#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &adj,int startNode,int n){
    queue<int> q;
    vector<int> vis(n+1,0);
    vector<int> bfs;

    q.push(startNode);
    vis[startNode]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(int neighbour:adj[node]){
            if(!vis[neighbour]){
                q.push(neighbour);
                vis[neighbour]=1;
            }
        }
    }
    return bfs;
}

int main(){
    // int n,m;
    // cin>>n>>m;

    // vector<vector<int>> adj(n+1); 
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u); 
    // }

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

    vector<int> traversal=bfs(adj,6,n);
    for(int it:traversal){
        cout<<it<<" ";
    }
    return 0;
} 