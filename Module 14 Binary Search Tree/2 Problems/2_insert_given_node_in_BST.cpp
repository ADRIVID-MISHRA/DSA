//LC 701
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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    // if(root==nullptr) return new TreeNode(val);
    // TreeNode *curr=root;
    // TreeNode *prev=curr;
    // while(curr!=nullptr){
    //     prev=curr;
    //     if(curr->val > val) curr=curr->left;
    //     else curr=curr->right;
    // }
    // if(prev->val > val) prev->left=new TreeNode(val);
    // else prev->right=new TreeNode(val);

    // return root;

    if(root==nullptr) return new TreeNode(val);
    TreeNode *curr=root;
    while(true){
        if(curr->val>val){
            if(curr->left) curr=curr->left;
            else{
                curr->left=new TreeNode(val);
                break;
            }
        }else{
            if(curr->right) curr=curr->right;
            else{
                curr->right=new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

//Print modified BST
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

    root=insertIntoBST(root,66);
    root=insertIntoBST(root,46);

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
