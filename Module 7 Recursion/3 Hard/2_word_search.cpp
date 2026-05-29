// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 if(board[i][j]==word[0]){
//                     visited[i][j]=true;
//                     if(helper(board,word,visited,i,j,1)) return true;
//                     visited[i][j]=false;
//                 }
//             }
//         }
//         return false;
//     }

//     bool helper(vector<vector<char>> &board,string &word,vector<vector<bool>> &visited,int row,int col,int index){
//         if(index==word.size()) return true;

//         if(row-1>=0 && word[index]==board[row-1][col] && !visited[row-1][col]){
//             visited[row-1][col]=true;
//             if(helper(board,word,visited,row-1,col,index+1)) return true;
//             visited[row-1][col]=false;
//         }
//         if(row+1<board.size() && word[index]==board[row+1][col] && !visited[row+1][col]){
//             visited[row+1][col]=true;
//             if(helper(board,word,visited,row+1,col,index+1)) return true;
//             visited[row+1][col]=false;
//         }
//         if(col+1<board[0].size() && word[index]==board[row][col+1] && !visited[row][col+1]){
//             visited[row][col+1]=true;
//             if(helper(board,word,visited,row,col+1,index+1)) return true;
//             visited[row][col+1]=false;
//         }
//         if(col-1>=0 && word[index]==board[row][col-1] && !visited[row][col-1]){
//             visited[row][col-1]=true;
//             if(helper(board,word,visited,row,col-1,index+1)) return true;
//             visited[row][col-1]=false;
//         }
//         return false;
//     }
// };








//LC 79
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board,string &word,int i,int j,int idx){
        if(idx==word.size()) return true;
        
        //check bounds and matching char with word's index
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        //store current 
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all four directions
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        // Restore the character (backtracking)
        board[i][j] = temp;

        return found;
    }
};
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha << sol.exist(board, "ABCCED") << endl; // true
    cout << boolalpha << sol.exist(board, "SEE") << endl;    // true
    cout << boolalpha << sol.exist(board, "ABCB") << endl;   // false
}