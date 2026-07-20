#include<iostream>
#include<vector>

using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
public:
    //constructor
    DisjointSet(int n){   //supports both 1-based indexing(1 to n nodes) and 0-based indexing(0 to n nodes)
        rank.resize(n+1,0);
        size.resize(n+1,1);
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

    void unionBySize(int u,int v){
        int pu=findParent(u);  //find the ultimate parents
        int pv=findParent(v);

        if(pu==pv) return;   //already in the same component

        if(size[pv]<=size[pu]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }

    bool sameComponent(int a,int b){
        return (findParent(a)==findParent(b));
    }
};

int main(){
    //While implementing disjoint set, do it either by size or by rank, don't use both of them together
    
    //By Rank
    DisjointSet ds1(7);  //upto 7 nodes (0 to 7  or  1 to 7)
    ds1.unionByRank(1,2);
    ds1.unionByRank(2,3);
    ds1.unionByRank(4,5);
    ds1.unionByRank(6,7);
    ds1.unionByRank(5,6);
    cout<<boolalpha<<ds1.sameComponent(3,7)<<endl;
    ds1.unionByRank(3,7);
    cout<<ds1.sameComponent(3,7)<<endl<<endl;

    //By size
    DisjointSet ds2(7);  //upto 7 nodes (0 to 7  or  1 to 7)
    ds2.unionBySize(1,2);
    ds2.unionBySize(2,3);
    ds2.unionBySize(4,5);
    ds2.unionBySize(6,7);
    ds2.unionBySize(5,6);
    cout<<boolalpha<<ds2.sameComponent(3,7)<<endl;
    ds2.unionBySize(3,7);
    cout<<ds2.sameComponent(3,7);
    return 0;
}