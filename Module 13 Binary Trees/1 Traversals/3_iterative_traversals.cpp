#include<iostream>
#include<vector>
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

vector<int> iterativeInOrder(TreeNode *root){    //LC 94
    vector<int> ans;
    if(root==nullptr) return ans;
        
    stack<TreeNode *> s;
    TreeNode *node=root;
    while(true){
        if(node!=nullptr){
            s.push(node);
            node=node->left;
        }
        else{
            if(s.empty()) break;
            ans.push_back(s.top()->val);
            node=s.top()->right;
            s.pop();
        }
    }
    return ans;
}

vector<int> iterativePreOrder(TreeNode* root) {   //LC 144
    vector<int> ans;
    if(root==nullptr) return ans;
    
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){ 
        TreeNode *top=s.top();
        s.pop();

        ans.push_back(top->val);
        if(top->right!=nullptr) s.push(top->right);
        if(top->left!=nullptr) s.push(top->left);
    }
    return ans;
}

vector<int> iterativePostOrderTwoStack(TreeNode* root) {   //LC 145
    vector<int> ans;
    if(root==nullptr) return ans;

    stack<TreeNode *> s1;
    stack<int> s2;
    s1.push(root);

    while(!s1.empty()){
        TreeNode *top=s1.top();
        s1.pop();
        if(top->left!=nullptr) s1.push(top->left);
        if(top->right!=nullptr) s1.push(top->right);

        s2.push(top->val);
    }

    while(!s2.empty()){
        ans.push_back(s2.top());
        s2.pop();
    }
    return ans;
}

vector<int> iterativePostOrderOneStack(TreeNode* root) {   //LC 145
    vector<int> ans;
    if(root==nullptr) return ans;

    stack<TreeNode *> s;
    TreeNode *temp;
    TreeNode *curr=root;

    while(curr!=nullptr || !s.empty()){
        if(curr!=nullptr){
            s.push(curr);
            curr=curr->left;
        }
        else{
            temp=s.top()->right;
            if(temp==nullptr){
                temp=s.top();
                s.pop();
                ans.push_back(temp->val);
                while(!s.empty() && temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return ans;
}

void print(vector<int> &ans){
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    // root->left->right=new TreeNode(4);
    // root->left->left=new TreeNode(7);
    // root->right->right=new TreeNode(9);

    vector<int> inorder=iterativeInOrder(root);
    print(inorder);
    vector<int> preorder=iterativePreOrder(root);
    print(preorder);
    vector<int> postorder1=iterativePostOrderTwoStack(root);
    print(postorder1);
    vector<int> postorder2=iterativePostOrderOneStack(root);
    print(postorder2);

    return 0;
}