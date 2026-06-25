//LC 130
#include<iostream>
#include<vector>

using namespace std;

class Solution {
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
    void mark(vector<vector<char>>& board,int row,int col,int n, int m){
        board[row][col]='C';   
        for(int i=0;i<4;i++){
            int x=row+dx[i];
            int y=col+dy[i];

            if(x<n && x>=0 && y>=0 && y<m && board[x][y]=='O'){
                mark(board,x,y,n,m);
            } 
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O'){
        //             mark(board,i,j,n,m);
        //         }
        //     }
        // }

        //Treverse first and last row
        for(int j=0;j<m;j++){
            //first row
            if(board[0][j]=='O') mark(board,0,j,n,m);
            //last row
            if(board[n-1][j]=='O') mark(board,n-1,j,n,m);
        }

        //Treverse first and last column
        for(int i=1;i<n-1;i++){
            //firat column
            if(board[i][0]=='O') mark(board,i,0,n,m);
            //last column
            if(board[i][m-1]=='O') mark(board,i,m-1,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='C') board[i][j]='O';
            }
        }
    }
};

int main(){
    vector<vector<char>> board = {
        {'X','X','X','X','X','X'},
        {'X','O','O','X','O','X'},
        {'X','X','O','X','O','X'},
        {'O','O','X','O','O','X'},
        {'X','X','X','X','X','O'}
    };

    Solution obj;
    obj.solve(board);

    for(auto it:board){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}