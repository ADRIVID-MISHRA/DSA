#include<iostream>
#include<vector>
#include<map>
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

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root==nullptr) return ans;

    queue<pair<TreeNode*,int>> q;  //node,col no(vertical order)
    map<int,int> mpp;    //col,val

    q.push({root,0});
    while(!q.empty()){
        auto top=q.front(); 
        q.pop();

        if(mpp.find(top.second)==mpp.end()) mpp[top.second]=top.first->val;   //only store the first occurences
        if(top.first->left!=nullptr) q.push({top.first->left,top.second-1});
        if(top.first->right!=nullptr) q.push({top.first->right,top.second+1});
    }

    for(auto it:mpp){
        ans.push_back(it.second);
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
    //             \
    //               98
    //                   \
    //                     18

    vector<int> ans=topView(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
