//LC 110
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

//BRUTE
int depth(TreeNode* root) {
    if(root==nullptr) return 0;

    return 1+max(depth(root->left),depth(root->right));
}

bool isBalancedBrute(TreeNode* root) {
    if(root==nullptr) return true;
    if(abs(depth(root->left)-depth(root->right))>1) return false;
    if(!isBalancedBrute(root->left)) return false;
    if(!isBalancedBrute(root->right)) return false;
    return true;
}


//OPTIMAL
int height(TreeNode* root) {
    if(root==nullptr) return 0;
    int lh=height(root->left);
    int rh=height(root->right);

    if(lh==-1 || rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}

bool isBalanced(TreeNode* root) {
    if(height(root)==-1) return false;
    return true;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(7);
    // root->right->right=new TreeNode(9);

    cout<<boolalpha<<isBalancedBrute(root)<<endl;
    cout<<isBalanced(root);

    return 0;
}