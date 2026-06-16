//LC 230
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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count=0;
        inorder(root,ans,count,k);
        return ans;
    }

    void inorder(TreeNode *root,int &ans,int &count,int k){
        if(root==nullptr || count>=k) return;

        inorder(root->left,ans,count,k);
        count++;
        if(count==k) ans=root->val;
        inorder(root->right,ans,count,k);  
    }

    int kthLargest(TreeNode* root, int k) {
        int ans;
        int count=0;
        reverseInorder(root,ans,count,k);
        return ans;
    }

    void reverseInorder(TreeNode *root,int &ans,int &count,int k){
        if(root==nullptr || count>=k) return;

        reverseInorder(root->right,ans,count,k);
        count++;
        if(count==k) ans=root->val;
        reverseInorder(root->left,ans,count,k);  
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

    
    Solution obj;
    cout<<obj.kthSmallest(root,4)<<endl;
    cout<<obj.kthLargest(root,3);
    return 0;
}
