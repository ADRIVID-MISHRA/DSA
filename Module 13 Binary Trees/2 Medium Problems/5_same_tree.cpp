//LC 100
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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr || q==nullptr){
        return p==q;    //both are nulllptr then return treu otherwise return false
    }

    // if(p->val!=q->val) return false;
    // if(!isSameTree(p->left,q->left)) return false;
    // if(!isSameTree(p->right,q->right)) return false;

    // return true;
    return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right); //If either of them returns false then return false,, otherwise return true
}

int main(){
    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    root1->left->right=new TreeNode(4);
    root1->left->right->left=new TreeNode(-7);
    // root1->right->right=new TreeNode(9);

    TreeNode *root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);
    root2->left->right=new TreeNode(4);
    root2->left->right->left=new TreeNode(-7);
    root2->right->right=new TreeNode(9);

    cout<<boolalpha<<isSameTree(root1,root2);
    return 0;
}