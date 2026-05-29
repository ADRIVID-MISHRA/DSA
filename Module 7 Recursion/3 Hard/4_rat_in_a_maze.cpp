#include<iostream>
#include<vector>

using namespace std;

vector<int> di={+1,0,0,-1};
vector<int> dj={0,-1,+1,0};
string dir="DLRU";

void helper(vector<vector<int>> &maze,vector<string> &result,string &curr,int row,int col,int n){
    if(row==n && col==n){
        result.push_back(curr);
        return;
    }

    //lexicographical order of calling DLRU
    for(int i=0;i<4;i++){
        int newRow=row+di[i];
        int newCol=col+dj[i];

        if(newRow>=0 && newRow<=n && newCol>=0 && newCol<=n && maze[newRow][newCol]!=0){
            maze[newRow][newCol]=0;
            curr.push_back(dir[i]);
            helper(maze,result,curr,newRow,newCol,n);
            maze[newRow][newCol]=1;
            curr.pop_back();
        }
    }

    //manual checks, not suiitable for production code.
    // //Down
    // if(row+1<=n && maze[row+1][col]!=0){
    //     maze[row+1][col]=0;
    //     curr.push_back('D');
    //     helper(maze,result,curr,row+1,col,n);
    //     maze[row+1][col]=1;
    //     curr.pop_back();
    // } 

    // //Left
    // if(col-1>=0 && maze[row][col-1]!=0){
    //     maze[row][col-1]=0;
    //     curr.push_back('L');
    //     helper(maze,result,curr,row,col-1,n);
    //     maze[row][col-1]=1;
    //     curr.pop_back();
    // } 

    // //Right
    // if(col+1<=n && maze[row][col+1]!=0){
    //     maze[row][col+1]=0;
    //     curr.push_back('R');
    //     helper(maze,result,curr,row,col+1,n);
    //     maze[row][col+1]=1;
    //     curr.pop_back();
    // } 

    // //UP
    // if(row-1>=0 && maze[row-1][col]!=0){
    //     maze[row-1][col]=0;
    //     curr.push_back('U');
    //     helper(maze,result,curr,row-1,col,n);
    //     maze[row-1][col]=1;
    //     curr.pop_back();
    // } 

}

vector<string> ratMaze(vector<vector<int>> maze){
    vector<string> result;
    string curr;
    if(maze[0][0]!=0){
        maze[0][0]=0;
        helper(maze,result,curr,0,0,maze.size()-1);
    }
    return result;
}

int main(){
    vector<vector<int>> maze={
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string> result=ratMaze(maze);
    for(auto it:result){
        cout<<it<<endl;
    }
    return 0;
}