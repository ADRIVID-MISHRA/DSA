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

int findCeil(TreeNode *root,int key){
    int ceil=0;    //return 0 if not found
    TreeNode *curr=root;
    while(curr!=nullptr){
        if(curr->val >= key){
            ceil=curr->val;
            curr=curr->left;
        }else{
            curr=curr->right;
        }
    }
    return ceil;
}

int findFloor(TreeNode *root,int key){
    int floor=0;   //return 0 if not found
    TreeNode *curr=root;
    while(curr!=nullptr){
        if(curr->val <= key){
            floor=curr->val;
            curr=curr->right;
        }else{
            curr=curr->left;
        }
    }
    return floor;
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

    int ceil=findCeil(root,46);
    cout<<ceil<<endl;
 
    int floor=findFloor(root,46);
    cout<<floor<<endl;
    return 0;
}
