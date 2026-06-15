#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

vector<int> morrisInorder(TreeNode *root){
    vector<int> inorder;
    TreeNode *curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            inorder.push_back(curr->val);
            curr=curr->right;   
        }else{
            TreeNode *prev=curr->left;
            while(prev->right!=nullptr && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==nullptr){
                prev->right=curr;
                curr=curr->left;
            }else{
                inorder.push_back(curr->val);
                prev->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return inorder;
}

vector<int> morrisPreorder(TreeNode *root){
    vector<int> preorder;
    TreeNode *curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            preorder.push_back(curr->val);
            curr=curr->right;   
        }else{
            TreeNode *prev=curr->left;
            while(prev->right!=nullptr && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==nullptr){
                preorder.push_back(curr->val);
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return preorder;
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

    vector<int> inorder=morrisInorder(root);
    for(auto it:inorder){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> preorder=morrisPreorder(root);
    for(auto it:preorder){
        cout<<it<<" ";
    }
    return 0;
}
