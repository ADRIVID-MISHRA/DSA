//LC 450
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

TreeNode* helper(TreeNode *node){   //returns the new root of the sub-tree, whoes root is being deleted
    if(node->left==nullptr) return node->right;
    if(node->right==nullptr) return node->left;
    // if(node->left==nullptr && node->right==nullptr) return nullptr; //alreadey implicit in the above two conditions

    TreeNode *temp=node->right;
    while(temp->left!=nullptr) temp=temp->left;
    temp->left=node->left;
    return node->right; 
}
    
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr) return root;
    if(root->val==key){
        return helper(root);
    }
    
    TreeNode *curr=root;
    while(curr!=nullptr){
        if(curr->val> key){   //move left
            if(curr->left!=nullptr && curr->left->val==key){
                curr->left=helper(curr->left);
                break;
            }
            curr=curr->left;
        }else{    //move rignt
            if(curr->right!=nullptr && curr->right->val==key){
                curr->right=helper(curr->right);
                break;
            }
            curr=curr->right;
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

    root=deleteNode(root,50);
    root=deleteNode(root,70);

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
