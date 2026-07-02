//LC 207
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);   // 0 indexed -> vertices from 0 to numCourses-1

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);   // Directed edge b -> a 
        }

        vector<int> indegree(numCourses,0); 
        for(int i=0;i<numCourses;i++){       //initialize the indegree
            for(int neigh:adj[i]){
                indegree[neigh]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){      //initialize queue
            if(indegree[i]==0) q.push(i);
        }

        int count=0;
        while(!q.empty()){
            int node=q.front();
            count++;
            q.pop();

            for(auto neighbour:adj[node]){    //remove node from indegree
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return count==numCourses;
    }
};

int main(){
    int n=11,m=12;

    vector<vector<int>> prerequisites={
        {0,1},{1,2},{1,3},{2,4},{2,5},{3,5},
        {3,6},{4,7},{5,8},{6,8},{8,9},{9,10},
        {10,8}   // Cycle
    };

    //            0
    //           |
    //           1
    //        ↙   ↘
    //       2     3
    //      ↙ ↘   ↙ ↘
    //     4   5     6
    //      ↓   ↘   ↙
    //      7     8
    //           /  ↓
    //         10 ← 9
    //
    // Cycle: 8 → 9 → 10 → 8

    Solution sol;
    cout<<boolalpha<<sol.canFinish(n,prerequisites);
    return 0;
}