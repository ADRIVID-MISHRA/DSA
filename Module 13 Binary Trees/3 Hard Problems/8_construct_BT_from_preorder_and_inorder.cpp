//LC 105
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &mpp,int preStart,int preEnd,int inStart,int inEnd) {
    if(inStart>inEnd || preStart>preEnd) return nullptr;   //in case of empty array return null

    int inIndex=mpp[preorder[preStart]];
    int leftSize=inIndex-inStart;
    TreeNode* root=new TreeNode(preorder[preStart]);
    root->left=buildTreeRecursive(preorder,inorder,mpp,preStart+1,leftSize+preStart,inStart,inIndex-1);
    root->right=buildTreeRecursive(preorder,inorder,mpp,leftSize+preStart+1,preEnd,inIndex+1,inEnd);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> mpp;   //inorder node, index
    for(int i=0;i<inorder.size();i++){   
        mpp[inorder[i]]=i;
    }
    return buildTreeRecursive(preorder,inorder,mpp,0,preorder.size()-1,0,inorder.size()-1);
}


vector<vector<int>> levelOrder(TreeNode *root){    //print the formed tree
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
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    TreeNode *root=buildTree(preorder,inorder);

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
