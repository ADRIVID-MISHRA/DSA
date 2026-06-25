//LC 733
#include<iostream>
#include<vector>

using namespace std;

class Solution {
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
    void dfs(vector<vector<int>>& image,int org,int color,int r,int c,int n,int m){
        image[r][c]=color;
        for(int i=0;i<4;i++){
            int x=r+dx[i];
            int y=c+dy[i];

            if(x<n && x>=0 && y>=0 && y<m && image[x][y]==org){
                dfs(image,org,color,x,y,n,m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        if(originalColor==color) return image;
        int n=image.size();
        int m=image[0].size();
        dfs(image,originalColor,color,sr,sc,n,m);
        return image;
    }
};

int main(){
    vector<vector<int>> image={  
        {1,1,0,0,2,2},
        {1,1,1,0,2,2},
        {0,0,1,1,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,1,1},
        {1,1,0,0,1,1}
    };

    Solution obj;
    obj.floodFill(image,3,2,5);

    for(auto i:image){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}

//Leetcode BFS submission
// class Solution {
//     const int dx[4]={0,1,0,-1};
//     const int dy[4]={1,0,-1,0};
//     void bfs(vector<vector<int>>& image,int org,int r,int c,int color){
//         int n=image.size();
//         int m=image[0].size();
//         queue<pair<int,int>> q;
//         q.push({r,c}); 
//         image[r][c]=color;

//         while(!q.empty()){
//             auto node=q.front();
//             q.pop();

//             for(int i=0;i<4;i++){
//                 int x=node.first+dx[i];
//                 int y=node.second+dy[i];

//                 if(x<n && x>=0 && y>=0 && y<m){ //within bounds
//                     if(image[x][y]==org){
//                         image[x][y]=color;
//                         q.push({x,y});
//                     }
//                 }
//             }
//         }
//     }
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int originalColor=image[sr][sc];
//         if(originalColor==color) return image;
//         bfs(image,originalColor,sr,sc,color);
//         return image;
//     }
// };