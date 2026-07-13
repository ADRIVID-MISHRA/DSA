//LC 743
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //min heap for pair
        vector<int> dist(n+1,INT_MAX);                                                       //{dist,node}

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(d>dist[node]) continue; //Optimization: This skips outdated entries
            
            for(const auto neighbour:adj[node]){
                int neigh=neighbour.first;
                int wt=neighbour.second;

                if(wt+d<dist[neigh]){
                    dist[neigh]=wt+d;
                    pq.push({wt+d,neigh});
                }
            }
        }
        int maxTimeTaken=0;
        for(int i=1;i<=n;i++){   //1 indexed
            maxTimeTaken=max(maxTimeTaken,dist[i]);
        }
        return (maxTimeTaken==INT_MAX)?-1:maxTimeTaken;
    }
};

int main(){ 
    int n=7,m=8; // Number of vertices and edges

    // {u, v, time}
    vector<vector<int>> times={
        {7,5,2},{7,6,3},{6,5,1},{5,1,3},
        {5,3,1},{1,2,2},{2,4,1},{3,4,3}
    };

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
    cout<<obj.networkDelayTime(times,n,7);

    return 0;
}