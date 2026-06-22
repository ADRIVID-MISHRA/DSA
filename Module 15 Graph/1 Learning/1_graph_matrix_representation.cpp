#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    // int adj[n+1][m+1]; 
    vector<vector<int>> adj(n,vector<int>(m,0));  //modern alternative of above line
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][v]=1;   //comment out for directed graph 
    }
    return 0;
}