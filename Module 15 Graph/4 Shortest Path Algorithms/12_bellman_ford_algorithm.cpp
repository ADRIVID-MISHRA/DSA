#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> bellmanFord(vector<vector<int>> &edges,int n,int src){  //n is number of nodes
        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        for(int i=1;i<=n;i++){   
            bool flag=false;
            for(auto it:edges){
                int u=it[0],v=it[1],wt=it[2];

                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    flag=true;  
                }
            }
            if(i==n && flag==true) return {-1};  //cycle detected in nth iteration
            if(flag==false) break;
        }
        return dist;
    }
};

int main(){
    //DG without -ve cycle
    int n=6,m=8; // Number of vertices and edges

    // {u, v, weight}
    vector<vector<int>> edges={
        {0,1,4},{0,2,2},{1,2,-1},{1,3,2},
        {2,3,3},{2,4,2},{3,5,2},{4,5,-2}
    };
    //        0
    //      /   \
    //   (4)     \(2)
    //    v       v
    //    1──(-1)▶2
    //    │      / \
    // (2)│   (3)  \(2)
    //    v    v     v
    //    3──(2)──▶5
    //         ^
    //         │(-2)
    //         4

    //DG with -ve cycle
    // int n=6,m=8; // Number of vertices and edges

    // // {u, v, weight}
    // vector<vector<int>> edges={
    //     {0,1,4},{1,2,3},{2,3,2},{3,1,-8},
    //     {2,4,4},{4,5,2},{0,5,10},{5,2,1}
    // };
    //             (4)
    //        0 ─────────▶ 1
    //        │            │
    //    (10)│         (3)│
    //        ▼            ▼
    //        5 ◀──(2)─── 4
    //        │            ▲
    //     (1)│         (4)│
    //        ▼            │
    //        2 ───(2)──▶ 3
    //        ▲            │
    //        └────(-8)────┘
    //
    // Negative Cycle:
    // 1 ──(3)──▶ 2 ──(2)──▶ 3 ──(-8)──▶ 1
    // Total Weight = 3 + 2 - 8 = -3

    Solution obj;
    vector<int> distances=obj.bellmanFord(edges,n,0);
    for(int it:distances){
        cout<<it<<" ";
    }
    return 0;
}