//LC 827
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class DisjointSet{
public:
    vector<int> parent,size;
    //constructor
    DisjointSet(int n){   //supports both 1-based indexing(1 to n nodes) and 0-based indexing(0 to n nodes)
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
};

class Solution {
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int totalNodes=n*m-1;  //0 to totalNodes are the nodes
        DisjointSet ds(totalNodes);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int node=m*i+j;  //node number for DisjointSet
                    for(int k=0;k<4;k++){
                        int row=i+dx[k];
                        int col=j+dy[k];
                        if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1){
                            int newNode=row*n+col;
                            ds.unionBySize(node,newNode);
                        }
                    }
                }
            }
        }   

        int maxSize=ds.size[ds.findParent(0)];  //if all the cells are 1, then this is the size of the island
        // for(int i=0;i<=totalNodes;i++){      //Alternate way of finding the largest island before converting any 0 to 1.
        //     maxSize=max(maxSize,ds.size[i]);
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){  
                    int node=m*i+j;  
                    int newSize=1;
                    unordered_set<int> st;
                    for(int k=0;k<4;k++){
                        int row=i+dx[k];
                        int col=j+dy[k];
                        if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1){
                            int newNode=row*m+col;
                            int newParent=ds.findParent(newNode);
                            if(st.find(newParent)==st.end()){  //different component than the other neighbours
                                newSize+=ds.size[newParent];
                                st.insert(newParent);                                
                            }
                        }
                    }
                    maxSize=max(maxSize,newSize);
                }
            }
        }     
        return maxSize;
    }
};

int main(){
    vector<vector<int>> grid={
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1}
    };

    Solution obj;
    cout<<obj.largestIsland(grid);

    return 0;
}