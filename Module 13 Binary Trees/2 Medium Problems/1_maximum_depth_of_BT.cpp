//LC 104
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

int maxDepth(TreeNode* root) {
    if(root==nullptr) return 0;

    return 1+max(maxDepth(root->left),maxDepth(root->right));
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->left=new TreeNode(7);
    root->right->right=new TreeNode(9);

    cout<<maxDepth(root);

    return 0;
}