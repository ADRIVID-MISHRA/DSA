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

bool dfs(TreeNode* root,vector<int> &ans,int targetNode){
    if(root==nullptr) return false;

    ans.push_back(root->val);
    if(root->val==targetNode) return true; 

    if(dfs(root->left,ans,targetNode)) return true;
    if(dfs(root->right,ans,targetNode)) return true;
    
    ans.pop_back();
    return false;
}

vector<int> path(TreeNode* root,int targetNode){
    vector<int> ans;
    dfs(root,ans,targetNode); 
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

    vector<int> ans=path(root,98);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
