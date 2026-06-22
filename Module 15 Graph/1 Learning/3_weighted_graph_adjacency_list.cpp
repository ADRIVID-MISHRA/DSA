#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    // vector<<pair<int,int>> adj[n+1];
    vector<vector<pair<int,int>>> adj(n+1); //modern alternative of above line
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); //comment out for directed graph
    }
    return 0;
}