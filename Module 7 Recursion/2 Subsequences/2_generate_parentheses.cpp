//LC 22
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        backtrack(ans,curr,n,0,0);
        return ans;
    }

    void backtrack(vector<string> &ans,string curr,int n,int open,int close){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            backtrack(ans,curr,n,open+1,close);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            backtrack(ans,curr,n,open,close+1);
            curr.pop_back();
        }
    }
};

int main(){
    Solution obj;

    vector<string> ans=obj.generateParenthesis(4);
    for(auto it: ans){
        cout<<it<<"  ";
    }
    return 0;
}