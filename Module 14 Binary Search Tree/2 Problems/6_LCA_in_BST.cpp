//LC 235
#include<iostream>

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
    TreeNode *currNode=root;

    while(currNode!=nullptr){
        int curr=currNode->val;

        if(curr > p->val && curr > q->val) currNode=currNode->left;
        else if(curr < p->val && curr < q->val) currNode=currNode->right;
        else break;  //within the range
    }
    return currNode;
}

int main(){
    TreeNode *root=new TreeNode(50);
    root->left=new TreeNode(30);
    root->right=new TreeNode(70);
    root->left->left=new TreeNode(20);
    root->left->right=new TreeNode(40);
    root->left->right->left=new TreeNode(35);
    root->left->right->right=new TreeNode(45);
    root->left->right->left->left=new TreeNode(33);
    root->left->right->left->left->left=new TreeNode(32);
    root->left->right->right->right=new TreeNode(47);
    root->left->right->right->right->right=new TreeNode(48);
    root->right->left=new TreeNode(60);
    root->right->right=new TreeNode(80);

    //                  50
    //            /          \
    //          30            70
    //        /   \         /    \
    //      20     40      60     80
    //            /  \
    //          35    45
    //         /        \
    //       33          47
    //      /              \
    //    32                48

    TreeNode* lca=lowestCommonAncestor(root,root->left->right,root->left->right->left->left); //40 and 33 is passed
    cout<<lca->val;
    return 0;
}
