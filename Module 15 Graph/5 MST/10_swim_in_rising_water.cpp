//LC 778
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//Djkistra approach
// class Solution {
//     vector<int> dx={0,0,1,-1};
//     vector<int> dy={1,-1,0,0};
// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int maxTime=grid[0][0];
//         priority_queue< pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
//         pq.push({grid[0][0],{0,0}});  // 0,0 node
        
//         vector<vector<int>> vis(n,vector<int>(n,0));

//         while(!pq.empty()){
//             int time=pq.top().first;
//             int row=pq.top().second.first;
//             int col=pq.top().second.second;
//             pq.pop();

//             maxTime=max(maxTime,time);
//             if(row==n-1 && col==n-1) return maxTime;

//             for(int i=0;i<4;i++){
//                 int nrow=row+dx[i];
//                 int ncol=col+dy[i];
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0){
//                     pq.push({grid[nrow][ncol],{nrow,ncol}});
//                     vis[nrow][ncol]=1;
//                 }
//             }
//         }
//         return maxTime;
//     }
// };


//DSU approach
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
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
public:
    int swimInWater(vector<vector<int>>& grid){
        int n=grid.size();
        int totalNodes=n*n-1;
        DisjointSet ds(totalNodes);
        vector<pair<int,pair<int,int>>> heights;
        vector<vector<int>> vis(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                heights.push_back({grid[i][j],{i,j}});
            }
        }

        sort(heights.begin(),heights.end());

        for(auto it:heights){
            int time=it.first;
            int row=it.second.first;
            int col=it.second.second;
            vis[row][col]=1;
            int node=row*n+col;
            
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                int newNode=nrow*n+ncol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==1){
                    ds.unionByRank(node,newNode);
                }
            }
            if(ds.findParent(0)==ds.findParent(totalNodes)) return time;
        }
        return grid[0][0];
    }
};

int main(){
    vector<vector<int>> grid={
        {0,1,2,3},
        {5,4,7,6},
        {8,9,10,11},
        {12,13,14,15}
    };

    // Height Grid
    //
    //   0──1──2──3
    //   │  │  │  │
    //   5──4──7──6
    //   │  │  │  │
    //   8──9─10─11
    //   │  │  │  │
    //  12─13─14─15
    //
    // Expected Answer: 15

    Solution obj;

    cout<<"Minimum Time: "<<obj.swimInWater(grid)<<endl;

    return 0;
}