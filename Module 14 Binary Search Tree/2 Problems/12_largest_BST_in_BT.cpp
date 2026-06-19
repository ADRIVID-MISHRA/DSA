#include<iostream>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

class NodeValue{
    public:
    int size,maxNode,minNode;

    NodeValue(int s,int mn,int mx){
        size=s;
        minNode=mn;
        maxNode=mx;
    }
};

NodeValue largest(TreeNode* root){     //count, smallest, largest
    if(root==nullptr) return NodeValue(0,INT_MAX,INT_MIN);
    
    auto left=largest(root->left);
    auto right=largest(root->right);

    if(left.maxNode < root->val && right.minNode > root->val){
        return NodeValue(1+left.size+right.size,min(root->val,left.minNode),max(root->val,right.maxNode));
    }else{
        return NodeValue(max(left.size,right.size),INT_MIN,INT_MAX);
    }
}

int main(){
    TreeNode *root=new TreeNode(50);
    root->left=new TreeNode(300);
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

    //                 50
    //            /          \
    //          300           70
    //        /   \         /    \
    //      20     40      60     80
    //            /  \
    //          35    45
    //         /        \
    //       33          47
    //      /              \
    //    32                48

    auto ans=largest(root);
    cout<<ans.size;

    return 0;
}


// pair<int,pair<int,int>> largest(TreeNode* root){     //count, smallest, largest
//     if(root==nullptr) return {0,{INT_MAX,INT_MIN}};
//     if(root->left==nullptr && root->right==nullptr){
//         return {1,{root->val,root->val}};
//     }

//     pair<int,pair<int,int>> left,right;
//     left=largest(root->left);
//     right=largest(root->right);

//     if(root->val > left.second.second && root->val < right.second.first){
//         return {1+left.first+right.first,{min(root->val,left.second.first),max(root->val,right.second.second)}};
//     }else{
//         return {max(left.first,right.first),{INT_MIN,INT_MAX}};
//     }
// }