#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    void dfs(vector<vector<int>> &adj,int node,vector<int> &vis,stack<int> &st){
        vis[node]=1;
        
        for(int neighbour:adj[node]){
            if(vis[neighbour]==0){    //node is not visited
                dfs(adj,neighbour,vis,st);
            }
        }
        st.push(node);   //Add to the stack while returning
    }
public:
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n=adj.size();       
        vector<int> vis(n,0); 
        stack<int> st;
        for(int i=1;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis,st);
            }
        }
        vector<int> sortedOrder;
        while(!st.empty()){
            sortedOrder.push_back(st.top());
            st.pop();
        }
        return sortedOrder;
    }
};

int main(){
    int n=10,m=12;

    vector<pair<int,int>> edges={
        {1,2},{1,3},{2,4},{2,5},{3,5},{3,6},
        {4,7},{5,8},{6,8},{7,10},{8,9},{9,10}
    };

    vector<vector<int>> adj(n+1);   // 1 indexed ->vertices from 1 to 10

    for(auto [u,v] : edges){
        adj[u].push_back(v);   // Directed edge u -> v
    }

    //          1
    //        ↙   ↘
    //       2     3
    //      ↙ ↘   ↙ ↘
    //     4    5     6
    //      ↓   ↘   ↙
    //      7     8
    //       ↘     ↓
    //         10 ← 9
    //
    // No Cycle. Graph is a DAG

    Solution sol;
    vector<int> result=sol.topoSort(adj);

    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}