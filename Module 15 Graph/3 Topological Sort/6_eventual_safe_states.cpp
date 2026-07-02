//LC 802
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class BFS{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse the graph
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0); 

        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i); 
                indegree[i]++;     //initialize the indegree in same loop
            }
        }

        //Run topo sort
        queue<int> q;
        for(int i=0;i<n;i++){      //initialize queue
            if(indegree[i]==0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();

            for(auto neighbour:adj[node]){    //remove node from indegree
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};


class DFS{
    bool dfs(vector<vector<int>> &graph,int node,vector<int> &vis,vector<int> &isSafe){
        vis[node]=2;
        for(int neighbour:graph[node]){
            if(vis[neighbour]==0){    //note is not visited
                if(dfs(graph,neighbour,vis,isSafe)){
                    // isSafe[node]=0;
                    return true;
                }
            }
            else if(vis[neighbour]==2){
                // isSafe[node]=0;
                return true;   //node is visited on the same path
            }
        }
        vis[node]=1;
        isSafe[node]=1;   //all the path have been successfully explored without cycles, so node is safe
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);  //0->not visited 1->visited 2->path visited and visited
        vector<int> isSafe(n,0);    //0->not safe(not decided)   1->safe node
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,i,vis,isSafe);
            }
        }

        vector<int> safeNode;
        for(int i=0;i<n;i++){
            if(isSafe[i]==1) safeNode.push_back(i);
        }
        return safeNode;
    }
};

int main(){
    int n=11,m=13;

    vector<vector<int>> edges={
        {0,1},{1,2},{1,3},{2,4},{2,5},{3,5},
        {3,6},{4,7},{5,8},{6,8},{8,9},{9,10},
        {10,8}   // Cycle
    };

    vector<vector<int>> adj(n);   // 0 indexed -> vertices from 0 to 10

    for(auto it:edges){
        adj[it[0]].push_back(it[1]);   // Directed edge
    }

    //            0
    //           |
    //           1
    //        ↙   ↘
    //       2     3
    //      ↙ ↘   ↙ ↘
    //     4    5    6
    //      ↓   ↘   ↙
    //      7     8
    //           /  ↓
    //         10 ← 9
    //
    // Cycle: 8 → 9 → 10 → 8

    BFS obj1;
    vector<int> safeStates=obj1.eventualSafeNodes(adj);
    for(int it:safeStates){
        cout<<it<<" ";
    }
    cout<<endl;

    DFS obj2;
    safeStates=obj2.eventualSafeNodes(adj);
    for(int it:safeStates){
        cout<<it<<" ";
    }
    return 0;
}