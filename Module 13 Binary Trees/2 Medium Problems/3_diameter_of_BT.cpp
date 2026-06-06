//LC 543
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

int depth(TreeNode* root,int &diameter){
    if(root==nullptr) return 0;

    int lh=depth(root->left,diameter);
    int rh=depth(root->right,diameter);

    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter=0;
    depth(root,diameter);
    return diameter;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(7);
    // root->right->right=new TreeNode(9);

    cout<<diameterOfBinaryTree(root);
    return 0;
}