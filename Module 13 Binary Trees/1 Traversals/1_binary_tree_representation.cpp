#include<iostream>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr)   //initializer list allocation
        :val(val),left(left),right(right) {}
};

int main(){
    TreeNode *root=new TreeNode(2);
    root->left=new TreeNode(4);
    cout<<root->val<<endl<<root->left->val;

    return 0;
}