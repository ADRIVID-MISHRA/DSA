#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    int timer=1;
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &time,vector<int> &low,vector<int> &vis,vector<int> &mark){
        vis[node]=1;
        time[node]=timer;
        low[node]=timer;
        timer++;

        int child=0;
        for(int neigh:adj[node]){
            if(neigh==parent) continue;
            if(vis[neigh]==0){  //not visited
                dfs(neigh,node,adj,time,low,vis,mark);
                low[node]=min(low[neigh],low[node]);
 
                if(time[node] <= low[neigh] && parent!=-1){  //aarticulation point condition for node
                    mark[node]=1;
                }
                child++;
            }else{
                low[node]=min(time[neigh],low[node]);  //changes in logic
            }
        }
        if(child>1 && parent==-1) mark[node]=1;  //start node logic
    }
public:
    vector<int> articulationPoints(int n, vector<vector<int>>& connections) {
        //form the graph
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> mark(n,0);   //mark the nodes that are articulation points as 1
        vector<int> time(n);
        vector<int> low(n);
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){   //for multi-component graph
            if(!vis[i]) dfs(i,-1,adj,time,low,vis,mark);
        }
        
        vector<int> points;   //collect all the articulation points, done to avoid repetation of points in the answer
        for(int i=0;i<n;i++){
            if(mark[i]!=0) points.push_back(i);
        }
        if(points.size()==0) return {-1};  //no points
        return points;
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
    vector<int> points;
    points=obj.articulationPoints(n,connections);

    for(auto it:points){
        cout<<it<<" ";
    }

    return 0;
}