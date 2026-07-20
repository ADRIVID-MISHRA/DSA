#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//By rank code only
class DisjointSet{
    vector<int> rank,parent;
public:
    //constructor
    DisjointSet(int n){   //supports both 1-based indexing(1 to n nodes) and 0-based indexing(0 to n nodes)
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){   //finds ultimate parents
        if(node==parent[node]) return node;

        return parent[node]=findParent(parent[node]);  //path compression
    }

    void unionByRank(int pu,int pv){
        if(rank[pv]<rank[pu]) parent[pv]=pu;
        else if(rank[pu]<rank[pv]) parent[pu]=pv;
        else{   //connect in any of the ways
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution{
public:
    pair<int,vector<vector<int>>> minSpanningTree(vector<vector<pair<int,int>>> &adj ,int n){  //given adj list || n is number of nodes (1 to n)
        vector<pair<int,pair<int,int>>> edges;  //(weight, (u,v))
        for(int i=1;i<=n;i++){
            for(auto it:adj[i]){
                if(i<it.first) edges.push_back({it.second,{i,it.first}});  //we add each edge once
            }                                         
        }
        vector<vector<int>> mst;
        int sum=0;
        sort(edges.begin(),edges.end());
        DisjointSet ds(n);

        for(auto it: edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;

            int pu=ds.findParent(u);
            int pv=ds.findParent(v);
            if(pu!=pv){   //not in the same component
                mst.push_back({u,v});
                ds.unionByRank(pu,pv);   //directly pass the ultimate parents to avoid calling findParent() again in the union() function
                sum+=wt;
            }
        }

        return {sum,mst};
    }
};

int main(){
    int n=5,m=6; // Number of vertices and edges

    // {u, v, weight}
    vector<vector<int>> edges={
        {1,2,2},{1,4,6},{2,3,3},
        {2,4,8},{2,5,5},{3,5,7}
    };

    // Adjacency List: {neighbour, weight}
    vector<vector<pair<int,int>>> adj(n+1);   //1 indexed graph (1 to n=5)

    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    //              1
    //           /     \
    //       (2)/       \(6)
    //         2─────────4
    //        / \       /
    //    (3)/   \(8)  /
    //      3     \   /
    //       \     \ /
    //     (7)\   (5)
    //         \   /
    //           5

    Solution obj;
    auto ans=obj.minSpanningTree(adj,n);

    cout<<"Weight of MST: "<<ans.first<<endl;

    cout<<"Edges in MST:"<<endl;
    for(auto it:ans.second){
        cout<<it[0]<<" - "<<it[1]<<endl;
    }

    return 0;
}