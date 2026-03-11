#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isAnagramBrute(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }

    bool isAnagramOptimal(string s, string t) {
        if(s.size()!=t.size()) return false;
        // map<char,int> mppS,mppT;
        // for(int i=0;i<s.size();i++){
        //     mppS[s[i]]++;    //map based approach (for any string not only lowercase letters)
        //     mppT[t[i]]++;
        // }
        // // for(auto it:mppS){
        // //     if(it.second!= mppT[it.first]) return false;
        // // }
        // if(mppS!=mppT) return false;
        // return true;
        vector<int> hashArr(26,0);
        for(int i=0;i<s.size();i++){
            hashArr[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            hashArr[t[i]-'a']--;
        }
        for(int i=0;i<hashArr.size();i++){
            if(hashArr[i]!=0)return false;
        }
        return true;
    }
};

int main() {
    string str1 = "integer";
    string str2 = "teinreg";

    Solution obj;
    cout<<boolalpha;
    cout<<obj.isAnagramBrute(str1,str2)<<endl;;
    cout<<obj.isAnagramOptimal(str1,str2);

    return 0;
}
