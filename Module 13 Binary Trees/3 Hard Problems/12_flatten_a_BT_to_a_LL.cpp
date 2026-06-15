//LC 114
#include<iostream>
#include<vector>
#include<stack>

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
    TreeNode *prev=nullptr;   //prev is the subtree that has already been flattened
    void flattenRecursive(TreeNode* root) {
        if(root==nullptr) return;

        flattenRecursive(root->right);
        flattenRecursive(root->left);

        root->left=nullptr;
        root->right=prev;

        prev=root;
    }

    void flattenIterative(TreeNode* root) {
        if(root==nullptr) return;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* front=st.top();
            st.pop();

            if(front->right) st.push(front->right);
            if(front->left) st.push(front->left);

            if(!st.empty()) front->right=st.top();   //stack becomes empty at the last node
            front->left=nullptr;
        }
    }

    void flattenMorris(TreeNode* root) {
        if(root==nullptr) return;
        TreeNode* curr=root;

        while(curr!=nullptr){
            if(curr->left==nullptr){   //move right if left is not there
                curr=curr->right;
                continue;
            }
            if(curr->right){  //if there is no right, no need to assign
                TreeNode *prev=curr->left;
                //find rightmost node of left subtree
                while(prev->right!=nullptr){
                    prev=prev->right;
                }
                //assign it to root of right subtree
                prev->right=curr->right;
            }
            curr->right=curr->left;
            curr->left=nullptr;
            curr=curr->right;
        }
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->left=new TreeNode(14);
    root->left->right->left=new TreeNode(7);
    root->left->right->left->left=new TreeNode(66);
    root->left->right->left->left->left=new TreeNode(77);
    root->left->right->right=new TreeNode(23);
    root->left->right->right->right=new TreeNode(98);
    root->left->right->right->right->right=new TreeNode(18);
    root->right->right=new TreeNode(9);
    root->right->left=new TreeNode(5);

    //             1
    //         /       \
    //        2         3
    //      /   \     /   \
    //    14     4   5     9
    //          / \
    //         7   23
    //        /      \
    //      66        98
    //      /           \
    //    77             18

    Solution obj;
    // obj.flattenRecursive(root);
    // obj.flattenIterative(root);
    obj.flattenMorris(root);
    TreeNode *curr=root;
    while(curr!=nullptr){
        cout<<curr->val<<" ";
        curr=curr->right;
    }
    return 0;
}
