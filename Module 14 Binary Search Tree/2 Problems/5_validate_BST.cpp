//LC 98
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

class Solution1{
public:
    bool isValidBST(TreeNode* root) {
        long long last=LONG_MIN;
        return inorder(root,last);
    }
    
    bool inorder(TreeNode* root,long long &last){
        if(root==nullptr) return true;

        if(!inorder(root->left,last)) return false;
        if(root->val<=last) return false;
        last=root->val;
        if(!inorder(root->right,last)) return false;

        return true;
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root,LONG_MIN,LONG_MAX);
    }

    bool inorder(TreeNode* root,long long min,long long max){
        if(root==nullptr) return true;

        if(root->val<=min || root->val>=max) return false;
        return inorder(root->left,min,root->val) && inorder(root->right,root->val,max);
    }
};

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

    
    Solution1 obj1;
    cout<<boolalpha<<obj1.isValidBST(root)<<endl;
    
    Solution2 obj2;
    cout<<obj2.isValidBST(root);
    return 0;
}
