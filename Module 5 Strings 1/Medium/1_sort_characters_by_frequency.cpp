#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(auto i:s){
            mpp[i]++;
        }
        vector<pair<char,int>> vec(mpp.begin(),mpp.end());

        sort(vec.begin(),vec.end(),[](pair<char,int> &a,pair<char,int> &b){
            return a.second>b.second;
        });
        string ans;
        for(auto it:vec){
            // while(it.second !=0){
            //     ans+=it.first;
            //     it.second--;
            // }
            ans.append(it.second,it.first);
        }
        return ans;
    }

    // static bool comp(pair<char,int> &a,pair<char,int> &b){
    //     if(a.second > b.second) return true;
    //     return false;
    // }
};

int main() {
    string str="inteegger";
    Solution obj;
    cout<<obj.frequencySort(str);
    return 0;
}