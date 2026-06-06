//LC 124
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

int maxPath(TreeNode* root,int &maxSum){
    if(root==nullptr) return 0;

    int leftSum=max(0,maxPath(root->left,maxSum));   // take zero when the path down gives a negetive sum
    int rightSum=max(0,maxPath(root->right,maxSum));

    maxSum=max(maxSum,root->val+leftSum+rightSum);
    return root->val+max(leftSum,rightSum);
}

int maxPathSum(TreeNode* root) {
    int maxSum=INT_MIN;
    maxPath(root,maxSum);
    return maxSum;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(-7);
    // root->right->right=new TreeNode(9);

    cout<<maxPathSum(root);
    return 0;
}