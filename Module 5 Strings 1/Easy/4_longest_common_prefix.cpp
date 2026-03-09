#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string str1=strs[0],str2=strs[strs.size()-1];
        int minLen=min(str1.size(),str2.size());
        for(int i=0;i<minLen;i++){
            if(str1[i]!=str2[i]) return str1.substr(0,i);
        }
        return str1;
    }
};

int main(){
    vector<string> strs={"flower","flow","flight"};
    Solution sol;
    cout<<sol.longestCommonPrefix(strs);
    return 0;
}