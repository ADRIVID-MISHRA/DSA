#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr)   //initializer list allocation
        :val(val),left(left),right(right) {}
};

void inorder(TreeNode *root){   //LC 94
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(TreeNode *root){    //LC 144
    if(root==nullptr) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode *root){    //LC 145
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

vector<vector<int>> levelOrder(TreeNode *root){    //LC 102
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    queue<TreeNode *> q;

    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode *front=q.front();
            q.pop();
            if(front->left!=nullptr) q.push(front->left);
            if(front->right!=nullptr) q.push(front->right);
            level.push_back(front->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    //Make the tree first
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->left=new TreeNode(7);
    root->right->right=new TreeNode(9);
    
    //DFS
    inorder(root);
    cout<<endl;
    preorder(root); 
    cout<<endl;
    postorder(root);
    cout<<endl;

    //BFS
    vector<vector<int>> bfs=levelOrder(root);
    for(auto it:bfs){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}