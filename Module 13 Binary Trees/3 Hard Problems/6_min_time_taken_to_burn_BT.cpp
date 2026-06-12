#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

int minBurn(TreeNode* root, TreeNode* node) {
    unordered_map<TreeNode *,TreeNode *> parentPointer;  //node,parent
    queue<TreeNode *> q;
    
    //Mark parents
    q.push(root);
    while(!q.empty()){
        auto top=q.front();
        q.pop();

        if(top->left){
            parentPointer[top->left]=top;
            q.push(top->left);
        }
        if(top->right){
            parentPointer[top->right]=top;
            q.push(top->right);
        }
    } 

    //Traverse outward from starting Node
    unordered_set<TreeNode*> visited;
    int time=0;
    q.push(node);
    visited.insert(node);
    
    while(!q.empty()){ 
        int size=q.size();
        bool burned=false;

        for(int i=0;i<size;i++){
            auto top=q.front();
            q.pop();
            //Span outward
            if(top->left && !visited.count(top->left)){
                q.push(top->left); 
                visited.insert(top->left);
                burned=true;
            }
            if(top->right && !visited.count(top->right)){
                q.push(top->right);
                visited.insert(top->right);
                burned=true;
            }
            if(parentPointer.find(top)!=parentPointer.end() && !visited.count(parentPointer[top])){
                q.push(parentPointer[top]);
                visited.insert(parentPointer[top]);
                burned=true;
            }
        }
        if(burned) time++;  //To avoid incrementing at the last level of BFS traversal
    }
    return time;  
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->left=new TreeNode(14);
    root->left->right->left=new TreeNode(7);
    root->left->right->left->left=new TreeNode(66);
    root->left->right->left->left->left=new TreeNode(77);
    root->left->right->right=new TreeNode(23);
    root->left->right->right->right=new TreeNode(98);
    root->left->right->right->right->right=new TreeNode(18);
    root->right->right=new TreeNode(9);
    root->right->left=new TreeNode(5);

    //             1
    //         /       \
    //        2         3
    //      /   \     /   \
    //    14     4   5     9
    //          / \
    //         7   23
    //        /      \
    //      66        98
    //      /           \
    //    77             18

    cout<<minBurn(root,root->left->right);
    return 0;
}
