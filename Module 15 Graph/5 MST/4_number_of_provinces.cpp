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

    void unionByRank(int u,int v){
        int pu=findParent(u);  //find the ultimate parents
        int pv=findParent(v);

        if(pu==pv) return;   //already in the same component

        if(rank[pv]<rank[pu]) parent[pv]=pu;
        else if(rank[pu]<rank[pv]) parent[pu]=pv;
        else{   //connect in any of the ways
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    bool sameComponent(int a,int b){
        return (findParent(a)==findParent(b));
    }
};

class Solution{
public:
    int numberOfProvinces(vector<vector<int>> &adj,int V){   //adj matrix  //1 based indexing  //V is no of vertices (1 to V)
        DisjointSet ds(V);
        int components=V;
        for(int i=1;i<adj.size();i++){
            for(int j=i+1;j<adj[0].size();j++){
                if(adj[i][j]==1){
                    if(!ds.sameComponent(i,j)){
                        ds.unionByRank(i,j);
                        components--;
                    }
                }
            }
        }
        return components;

        //alternate solution
        // DisjointSet ds(V);
        // for(int i=1;i<adj.size();i++){
        //     for(int j=1;j<adj[0].size();j++){
        //         if(adj[i][j]==1) ds.unionByRank(i,j);
        //     }
        // }

        // int components=0;
        // for(int i=1;i<=V;i++) if(ds.findParent(i)==i) components++;

        // return components;
    }
};

int main(){
    int V=7; // Number of vertices

    // Adjacency Matrix (1-indexed)
    vector<vector<int>> adj={
        {0,0,0,0,0,0,0,0},
        {0,1,1,1,0,0,0,0},
        {0,1,1,1,0,0,0,0},
        {0,1,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0},
        {0,0,0,0,1,1,0,0},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1}
    };

    // Province 1: 1,2,3
    //
    //      1
    //     / \
    //    2---3
    //
    // Province 2: 4,5
    //
    //    4-----5
    //
    // Province 3: 6,7
    //
    //    6-----7

    Solution obj;

    cout<<"Number of Provinces: "<<obj.numberOfProvinces(adj,V)<<endl;

    return 0;
}