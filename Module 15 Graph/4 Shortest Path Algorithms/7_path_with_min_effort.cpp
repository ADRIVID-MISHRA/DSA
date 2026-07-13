//LC 1631
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();   //rows
        int m=heights[0].size();   //cols
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;

        dist[0][0]=0;
        pq.push({0,{0,0}}); //dist,(row,col);   //Taking iniial distance as 0

        vector<int> dx={0,1,-1,0};
        vector<int> dy={1,0,0,-1};

        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int d=node.first;
            int row=node.second.first;
            int col=node.second.second;
            if(row==n-1 && col==m-1) return d;

            for(int i=0;i<4;i++){
                int x=row+dx[i];
                int y=col+dy[i];

                if(x<n && x>=0 && y>=0 && y<m){ //within bounds
                    int newEffort=max(abs(heights[row][col]-heights[x][y]),d);
                    if(newEffort<dist[x][y]){
                        pq.push({newEffort,{x,y}});
                        dist[x][y]=max(newEffort,d);
                    }
                }
            }
        }
        return -1; //not reachable ** Dummy
    }
};

int main(){
    vector<vector<int>> heights={
        {1,2,2,3,5,4,6,7},
        {3,8,2,1,4,5,7,8},
        {5,3,5,2,6,7,3,2},
        {4,2,1,3,8,9,4,1},
        {6,7,2,4,5,3,2,2},
        {8,6,5,7,4,2,1,3},
        {7,5,3,2,6,8,4,5},
        {9,7,4,3,2,1,2,1}
    };

    Solution obj;
    cout<<obj.minimumEffortPath(heights);
    return 0;
}