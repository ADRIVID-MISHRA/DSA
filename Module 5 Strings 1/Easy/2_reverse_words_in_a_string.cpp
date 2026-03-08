#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    string reverseWordsBrute(string s) {
        vector<string> words;
        string word="";

        for(char i:s){
            if(i!=' '){
                word+=i;
            }
            // else if(i==' ' && word!=""){
            //     words.push_back(word);
            //     word="";
            // }
            else if(!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }

        if(!word.empty()){
            words.push_back(word);
        }

        reverse(words.begin(),words.end());
        string ans;
        for(auto i:words){
            ans+=i;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }

    string reverseWordsOptimal(string s) {
        // string ans;
        // string temp="";   //my first logic
        // bool plsAdd=false;
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]==' '){
        //         if(plsAdd==1){
        //             reverse(temp.begin(),temp.end());
        //             ans+=temp;
        //             ans+=' ';
        //             temp="";
        //             plsAdd=false;
        //         }
        //     }
        //     else{
        //         temp+=s[i];
        //         plsAdd=true;
        //     }
        // }
        // if(plsAdd==1){
        //     reverse(temp.begin(),temp.end());
        //     ans+=temp;
        //     ans+=' ';
        // }
        // ans.pop_back();
        // return ans;

        string result;
        int i=s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            if(i<0) break;
            int endIndex=i;
            while(i>=0 && s[i]!=' ') i--;
            int startIndex=i+1;
            if(!result.empty()) result+=' ';
            result+=s.substr(startIndex,endIndex-startIndex+1);
            // result+=' ';
        }
        // result.pop_back();
        return result;
    }
};

int main(){
    string  s= "a good   example  ";
    Solution obj;
    cout<<obj.reverseWordsBrute(s)<<endl;
    cout<<obj.reverseWordsOptimal(s);
    return 0;
}