//LC 785
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class BFS{
    bool bfs(vector<vector<int>>& graph,vector<int>& vis,int src){
        queue<int> q; 
        q.push(src);
        vis[src]=0;  // start with RED
        while(!q.empty()){
            int node=q.front();
            int color=vis[node];
            q.pop();

            for(int neighbour:graph[node]){
                if(vis[neighbour]==-1){   //not visited
                    vis[neighbour]=!color;
                    q.push(neighbour);
                }else{   //Already visited
                    if(vis[neighbour]==color) return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);  //Visited array stores the color
        // color(0-> red, 1-> green, -1 -> not visited yet)
        for(int i=0;i<n;i++){
            if(vis[i]==-1) {
                if(!bfs(graph,vis,i)) return false;
            }
        }
        return true;
    }
};


class DFS{
    bool dfs(vector<vector<int>>& graph,vector<int>& vis,int srcNode,int srcColor){
        vis[srcNode]=srcColor;
        for(int neighbour:graph[srcNode]){
            if(vis[neighbour]==-1){    //not visited
                if(!dfs(graph,vis,neighbour,!srcColor)) return false;
            }else{    //Already visited
                if(vis[neighbour]==srcColor) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);  //Visited array stores the color
        // color(0-> red, 1-> green, -1 -> not visited yet)
        for(int i=0;i<n;i++){
            if(vis[i]==-1) {
                if(!dfs(graph,vis,i,0)) return false;   //pass the color of src node, so coloring starts from 0
            }
        }
        return true;
    }
};

int main(){
    int n=10,m=14;

    vector<pair<int,int>> edges={
        {1,2},{1,3},{2,4},{2,5},{3,5},{3,6},{4,7},
        {5,7},{5,8},{6,8},{7,9},{8,9},{8,10},{9,10}
    };

    vector<vector<int>> adj(n+1);

    for(auto [u,v]:edges){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4    5   6
    //     \ / \ /
    //      7   8
    //       \ / \
    //        9 --10   //The 9-10 edge is making the graph non-bipartite

    BFS obj1;
    cout<<boolalpha<<obj1.isBipartite(adj)<<endl;

    DFS obj2;
    cout<<boolalpha<<obj2.isBipartite(adj);

    return 0;
}