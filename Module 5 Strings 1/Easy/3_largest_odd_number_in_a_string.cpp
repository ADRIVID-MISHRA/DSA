#include<iostream>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            } 
        }
        return "";   //no odd numbers/digits found   
    }
};

int main(){
    string s="2496294629462";
    Solution sol;
    cout<<sol.largestOddNumber(s);
    return 0;
}

