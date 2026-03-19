#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // unordered_map<char,int> symbols={ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
        vector<int> symbols(256, 0);
        symbols['I'] = 1;
        symbols['V'] = 5;
        symbols['X'] = 10;
        symbols['L'] = 50;
        symbols['C'] = 100;
        symbols['D'] = 500;
        symbols['M'] = 1000;
        int number=0,i=s.size()-1,curr,prev=0;
        while(i>=0){
            // if(s[i-1]=='I' && s[i]=='V'){
            //     number+=4;
            //     i-=2;
            // }else if(s[i-1]=='I' && s[i]=='X'){
            //     number+=9;
            //     i-=2;
            // }else if(s[i-1]=='X' && s[i]=='L'){
            //     number+=40;
            //     i-=2;
            // }else if(s[i-1]=='X' && s[i]=='C'){
            //     number+=90;
            //     i-=2;
            // }else if(s[i-1]=='C' && s[i]=='D'){
            //     number+=400;
            //     i-=2;
            // }else if(s[i-1]=='C' && s[i]=='M'){
            //     number+=900;
            //     i-=2;
            // }else{
            //     number+=symbols[s[i]];
            //     i--;
            // }
            curr=symbols[s[i]];
            if(curr<prev) number-=curr;
            else number+=curr;
            prev=curr;
            i--;
        }
        // if(i>=0) number+=symbols[s[0]];
        return number;
    }
};

int main() {
    string str="MCMXCIV";   //1994
    Solution obj;
    cout<<obj.romanToInt(str);
    return 0;
}