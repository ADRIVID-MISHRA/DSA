#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:

    bool rotateStringBrute(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++){
            if(s==goal) return true;
            shiftLeft(s);
        }
        return false;
    }

    void shiftLeft(string &s){
        char temp=s[0];
        for(int i=1;i<s.size();i++){
            s[i-1]=s[i];
        }
        s[s.size()-1]=temp;
    }

    bool rotateStringBetter(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        for(int i=0;i<s.size();i++){
            if(s[i]==goal[0]){
                string temp=s;
                rotate(temp.begin(),temp.begin()+i,temp.end());
                if(temp==goal) return true;
            }
        }
        return false;
    }

    bool rotateStringOptimal(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        string doubleS=s+s;

        return doubleS.find(goal) != string::npos;
    }

};

int main(){
    string s="abcde", goal="cdeab";
    Solution obj;
    cout<<boolalpha;
    cout<<obj.rotateStringBrute(s,goal)<<endl;
    cout<<obj.rotateStringBetter(s,goal)<<endl;
    cout<<obj.rotateStringOptimal(s,goal)<<endl;
    return 0;
}
