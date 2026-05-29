//LC 8
#include<iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // int i=0,n=s.size();
        // int sign=1;

        // while(i<n && s[i]==' ') i++;   //leading spaces

        // if(i<n && (s[i]=='+' || s[i]=='-')){    //sign handle
        //     if(s[i]=='-') sign=-1;
        //     i++;
        // } 

        // int result=0;
        // while(i<n && isdigit(s[i])){
        //     int digit=s[i]-'0';
        //     if(result>(INT_MAX-digit)/10){
        //         return sign==-1?INT_MIN:INT_MAX;
        //     }

        //     result=result*10+digit;
        //     i++;
        // }
        // return result*sign;
        int n=s.size();
        int i=0;
        int sign=1;
        while(i<n && s[i]==' ') i++;   //handle spaces and sign
        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign=s[i]=='-'?-1:1;
            i++;
        }
        return recursiveAtoi(s,i,n,sign,0); //string, i, n, sign, answer
    }

    int recursiveAtoi(string s, int i, int n, int sign, int ans){
        if(i>=n) return ans*sign;
        else if(isdigit(s[i])){
            int digit=s[i]-'0';
            if(ans>(INT_MAX-digit)/10){
                return sign==-1?INT_MIN:INT_MAX;
            }

            ans=ans*10+digit;
            return recursiveAtoi(s,++i,n,sign,ans);;
        }else{
            return ans*sign;
        }

    }
};

int main(){
    string s="   -43  09-";
    Solution obj;
    cout<<obj.myAtoi(s);
}