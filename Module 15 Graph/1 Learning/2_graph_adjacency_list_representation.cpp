#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    // vector<int> adj[n+1];
    vector<vector<int>> adj(n+1); //modern alternative of above line
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //comment out for directed graph
    }
    return 0;
}