//LC 101
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

bool sameTree(TreeNode* a,TreeNode* b){
    if(a==nullptr || b==nullptr) return a==b;

    return (a->val==b->val) && sameTree(a->left,b->right) && sameTree(a->right,b->left);
}

bool isSymmetric(TreeNode* root) {
    if(root==nullptr) return true;
    return sameTree(root->left,root->right);
}
   
int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->left=new TreeNode(-14);
    // root->left->right->left=new TreeNode(-7);
    // root->left->right->right=new TreeNode(-23);
    // root->left->right->right->right=new TreeNode(98);
    // root->left->right->right->right->right=new TreeNode(18);
    root->right->right=new TreeNode(-14);
    root->right->left=new TreeNode(4);

    //           1
    //       /      \
    //      3        3
    //    /   \    /   \
    // -14    4   4     -14

    cout<<boolalpha<<isSymmetric(root);
    return 0;
}
