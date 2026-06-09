//LC 199
#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

//BFS
// vector<int> rightSideView(TreeNode* root) {
//     vector<int> ans;
//     if(root==nullptr) return ans;
//     queue<TreeNode *> q;

//     q.push(root);
//     while(!q.empty()){
//         int size=q.size();
//         int last;
//         for(int i=0;i<size;i++){
//             TreeNode *front=q.front();
//             q.pop();
//             last=front->val;
//             if(front->left!=nullptr) q.push(front->left);     //for left view just push into queue right first then left, so that BFS traversal becomes right to left
//             if(front->right!=nullptr) q.push(front->right);
//         }
//         ans.push_back(last);
//     }
//     return ans;
// }

//DFS (recomended)
void dfs(TreeNode* root,vector<int> &ans,int level){
    if(root==nullptr) return;

    if(level==ans.size()) ans.push_back(root->val);  //first node in that level -> so add

    dfs(root->right,ans,level+1);    //reverse this order and do left first then right to get left view
    dfs(root->left,ans,level+1);
}

vector<int> rightSideView(TreeNode* root){
    vector<int> ans;
    if(root==nullptr) return ans;

    dfs(root,ans,0);    //Root,Right,Left  -> reverse preorder traversal
    return ans;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->left=new TreeNode(-14);
    root->left->right->left=new TreeNode(-7);
    root->left->right->right=new TreeNode(-23);
    root->left->right->right->right=new TreeNode(98);
    root->left->right->right->right->right=new TreeNode(18);
    root->right->right=new TreeNode(9);
    root->right->left=new TreeNode(5);

    //           1
    //       /      \
    //      2        3
    //    /   \    /   \
    // -14    4   5     9
    //       / \
    //     -7  -23
    //             \
    //               98
    //                   \
    //                     18

    vector<int> ans=rightSideView(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
