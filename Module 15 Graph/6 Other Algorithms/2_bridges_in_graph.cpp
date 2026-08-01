//LC 1192
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    int timer=1;
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &time,vector<int> &low,vector<int> &vis,vector<vector<int>> &bridges){
        vis[node]=1;
        time[node]=timer;
        low[node]=timer;
        timer++;

        for(int neigh:adj[node]){
            if(neigh==parent) continue;
            if(vis[neigh]==0){  //not visited
                dfs(neigh,node,adj,time,low,vis,bridges);
                low[node]=min(low[neigh],low[node]);
 
                if(time[node] < low[neigh]){  //bridge condition
                    bridges.push_back({node,neigh});
                }
            }else{
                low[node]=min(low[neigh],low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //form the graph
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> bridges;
        vector<int> time(n);
        vector<int> low(n);
        vector<int> vis(n,0);

        dfs(0,-1,adj,time,low,vis,bridges);
        return bridges;
    }
};

int main(){
    int n=4;
    vector<vector<int>> connections={{0,1},{1,2},{2,0},{1,3}};
    //        0
    //       / \
    //      /   \
    //     1-----2
    //     |
    //     |
    //     3
    Solution obj;
    vector<vector<int>> bridges;
    bridges=obj.criticalConnections(n,connections);

    for(auto it:bridges){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}