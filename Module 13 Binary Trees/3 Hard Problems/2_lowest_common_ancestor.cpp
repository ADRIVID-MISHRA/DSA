//LC 236
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr || root==p || root==q) return root;  //handels p or q being ancestor also
    
    TreeNode *left=lowestCommonAncestor(root->left,p,q);
    TreeNode *right=lowestCommonAncestor(root->right,p,q);

    if(left==nullptr) return right;
    if(right==nullptr) return left; 
    return root;   //Both left and right are not nullptr
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

    TreeNode* ancestor=lowestCommonAncestor(root,root->left->right->right,root->left->left);  //-14 and -23
    cout<<ancestor->val;
    return 0;
}
