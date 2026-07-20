#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    pair<int,vector<vector<int>>> minSpanningTree(vector<vector<int>> &edges,int n){  //n is number of nodes (0 to n-1)
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});  //Undirected graph
        }

        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
                //{wt,node,parent}
        vector<int> vis(n,0);  //initialize all to not visited yet
        vector<vector<int>> mst; //Store the edges of the MST derived
        int sum=0;

        pq.push({0,{0,-1}});

        while(!pq.empty()){
            auto wt=pq.top().first;
            auto node=pq.top().second.first;
            auto parent=pq.top().second.second;
            pq.pop();

            if(vis[node]) continue;
            vis[node]=1;
            if(parent!=-1) mst.push_back({parent,node});  //not starting node
            sum+=wt;

            for(auto it:adj[node]){
                int neigh=it.first;
                int d=it.second;

                if(vis[neigh]==0){  //not visited
                    pq.push({d,{neigh,node}});
                }
            }
        }
        return {sum,mst};
    }
};

int main(){
    int n=5,m=6; // Number of vertices and edges

    // {u, v, weight}
    vector<vector<int>> edges={
        {0,1,2},{0,3,6},{1,2,3},
        {1,3,8},{1,4,5},{2,4,7}
    };

    //        0
    //      /   \
    //   (2)/     \(6)
    //    1-------3
    //   / \      |
    //(3)/  \(8)  |
    // 2     4    |
    //  \   /     |
    //(7)\ /(5)   |
    //    \/

    Solution obj;
    auto ans=obj.minSpanningTree(edges,n);

    cout<<"Weight of MST: "<<ans.first<<endl;

    cout<<"Edges in MST: "<<endl;
    for(auto it:ans.second){
        cout<<it[0]<<" - "<<it[1]<<endl;
    }
    return 0;
}