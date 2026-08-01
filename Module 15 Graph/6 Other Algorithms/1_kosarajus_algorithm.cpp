#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,stack<int> &order){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,order);
            } 
        }
        order.push(node);
    }

    void dfs2(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &order){
        vis[node]=1;
        order.push_back(node);  //follows normal order of SCC
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs2(it,adj,vis,order);
            } 
        }
    }

public:
    pair<int,vector<vector<int>>> kosaraju(vector<vector<int>> &adj){
        int n=adj.size();
        stack<int> sortedNodes;   //sorted by finishing order
        vector<int> vis(n,0); // 0 to n-1 nodes
        for(int i=0;i<n;i++){   //done for multi component graph
            if(!vis[i]) dfs(i,adj,vis,sortedNodes);
        }

        //reverse the graph
        vector<vector<int>> revGraph(n);
        for(int i=0;i<n;i++){
            vis[i]=0; //re-initialize vis array
            for(int it:adj[i]){
                revGraph[it].push_back(i);   //i->it converted to it->i
            }
        }

        //run dfs again to get SCC
        vector<vector<int>> scc;
        int cntScc=0;
        // vis=vector<int>(n,0);
        while(!sortedNodes.empty()){
            int node=sortedNodes.top();
            sortedNodes.pop();

            if(!vis[node]){
                vector<int> temp;
                dfs2(node,revGraph,vis,temp);
                scc.push_back(temp);
                cntScc++;
            }
        }
        return {cntScc,scc};
    }
};

int main(){
    int n=8,m=11; // Number of vertices and edges (0 to 7)

    // {u, v}
    vector<vector<int>> edges={
        {0,1},{1,2},{2,0},
        {2,3},
        {3,4},{4,5},{5,3},
        {5,6},
        {6,7},{7,6},
        {1,7}
    };

    // Adjacency List
    vector<vector<int>> adj(n);

    for(auto it:edges){
        int u=it[0];
        int v=it[1];

        adj[u].push_back(v);
    }

    //          ┌──────┐
    //          ▼      │
    //      0 ──▶ 1 ──▶ 2
    //      ▲           │
    //      └───────────┘
    //                  │
    //                  ▼
    //          ┌──────▶3◀──────┐
    //          │       │       │
    //          │       ▼       │
    //          │       4       │
    //          │       │       │
    //          └────── 5───────┘
    //                  │
    //                  ▼
    //              6 ◀──▶ 7
    //              ▲      │
    //              └──────┘
    //
    // Extra Edge:
    // 1 ─────────▶ 7
    //
    // SCCs:
    // {0,1,2}
    // {3,4,5}
    // {6,7}
    //
    // Expected Answer: 3

    Solution obj;
    auto ans=obj.kosaraju(adj);

    cout<<"Number of SCCs: "<<ans.first<<endl;

    cout<<"Strongly Connected Components:"<<endl;
    for(auto component:ans.second){
        for(int node:component){
            cout<<node<<" ";
        }
        cout<<endl;
    }

    return 0;
}




//LC 1520
// Model this question as graph problem

// If there is a character 'b' between the first and last occurrence of character 'a', then it means we must include 'b' in the substring if we want to include 'a', so we can create an edge from 'a' to 'b'.

// So we can convert the input string into a directed graph, which has at most 26 vertex 'a' to 'z'.

// Within this graph, each SCC (Strongly Connected Components) much be included in a substring together. Additionaly, 'downstream' SCCs of a chosen SCC must also be included in the same substring.

// Thus, its easy to see that we just need to find all the SCC with 0 out-degree. Characters in each SCC are characters we must include in each substring. And it is guaranteed to be minimal total length.

//YET TO BE DONE