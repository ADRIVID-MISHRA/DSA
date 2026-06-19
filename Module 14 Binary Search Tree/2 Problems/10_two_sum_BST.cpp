//LC 653
#include<iostream>
#include<stack>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

class BSTIterator {
private:
    stack<TreeNode *> st;
    bool isReverse=true;
public:
    BSTIterator(TreeNode* root,bool rev) {
        isReverse=rev;
        pushAll(root);
    }
    
    int next() {
        TreeNode *top=st.top();
        st.pop();
        if(isReverse) pushAll(top->left);
        else pushAll(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode *root){  //push all elements going full left
        while(root!=nullptr){
            st.push(root);
            if(isReverse) root=root->right;
            else root=root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator *it1=new BSTIterator(root,false);  //inorder
        BSTIterator *it2=new BSTIterator(root,true);  //reverse inorder

        int i=it1->next();
        int j=it2->next();
        while(i!=j){
            if(i+j==k) return true;
            // if(!it1->hasNext() || !it2->hasNext()) break;   //The iterators can never run out of elements before the pointers meet/cross.
            else if(i+j<k) i=it1->next();
            else j=it2->next();
        }
        return false;
    }
};

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

    //                 50
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

    Solution obj;
    cout<<boolalpha<<obj.findTarget(root,100)<<endl;
    cout<<obj.findTarget(root,99)<<endl;
    return 0;
}

//AVOID USING SEPERATE ITERATOR CLASSES, THIS INCREASES REPEATED CODES

// class BSTIteratorAscending {
// private:
//     stack<TreeNode *> st;
// public:
//     BSTIteratorAscending(TreeNode* root) {
//         pushAll(root);
//     }
    
//     int next() {
//         TreeNode *top=st.top();
//         st.pop();
//         pushAll(top->right);
//         return top->val;
//     }

//     bool hasNext() {
//         return !st.empty();
//     }
    
//     void pushAll(TreeNode *root){  //push all elements going full left
//         while(root!=nullptr){
//             st.push(root);
//             root=root->left;
//         }
//     }
// };

// class BSTIteratorDescending {
// private:
//     stack<TreeNode *> st;
// public:
//     BSTIteratorDescending(TreeNode* root) {
//         pushAll(root);
//     }
    
//     int next() {
//         TreeNode *top=st.top();
//         st.pop();
//         pushAll(top->left);
//         return top->val;
//     }
    
//     bool hasNext() {
//         return !st.empty();
//     }

//     void pushAll(TreeNode *root){  //push all elements going full left
//         while(root!=nullptr){
//             st.push(root);
//             root=root->right;
//         }
//     }
// };

// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         BSTIteratorAscending* it1 = new BSTIteratorAscending(root);
//         BSTIteratorDescending* it2 = new BSTIteratorDescending(root);

//         int i=it1->next();
//         int j=it2->next();

//         while(i!=j){
//             if(!it1->hasNext() || !it2->hasNext()) break;
//             if(i+j==k) return true;
//             else if(i+j<k) i=it1->next();
//             else j=it2->next();

//         }
//         return false;
//     }
// };