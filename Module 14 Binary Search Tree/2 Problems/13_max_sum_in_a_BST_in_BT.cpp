//LC 1373
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

class NodeValue{
    public:
    int sum,maxNode,minNode;

    NodeValue(int s,int mn,int mx){
        sum=s;
        minNode=mn;
        maxNode=mx;
    }
};

class Solution {
    int maxSum=0;

    NodeValue postorder(TreeNode* root){     //sum, smallest, largest
        if(root==nullptr) return NodeValue(0,INT_MAX,INT_MIN);

        auto left=postorder(root->left);
        auto right=postorder(root->right);

        if(left.maxNode < root->val && right.minNode > root->val){  // valid BST
            int currSum=root->val+left.sum+right.sum;
            maxSum=max(currSum,maxSum);
            return NodeValue(currSum,min(root->val,left.minNode),max(root->val,right.maxNode));
        }else{
            return NodeValue(0,INT_MIN,INT_MAX);  //BST becomes invalid
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        postorder(root);
        return maxSum;
    }    
};

int main(){
    TreeNode *root=new TreeNode(50);
    root->left=new TreeNode(300);
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

    //                 50
    //            /          \
    //          300           70
    //        /   \         /    \
    //      20     40      60     80
    //            /  \
    //          35    45
    //         /        \
    //       33          47
    //      /              \
    //    32                48

    Solution sol;
    cout<<sol.maxSumBST(root);

    return 0;
}

