//LC 131
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        helper(result,curr,s,0);
        return result;
    }
    void helper(vector<vector<string>> &result,vector<string> &curr,string &s,int partition){
        if(partition==s.size()){
            result.push_back(curr);
            return;
        }
        for(int i=partition;i<s.size();i++){
            if(isPalindrome(s,partition,i)){
                curr.push_back(s.substr(partition,i-partition+1));
                helper(result,curr,s,i+1);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};

int main(){
    string inp="aab";
    Solution sol;
    vector<vector<string>> result=sol.partition(inp);
    for(auto it:result){
        for(auto s:it){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}