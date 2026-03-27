#include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest;

        for(int i=0;i<s.size();i++){
            //odd palindromes
            string s1=expand(s,i,i);
            //even palindrome
            string s2=expand(s,i,i+1);

            if(s1.size()>longest.size()) longest=s1;
            if(s2.size()>longest.size()) longest=s2;
        }
        return longest;
    }

    string expand(string &s,int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
};

int main(){
    string s="ababd";
    Solution obj;
    cout<<obj.longestPalindrome(s);
    return 0;
}