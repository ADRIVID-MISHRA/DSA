//LC 947
#include<iostream>
#include<vector>
#include<unordered_map>

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
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }

        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> mpp; //stores the rows and couloumns that are connected
        for(auto it:stones){
            int row=it[0];
            int col=maxRow+it[1]+1;
            ds.unionByRank(row,col);
            mpp[row]=1;
            mpp[col]=1;
        }

        int cnt=0;
        for(auto it:mpp){
            if(ds.findParent(it.first)==it.first) cnt++;
        }
        return n-cnt;
    }
};


int main(){
    vector<vector<int>> stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution obj;
    cout<<obj.removeStones(stones);
    return 0;
}