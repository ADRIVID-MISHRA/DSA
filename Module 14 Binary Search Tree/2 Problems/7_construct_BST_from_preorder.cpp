//LC 1008
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

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return helper(preorder,INT_MAX,index);
    }

    TreeNode* helper(vector<int> &preorder,int ub,int &index){
        if(index>=preorder.size()) return nullptr;
        int val=preorder[index];
        if(val>=ub) return nullptr;
        
        TreeNode* newNode=new TreeNode(val);
        index++;
        newNode->left=helper(preorder,val,index);
        newNode->right=helper(preorder,ub,index);
        return newNode;
    }
};

//Print BST
vector<vector<int>> levelOrder(TreeNode *root){   
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
    Solution obj;
    vector<int> preorder={8,5,1,7,10,12};
    TreeNode* root=obj.bstFromPreorder(preorder);

    vector<vector<int>> bfs=levelOrder(root);
    for(auto it:bfs){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
