#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
    void dfs(vector<vector<pair<int,int>>> &adj,int node,vector<int> &vis,stack<int> &st){
        vis[node]=1;
        
        for(auto neighbour:adj[node]){
            if(vis[neighbour.first]==0){    //node is not visited
                dfs(adj,neighbour.first,vis,st);
            }
        }
        st.push(node);   //Add to the stack while returning
    }
public:
    vector<int> shortestPath(vector<vector<pair<int,int>>> &adj,int src){
        int n=adj.size();       
        vector<int> vis(n,0); 
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis,st);
            }
        }

        //run the diatance algorithm(Node relaxation)
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto neigh:adj[node]){
                int v=neigh.first;
                int wt=neigh.second;

                if(dist[node]+wt < dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
        }
        return dist;
    }
};

int main(){ 
    int n=7,m=8; //Number of vertices and edges

    // {from, to, weight}
    vector<vector<int>> edges={
        {6,4,2},{6,5,3},{5,4,1},{4,0,3},
        {4,2,1},{0,1,2},{1,3,1},{2,3,3}
    };

    // Adjacency list: {neighbour, weight}
    vector<vector<pair<int,int>>> adj(n);

    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});   //Directed edge u->v with weight wt
    }

    //             6
    //           ↙   ↘
    //       (2)/     \(3)
    //         4 ←(1)─ 5
    //       ↙   ↘
    //   (3)/     \(1)
    //     0         2
    //     |         |
    //   (2)|       (3)
    //     |         |
    //     1 ──(1)──▶3

    Solution obj;
    vector<int> distances=obj.shortestPath(adj,6);
    for(int it:distances){
        cout<<it<<" ";
    }
    return 0;
}