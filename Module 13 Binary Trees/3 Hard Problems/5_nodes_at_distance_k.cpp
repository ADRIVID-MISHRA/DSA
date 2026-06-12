//LC 863
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

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
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

    //Traverse outward from target Node
    int distance=0;
    unordered_set<TreeNode*> visited;
    q.push(target);
    visited.insert(target);

    while(!q.empty()){
        if(distance==k) break;  //at this point we have all the nessary elements in the queue
        int size=q.size();
        for(int i=0;i<size;i++){
            auto top=q.front();
            q.pop();
            //Span outward
            if(top->left && !visited.count(top->left)){
                q.push(top->left); 
                visited.insert(top->left);
            }
            if(top->right && !visited.count(top->right)){
                q.push(top->right);
                visited.insert(top->right);
            }
            if(parentPointer.find(top)!=parentPointer.end() && !visited.count(parentPointer[top])){
                q.push(parentPointer[top]);
                visited.insert(parentPointer[top]);
            }
            
        }
        distance++;
    }
    
    vector<int> ans;
    while(!q.empty()){   //push necessary nodes at distance k from target in the ans vector
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
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

    vector<int> ans=distanceK(root,root->left->right,3);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
