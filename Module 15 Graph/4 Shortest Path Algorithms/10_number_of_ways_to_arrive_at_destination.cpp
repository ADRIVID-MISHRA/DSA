//1976
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    int MOD=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(const auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});   //un-directed graph
        }

        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > pq; //min heap for pair
        vector<long long> dist(n,LLONG_MAX);                                                       //{dist,node}
        vector<int> ways(n,0);

        ways[0]=1;
        dist[0]=0;
        pq.push({0,0}); 

        while(!pq.empty()){
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(d>dist[node]) continue; //Optimization: This skips outdated entries
            
            for(const auto &neighbour:adj[node]){
                int neigh=neighbour.first;
                int wt=neighbour.second;
                
                if(wt+d<dist[neigh]){    //First time comming with this short distance
                    dist[neigh]=wt+d;
                    ways[neigh]=ways[node];
                    pq.push({wt+d,neigh});
                }
                else if(wt+d==dist[neigh]){   //another minimum distance path
                    ways[neigh]=(ways[neigh]+ways[node])% MOD;
                }
            }
        }
        return ways[n-1];
    }
};

int main(){
    int n=7,m=10; // Number of vertices and roads

    // {u, v, time}
    vector<vector<int>> roads={
        {0,1,2},{0,2,4},{1,2,1},{1,3,7},{2,4,3},
        {3,5,1},{4,5,2},{5,6,3},{4,6,5},{2,3,2}
    };

    //               0
    //            /     \
    //        (2)/       \(4)
    //          1──(1)──2
    //          |       |\
    //      (7) |       | \(2)
    //          |     (3)|  3
    //          |       | / \
    //          3──(1)──5   \(1)
    //             \     \   |
    //             (2)\   \(3)
    //                 4──(5)──6

    Solution obj;
    cout<<obj.countPaths(n,roads);

    return 0;
}