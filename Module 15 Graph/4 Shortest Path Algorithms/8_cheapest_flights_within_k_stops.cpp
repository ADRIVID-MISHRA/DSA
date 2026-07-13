//LC 787
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //make the graph
        vector<vector<pair<int,int>>> adj(n);  // from: {to,price}
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue< pair<int,pair<int,int>> > q; //stops, price, node
        vector<int> price(n,INT_MAX);

        q.push({-1,{0,src}});
        price[src]=0;

        while(!q.empty()){
            auto el=q.front();
            q.pop();
            int stops=el.first;
            int p=el.second.first;
            int node=el.second.second;

            if(stops==k) continue;

            for(auto it:adj[node]){
                int neigh=it.first;
                int cost=it.second;

                if(p+cost<price[neigh]){
                    price[neigh]=p+cost;
                    q.push({stops+1,{p+cost,neigh}});
                }
            }            
        }
        if(price[dst]!=INT_MAX) return price[dst];
        return -1;
    }
};

int main(){
    int n=5;
    vector<vector<int>> flights={
        {0,1,100},{1,2,100},{2,3,100},{3,4,100},
        {0,2,500},{0,3,700},{1,3,250},{2,4,200}
    };

    int src=0;
    int dst=4;
    int k=2;

    // Flight Graph
    //
    //          (100)        (100)        (100)        (100)
    //      0 ─────────► 1 ─────────► 2 ─────────► 3 ─────────► 4
    //      │             │             │
    //      │(500)        │(250)        │(200)
    //      ▼             ▼             ▼
    //      2 ─────────► 3 ─────────► 4
    //          (100)        (100)
    //
    // src = 0
    // dst = 4
    // k = 2

    Solution obj;
    cout<<obj.findCheapestPrice(n,flights,src,dst,k);

    return 0;
}