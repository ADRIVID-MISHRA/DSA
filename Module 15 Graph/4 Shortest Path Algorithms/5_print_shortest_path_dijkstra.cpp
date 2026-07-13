#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> shortestPath(vector<vector<pair<int,int>>> &adj){
        int n=adj.size()-1;  //7 here
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++){   //0 to 7
            parent[i]=i;
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        dist[1]=0;
        pq.push({0,1});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(dist[node]<d) continue;

            for(auto it:adj[node]){
                int neigh=it.first;
                int nd=it.second;
                if(nd+d<dist[neigh]){
                    parent[neigh]=node;
                    dist[neigh]=nd+d;
                    pq.push({nd+d,neigh});
                }
            }
        }

        if(dist[n]==INT_MAX) return {-1};  //un-reachable destination node

        vector<int> result;
        int currNode=n;
        int srcNode=1;
        while(parent[currNode]!=currNode){
            result.push_back(currNode);
            currNode=parent[currNode];
        }
        result.push_back(srcNode);

        reverse(result.begin(),result.end());
        return result;
    }
};

int main(){ 
    int n=7,m=8; // Number of vertices and edges

    // {u, v, weight}
    vector<vector<int>> edges={
        {7,5,2},{7,6,3},{6,5,1},{5,1,3},
        {5,3,1},{1,2,2},{2,4,1},{3,4,3}
    };

    // Adjacency List: {neighbour, weight}
    vector<vector<pair<int,int>>> adj(n+1);   //1 indexed

    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});  
    }

    //               7
    //            /   \
    //        (2)/     \(3)
    //          5──(1)──6
    //        /   \
    //    (3)/     \(1)
    //      1       3
    //      |       |
    //    (2)|     (3)
    //      |       |
    //      2──(1)──4

    Solution obj;
    vector<int> path=obj.shortestPath(adj);   //from 1 to n
    for(int it:path){
        cout<<it<<" ";
    }

    return 0;
}