//LC 99
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
    TreeNode *first=nullptr;
    TreeNode *prev=new TreeNode(INT_MIN);
    TreeNode *middle=nullptr;
    TreeNode *last=nullptr;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);

        if(last){
            swap(first->val,last->val);
        }else{
            swap(first->val,middle->val);
        }
    }

    void inorder(TreeNode *root){
        if(root==nullptr) return;

        inorder(root->left);
        if(root->val < prev->val){
            if(!middle){
                first=prev;
                middle=root;
            }else{
                last=root;
                return;
            }
        }
        prev=root;
        inorder(root->right);
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
    TreeNode *root=new TreeNode(50);
    root->left=new TreeNode(60);
    root->right=new TreeNode(70);
    root->left->left=new TreeNode(20);
    root->left->right=new TreeNode(40);
    root->left->right->left=new TreeNode(35);
    root->left->right->right=new TreeNode(45);
    root->left->right->left->left=new TreeNode(33);
    root->left->right->left->left->left=new TreeNode(32);
    root->left->right->right->right=new TreeNode(47);
    root->left->right->right->right->right=new TreeNode(48);
    root->right->left=new TreeNode(30);
    root->right->right=new TreeNode(80);

    //                 50
    //            /          \
    //          60            70
    //        /   \         /    \
    //      20     40      30     80
    //            /  \
    //          35    45
    //         /        \
    //       33          47
    //      /              \
    //    32                48
    //30 and 60 are swapped in the above BST

    Solution obj;
    obj.recoverTree(root);  //correct the BST   
    vector<vector<int>> bfs=levelOrder(root);
    for(auto it:bfs){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// class Solution {
// public:
//     void recoverTree(TreeNode* root) {
//         TreeNode *prev=nullptr;
//         pair<TreeNode *,TreeNode*> violation1={nullptr,nullptr};
//         TreeNode *violation2=nullptr;
//         helper(root,prev,violation1,violation2);

//         if(!violation2){
//             int temp=violation1.first->val;
//             violation1.first->val=violation1.second->val;
//             violation1.second->val=temp;
//         }else{
//             int temp=violation1.first->val;
//             violation1.first->val=violation2->val;
//             violation2->val=temp;
//         }
//     }

//     void helper(TreeNode *root,TreeNode *&prev,pair<TreeNode *,TreeNode*> &violation1,TreeNode *&violation2){
//         if(root==nullptr) return;

//         helper(root->left,prev,violation1,violation2);
//         if(prev!=nullptr && root->val < prev->val){
//             if(!violation1.first) violation1={prev,root};
//             else{
//                 violation2=root;
//                 return;
//             }
//         }
//         prev=root;
//         helper(root->right,prev,violation1,violation2);
//     }
// };