//LC 103
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    queue<TreeNode *> q;
    q.push(root);

    bool flag=false;
    while(!q.empty()){
        int size=q.size();
        vector<int> level(size);
        for(int i=0;i<size;i++){
            TreeNode* top=q.front();
            q.pop();

            int index=flag?(size-1-i):i;   //insert from front or back of the level vector
            level[index]=top->val;

            if(top->left!=nullptr) q.push(top->left);
            if(top->right!=nullptr) q.push(top->right);
        }
        // if(count) reverse(level.begin(),level.end());    //count false means direction is from left to right
                                                //true means, direction is from right to left-> then reverse
        flag=!flag;
        ans.push_back(level);
    }
    return ans;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(-7);
    root->left->right->right=new TreeNode(-23);
    root->right->right=new TreeNode(9);

    vector<vector<int>> bfs=zigzagLevelOrder(root);
    for(auto it:bfs){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}