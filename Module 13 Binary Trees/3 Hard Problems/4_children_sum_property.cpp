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

void satisfyChildernSum(TreeNode *root){
    if(root==nullptr) return;
    
    int leftChild=(root->left)?root->left->val:0;
    int rightChild=(root->right)?root->right->val:0;

    int sumOfChildern=leftChild+rightChild;
    if(sumOfChildern < root->val){
        if(root->left) root->left->val=root->val;
        if(root->right) root->right->val=root->val;
    }else{
        root->val=sumOfChildern;
    }

    satisfyChildernSum(root->left);
    satisfyChildernSum(root->right);

    leftChild=(root->left)?root->left->val:0;
    rightChild=(root->right)?root->right->val:0;
    sumOfChildern=leftChild+rightChild;
    if(root->left || root->right) root->val=sumOfChildern;
}


//Helper function to print the answer
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

    //           1
    //       /      \
    //      2        3
    //    /   \    /   \
    //  14    4   5     9
    //       / \
    //      7   23
    //     /        \
    //    66          98
    //   /               \
    //  77                 18

    satisfyChildernSum(root);


    vector<vector<int>> ans=levelOrder(root);

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
