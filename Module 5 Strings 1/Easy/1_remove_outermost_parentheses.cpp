#include<iostream>

using namespace std;

class Solution{
public:
    string removeOuterParentheses(const string &s) {
        string ans="";
        int count=0;
        for(int i=0;i<s.size();i++){                  //Add '(' only if count > 0 before increment
            if(s[i]=='('){                              //Add ')' only if count > 0 after decrement
                if(count>0) ans+=s[i];
                count++;
            }else{
                count--;
                if(count>0) ans+=s[i]; 
            }
        }
        return ans;
    }
};

int main(){
    string s="(()())(())(()(()))";
    string ss="()(()())(())";
    Solution sol;
    cout<<sol.removeOuterParentheses(ss);
    return 0;
}