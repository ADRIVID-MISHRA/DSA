//LC 1319
#include<iostream>
#include<vector>

using namespace std;

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
        // int pu=findParent(u);  //find the ultimate parents
        // int pv=findParent(v);

        // if(pu==pv) return;   //already in the same component

        if(rank[pv]<rank[pu]) parent[pv]=pu;
        else if(rank[pu]<rank[pv]) parent[pu]=pv;
        else{   //connect in any of the ways
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    // bool sameComponent(int a,int b){
    //     return (findParent(a)==findParent(b));
    // }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n-1); //0 to n-1
        int nc=n,ee=0; //no of components and extra edges
        for(auto edge:connections){
            int u=edge[0];
            int v=edge[1];
            
            int pu=ds.findParent(u);
            int pv=ds.findParent(v);
            if(pu==pv){  //same component
                ee++;
            }else{
                nc--;
                ds.unionByRank(pu,pv);
            }
            // if(ds.sameComponent(u,v)){
            //     ee++;
            // }else{
            //     nc--;
            //     ds.unionByRank(u,v);
            // }
        }

        if(ee>=(nc-1)) return (nc-1);
        return -1;
    }
};

int main(){
    int n=9,m=8; // Number of vertices and edges

    // {u, v}
    vector<vector<int>> connections={
        {0,1},{1,2},{2,0},{3,4},
        {4,5},{6,7},{7,8},{8,6}
    };

    // Component 1:
    //
    //      0
    //     / \
    //    1---2
    //
    // Component 2:
    //
    //    3
    //    |
    //    |
    //    4
    //    |
    //    |
    //    5
    //
    // Component 3:
    //
    //      6
    //     / \
    //    7---8

    Solution obj;
    cout<<obj.makeConnected(n,connections);
    
    return 0;
}