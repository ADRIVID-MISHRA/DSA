#include<iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
        int sign=1;

        while(i<n && s[i]==' ') i++;   //leading spaces

        if(i<n && (s[i]=='+' || s[i]=='-')){    //sign handle
            if(s[i]=='-') sign=-1;
            i++;
        } 

        int result=0;
        while(i<n && isdigit(s[i])){
            int digit=s[i]-'0';
            if(result>(INT_MAX-digit)/10){
                return sign==-1?INT_MIN:INT_MAX;
            }

            result=result*10+digit;
            i++;
        }
        return result*sign;
    }
};

int main(){
    Solution obj;
    string s="    -09009--ojnwf08404";
    cout<<obj.myAtoi(s);
    return 0;
}