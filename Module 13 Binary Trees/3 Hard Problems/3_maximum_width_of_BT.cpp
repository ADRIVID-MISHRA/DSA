//LC 662
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if(root==nullptr) return 0;
    int ans=0;

    queue<pair<TreeNode*,long long>> q;
    q.push({root,0});

    while(!q.empty()){
        int size=q.size();
        int nmin=q.front().second;
        int first,last;

        for(int i=0;i<size;i++){
            TreeNode* node=q.front().first;
            long long index=q.front().second-nmin;   //normalized value,, without this even long long overflows
            q.pop();

            if(i==0) first=index;
            if(i==size-1) last=index;
            if(node->left!=nullptr) q.push({node->left,2*index+1});
            if(node->right!=nullptr) q.push({node->right,2*index+2});
        }
        ans=max(ans,last-first+1);   //This formulae returns 1 when there is only one node in that level
    }
    return ans;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->left=new TreeNode(-14);
    root->left->right->left=new TreeNode(-7);
    root->left->right->left->left=new TreeNode(66);
    root->left->right->left->left->left=new TreeNode(88);
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
    //     /        \
    //    66          98
    //   /               \
    //  77                 18

    cout<<widthOfBinaryTree(root);
    return 0;
}
