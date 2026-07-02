#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    bool topoSort(vector<vector<int>>& adj) {
        int n=adj.size();       
        vector<int> indegree(n,0); 
        for(int i=0;i<n;i++){       //initialize the indegree
            for(int neigh:adj[i]){
                indegree[neigh]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){      //initialize queue
            if(indegree[i]==0) q.push(i);
        }

        int count=0;
        while(!q.empty()){
            int node=q.front();
            count++;
            q.pop();

            for(auto neighbour:adj[node]){    //remove node from indegree
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return count!=n;
    }
};

int main(){
    int n=11,m=13;

    vector<pair<int,int>> edges={
        {0,1},{1,2},{1,3},{2,4},{2,5},{3,5},{3,6},
        {4,7},{5,8},{6,8},{7,10},{8,9},{9,10}
    };

    vector<vector<int>> adj(n);   // 0 indexed -> vertices from 0 to 10

    for(auto [u,v] : edges){
        adj[u].push_back(v);   // Directed edge u -> v
    }

    //            0
    //           |
    //           1
    //        ↙   ↘
    //       2     3
    //      ↙ ↘   ↙ ↘
    //     4    5     6
    //      ↓   ↘   ↙
    //      7     8
    //       ↘     ↓
    //         10 ← 9     
    //
    // No Cycle. Graph is a DAG

    Solution sol;
    cout<<boolalpha<<sol.topoSort(adj);   //True -> there is cycle
                                        //False -> there is no cycle
    return 0;
}