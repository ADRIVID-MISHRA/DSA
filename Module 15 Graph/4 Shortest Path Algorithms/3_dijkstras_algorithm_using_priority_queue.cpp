#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>> &adj,int src){
        int n=adj.size();
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //min heap for pair
        vector<int> dist(n,INT_MAX);                                                       //{dist,node}

        pq.push({0,src});
        dist[src]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(d>dist[node]) continue; //Optimization: This skips outdated entries
            
            for(auto neighbour:adj[node]){
                int neigh=neighbour.first;
                int wt=neighbour.second;

                if(wt+d<dist[neigh]){
                    dist[neigh]=wt+d;
                    pq.push({wt+d,neigh});
                }
            }
        }
        return dist;
    }
};

int main(){ 
    int n=7,m=8; // Number of vertices and edges

    // {u, v, weight}
    vector<vector<int>> edges={
        {6,4,2},{6,5,3},{5,4,1},{4,0,3},
        {4,2,1},{0,1,2},{1,3,1},{2,3,3}
    };

    // Adjacency List: {neighbour, weight}
    vector<vector<pair<int,int>>> adj(n);

    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});  
    }

    //               6
    //            /   \
    //        (2)/     \(3)
    //          4──(1)──5
    //        /   \
    //    (3)/     \(1)
    //      0       2
    //      |       |
    //    (2)|     (3)
    //      |       |
    //      1──(1)──3

    Solution obj;
    vector<int> distances=obj.dijkstra(adj,0);
    for(int it:distances){
        cout<<it<<" ";
    }

    return 0;
}