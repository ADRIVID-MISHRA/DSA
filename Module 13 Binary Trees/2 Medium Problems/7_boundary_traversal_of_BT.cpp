#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

bool isLeaf(TreeNode *node){
    return (node->left==nullptr && node->right==nullptr);
}

void leftBoundary(TreeNode *root,vector<int> &ans){
    TreeNode *curr=root;
    while(curr!=nullptr){
        if(!isLeaf(curr)) ans.push_back(curr->val);
        if(curr->left!=nullptr) curr=curr->left;
        else curr=curr->right; 
    }
}

void addLeaf(TreeNode *root,vector<int> &ans){
    if(root==nullptr) return;

    if(isLeaf(root)) ans.push_back(root->val);   //Preorder checking of leef nodes (DFS)

    addLeaf(root->left,ans);
    addLeaf(root->right,ans);
}

void rightBoundary(TreeNode *root,vector<int> &ans){
    TreeNode *curr=root;
    vector<int> temp;

    while(curr!=nullptr){
        if(!isLeaf(curr)) temp.push_back(curr->val);
        if(curr->right!=nullptr) curr=curr->right;
        else curr=curr->left;
    }
    // reverse(temp.begin(),temp.end());

    // ans.reserve(ans.size()+temp.size());  //reserve space to avoid multiple reallocations
    // ans.insert(ans.end(),temp.begin(),temp.end());
    for(int i=temp.size()-1;i>=0;i--){   //insert in reverse order
        ans.push_back(temp[i]);
    }
}

// void rightBoundary(TreeNode *root,vector<int> &ans){     //recursive right boundary addision
//     if(root==nullptr || isLeaf(root)) return;

//     if(root->right!=nullptr) rightBoundary(root->right,ans);     
//     else rightBoundary(root->left,ans);

//     ans.push_back(root->val);
// }

vector<int> boundaryTraversal(TreeNode *root){
    vector<int> ans;
    if(root==nullptr) return ans;

    if(!isLeaf(root)) ans.push_back(root->val);   //Add root
    leftBoundary(root->left,ans);
    addLeaf(root,ans);
    rightBoundary(root->right,ans);

    return ans;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(-7);
    root->left->right->right=new TreeNode(-23);
    root->right->right=new TreeNode(9);

    vector<int> ans=boundaryTraversal(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}