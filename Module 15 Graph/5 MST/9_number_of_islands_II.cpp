#include<iostream>
#include<vector>
#include<unordered_set>

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

class Solution{
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
public:
    vector<int> numOfIslands(int n,int m,vector<vector<int>> &operators){
        int totalNodes=n*m-1; //nodes 0 to totalNodes
        DisjointSet ds(totalNodes);
        unordered_set<int> markedNodes;  //keeps track of nodes that are already 1
        vector<int> components;
        int currComp=0;

        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            int node=row*m+col;
            if(markedNodes.find(node)!=markedNodes.end()) {
                components.push_back(currComp);
                continue; //already land(1)
            }
            unordered_set<int> st;
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                int newNode=nrow*m+ncol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){  //valid newNode
                    if(markedNodes.find(newNode)!=markedNodes.end()){   //this cell/node is 1
                        st.insert(ds.findParent(newNode));
                    }
                }
            }

            int size=st.size();
            currComp=currComp+(1-size);
            markedNodes.insert(node);
            components.push_back(currComp);

            for(int neigh:st){  //join the islands
                ds.unionByRank(node,neigh);
            }
        }
        return components;
    }   
};

int main(){
    int n=4,m=5; // Grid size (rows x cols)

    // Land addition operations: {row, col}
    vector<vector<int>> operators={
        {1,1},{0,1},{3,3},{3,4},
        {1,2},{2,2},{1,1},{2,3}
    };

    Solution obj;
    vector<int> ans=obj.numOfIslands(n,m,operators);

    cout<<"Number of Islands after each operation:"<<endl;
    for(int it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}