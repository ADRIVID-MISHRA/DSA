//LC 1334
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Dijkstra Solution

// class Solution {
//     vector<int> dijkstra(vector<vector<pair<int,int>>> &adj,int src){
//         int n=adj.size();
//         priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //min heap for pair
//         vector<int> dist(n,INT_MAX);                                                       //{dist,node}

//         pq.push({0,src});
//         dist[src]=0;

//         while(!pq.empty()){
//             int d=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();

//             if(d>dist[node]) continue; //Optimization: This skips outdated entries
            
//             for(auto neighbour:adj[node]){
//                 int neigh=neighbour.first;
//                 int wt=neighbour.second;

//                 if(wt+d<dist[neigh]){
//                     dist[neigh]=wt+d;
//                     pq.push({wt+d,neigh});
//                 }
//             }
//         }
//         return dist;
//     }
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<pair<int,int>>> adj(n);  //{neigh,weight}
//         for(auto it:edges){
//             adj[it[0]].push_back({it[1],it[2]});
//             adj[it[1]].push_back({it[0],it[2]});
//         }

//         vector<vector<int>> cost;
//         for(int i=0;i<n;i++){
//             cost.push_back(dijkstra(adj,i));
//         }

//         int count=INT_MAX;
//         int city=0;
//         for(int i=0;i<n;i++){
//             int cnt=0;
//             for(int j=0;j<n;j++){
//                 if(cost[i][j]<=distanceThreshold){
//                     cnt++;
//                 }
//             }
//             if(cnt<=count){
//                 count=cnt;
//                 city=i;
//             }
//         }
//         return city;
//     }
// };



//Floyd Warshall algorithm
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX)); 
    
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            adj[u][v]=wt;
            adj[v][u]=wt;   //Bi directional graph
        }
        //making the diagonal 0
        for(int i=0;i<n;i++) adj[i][i]=0;

        //floyd warshall
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][via]!=INT_MAX && adj[via][j]!=INT_MAX){
                        adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);                    
                    }
                }
            }
        }

        int count=INT_MAX;
        int city=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=count){
                count=cnt;
                city=i;
            }
        }
        return city;
    }
};

int main(){
    int n=6,m=8; // Number of vertices and edges

    // {u, v, weight}
    vector<vector<int>> edges={
        {0,1,4},{0,2,3},{1,2,1},{1,3,2},
        {2,4,4},{3,4,2},{3,5,3},{4,5,1}
    };

    //              0
    //           /     \
    //       (4)/       \(3)
    //         1──(1)───2
    //         |         |
    //      (2)|       (4)|
    //         |         |
    //         3──(2)───4
    //          \       /
    //        (3)\     /(1)
    //             \   /
    //               5

    int distanceThreshold=4;

    Solution obj;
    cout<<obj.findTheCity(n,edges,distanceThreshold);
    
    return 0;
}