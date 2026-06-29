#include<iostream>
#include<vector>

using namespace std;

class Solution{
    bool dfs(vector<vector<int>> &adj,int node,vector<int> &vis,vector<int> &pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(int neighbour:adj[node]){
            if(!vis[neighbour]){    //note is not visited
                if(dfs(adj,neighbour,vis,pathVis)) return true;
            }
            else if(pathVis[neighbour]) return true;   //node is visited on the same path
        }
        pathVis[node]=0;
        return false;  
    }
public:
    bool detectCycle(vector<vector<int>> &adj){
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for(int i=1;i<n;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis,pathVis)) return true;
            }
        }
        return false;
    }
};

int main(){
    int n=10,m=11;

    vector<pair<int,int>> edges={
        {1,2},{1,3},{2,4},{2,5},{3,5},{3,6},
        {4,7},{5,8},{6,8},{8,9},{9,10},
        {10,8}   // Cycle
    };

    vector<vector<int>> adj(n+1);

    for(auto [u,v] : edges){
        adj[u].push_back(v);   // Directed edge u -> v
    }

    //          1
    //        ↙   ↘
    //       2     3
    //      ↙ ↘   ↙ ↘
    //     4   5     6
    //      ↓   ↘   ↙
    //      7     8
    //           /  ↓
    //         10 ← 9
    //
    // Cycle: 8 → 9 → 10 → 8

    Solution sol;
    cout<<boolalpha<<sol.detectCycle(adj);
    return 0;
}



//DFS solution to Course schedule problems USING SINGLE VISITED ARRAY

//LC 207 
// class Solution {
//     bool dfs(vector<vector<int>> &adj,int node,vector<int> &vis){
//         vis[node]=2;   //path visited
//         // pathVis[node]=1;
//         for(int neighbour:adj[node]){
//             if(vis[neighbour]==0){    //note is not visited
//                 if(!dfs(adj,neighbour,vis)) return false;
//             }
//             else if(vis[neighbour]==2) return false;   //node is visited on the same path
//         }
//         // pathVis[node]=0;
//         vis[node]=1;  //only visited not path visited
//         return true;  
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);

//         for(auto it: prerequisites){
//             adj[it[1]].push_back(it[0]);   // Directed edge u -> v
//         }

//         vector<int> vis(numCourses,0);    // 0-> not visited  1->visited    2->pathVisited 
//         // vector<int> pathVis(numCourses,0);
//         for(int i=0;i<numCourses;i++){
//             if(!vis[i]){
//                 if(!dfs(adj,i,vis)) return false;
//             }
//         }
//         return true;
//     }
// };







//LC 210
// class Solution {
//     bool dfs(vector<vector<int>> &adj,int node,vector<int> &vis,vector<int> &order){
//         vis[node]=2;   //path visited
        
//         for(int neighbour:adj[node]){
//             if(vis[neighbour]==0){    //note is not visited
//                 if(!dfs(adj,neighbour,vis,order)) return false;
//             }
//             else if(vis[neighbour]==2) return false;   //node is visited on the same path
//         }
//         // pathVis[node]=0;
//         order.push_back(node);
//         vis[node]=1;  //only visited not path visited
//         return true;  
//     }
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);

//         for(auto it: prerequisites){
//             adj[it[1]].push_back(it[0]);   // Directed edge u -> v
//         }

//         vector<int> vis(numCourses,0);    // 0-> not visited  1->visited    2->pathVisited 
//         vector<int> order;
        
//         for(int i=0;i<numCourses;i++){
//             if(!vis[i]){
//                 if(!dfs(adj,i,vis,order)) return {};
//             }
//         }
//         reverse(order.begin(),order.end());
//         return order;
//     }
// };