#include<iostream>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=0;
        for(char i:s){
            if(i=='(') count++;
            else if(i==')') count--;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};

int main() {
    string str="((1+(2*3)+((8)/4))+1)";
    Solution obj;
    cout<<obj.maxDepth(str);
    return 0;
}