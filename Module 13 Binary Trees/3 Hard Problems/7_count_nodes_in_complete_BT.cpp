//LC 222
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

int countNodes(TreeNode* root) {
    if(root==nullptr) return 0;

    int lh=0,rh=0;
    //left height
    TreeNode *curr=root;
    while(curr!=nullptr){
        curr=curr->left;
        lh++;
    }
    //right height
    curr=root;
    while(curr!=nullptr){
        curr=curr->right;
        rh++;
    }

    if(lh==rh) return (1<<lh)-1;   ///pow(2,h)-1
    else return 1+countNodes(root->right)+countNodes(root->left);
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->left=new TreeNode(14);
    root->right->left=new TreeNode(5);

    //             1
    //         /       \
    //        2         3
    //      /   \     /   
    //    14     4   5     


    cout<<countNodes(root);  //Pass a complete BT
    return 0;
}
