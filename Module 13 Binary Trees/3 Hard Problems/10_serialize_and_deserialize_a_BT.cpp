//LC 297
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val,TreeNode *left=nullptr,TreeNode *right=nullptr) 
        :val(val),left(left),right(right) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial;
        if(root==nullptr) return serial;
        queue<TreeNode *> q;

        q.push(root);
        while(!q.empty()){
            TreeNode *front=q.front();
            q.pop();
            if(front==nullptr){
                serial.append("#,");  //use += or append to add a string to a strign, and push_back to add a single character
                continue;
            }
            serial+=to_string(front->val);
            serial.push_back(',');

            q.push(front->left);
            q.push(front->right);
        }
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream ss(data);
        string node;
        getline(ss,node,',');

        TreeNode *root=new TreeNode(stoi(node));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();

            getline(ss,node,',');
            if(node!="#"){
                front->left=new TreeNode(stoi(node));
                q.push(front->left);
            }
            
            getline(ss,node,',');
            if(node!="#"){
                front->right=new TreeNode(stoi(node));
                q.push(front->right);
            }
        }
        return root;
    }
};


//Just for printing the BT
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

    Codec ser, deser;
    string serialized=ser.serialize(root);
    cout<<serialized<<endl<<endl;
    TreeNode* ans = deser.deserialize(serialized);

    //BFS
    vector<vector<int>> bfs=levelOrder(ans);
    for(auto it:bfs){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
