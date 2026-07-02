#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    vector<int> shortestPath(vector<vector<int>> &adj,int src){
        int n=adj.size();
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<int> q; //node
        q.push(src);

        while(!q.empty()){
            int node=q.front();
            int distance=dist[node];
            q.pop();

            for(int neigh:adj[node]){
                if(dist[neigh] > distance+1){
                    dist[neigh]=distance+1;
                    q.push(neigh);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};

int main(){
    int n=11,m=15;

    vector<pair<int,int>> edges={
        {0,1},{1,2},{1,3},{2,4},{2,5},{3,5},{3,6},{4,7},
        {5,7},{5,8},{6,8},{7,9},{8,9},{8,10},{9,10}
    };

    vector<vector<int>> adj(n);

    for(auto [u,v]:edges){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //         0
    //         |
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4    5   6
    //     \ / \ /
    //      7   8
    //       \ / \
    //        9   10

    Solution obj;
    vector<int> ans=obj.shortestPath(adj,0);
    for(int it:ans){
        cout<<it<<" ";
    }
    return 0;
}