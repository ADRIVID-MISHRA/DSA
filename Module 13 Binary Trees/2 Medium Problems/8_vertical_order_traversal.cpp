//LC 987
#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

void dfs(TreeNode* root,map<int,map<int,multiset<int>>> &ds,int row, int col){
    if(root==nullptr) return;

    ds[col][row].insert(root->val);
    dfs(root->left,ds,row+1,col-1);
    dfs(root->right,ds,row+1,col+1);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int>>> ds;            //col, row, priority queue
    dfs(root,ds,0,0);

    vector<vector<int>> verticalOrder;
    for(auto it:ds){
        vector<int> vertical;
        for(auto i:it.second){
            vertical.insert(vertical.end(),i.second.begin(),i.second.end());
        }
        verticalOrder.push_back(vertical);
    }
    return verticalOrder;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(-7);
    root->left->right->right=new TreeNode(-23);
    root->right->right=new TreeNode(9);

    vector<vector<int>> verticalOrder=verticalTraversal(root);
    for(auto it:verticalOrder){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}


//USING BFS TRAVERSAL

// vector<vector<int>> verticalTraversal(TreeNode* root) {
//     map<int, map<int, multiset<int>>> nodes;
//     queue<pair<TreeNode*, pair<int, int>>> todo;

//     todo.push({root, {0, 0}});

//     while (!todo.empty()) {
//         auto p = todo.front();
//         todo.pop();

//         TreeNode* node = p.first;
//         int x = p.second.first;   // column
//         int y = p.second.second;  // row

//         nodes[x][y].insert(node->val);

//         if (node->left) {
//             todo.push({node->left, {x - 1, y + 1}});
//         }

//         if (node->right) {
//             todo.push({node->right, {x + 1, y + 1}});
//         }
//     }

//     vector<vector<int>> ans;

//     for (auto& p : nodes) {
//         vector<int> col;

//         for (auto& q : p.second) {
//             col.insert(col.end(),
//                        q.second.begin(),
//                        q.second.end());
//         }

//         ans.push_back(col);
//     }

//     return ans;
// }