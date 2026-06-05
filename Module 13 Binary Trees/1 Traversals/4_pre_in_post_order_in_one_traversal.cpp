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

vector<vector<int>> traversal(TreeNode *root){
    vector<int> preorder,inorder,postorder;
    stack<pair<TreeNode*,int>> s;

    s.push({root,1});
    while(!s.empty()){
        auto temp=s.top();
        s.pop();
        if(temp.second==1){
            preorder.push_back(temp.first->val);
            s.push({temp.first,2});
            if(temp.first->left!=nullptr) s.push({temp.first->left,1});
        }else if(temp.second==2){
            inorder.push_back(temp.first->val);
            s.push({temp.first,3});
            if(temp.first->right!=nullptr) s.push({temp.first->right,1});
        }else{
            postorder.push_back(temp.first->val);
        }
    }
    return {preorder,inorder,postorder};
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    // root->left->right=new TreeNode(4);
    // root->left->left=new TreeNode(7);
    // root->right->right=new TreeNode(9);

    vector<vector<int>> result=traversal(root);
    for(auto it: result){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}