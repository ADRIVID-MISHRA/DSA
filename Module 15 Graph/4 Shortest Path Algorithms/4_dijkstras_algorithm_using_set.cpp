#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution{
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>> &adj,int src){
        int n=adj.size();
        set<pair<int,int>> st; //{dist,node}
        vector<int> dist(n,INT_MAX);                                                       

        st.insert({0,src});
        dist[src]=0;

        while(!st.empty()){
            auto it=*st.begin();  // st.begin() is the iterator to the smallest element and * dereferences it to make it a variable
            int d=it.first;
            int node=it.second;
            st.erase(it);
            
            for(auto neighbour:adj[node]){
                int neigh=neighbour.first;
                int wt=neighbour.second;

                if(wt+d<dist[neigh]){ 
                    if(dist[neigh]!=INT_MAX){    //already visited though not finalized yet
                        st.erase({dist[neigh],neigh});
                    }
                    dist[neigh]=wt+d;
                    st.insert({wt+d,neigh});
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