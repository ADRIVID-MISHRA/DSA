//LC 17
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    unordered_map<int,string> keys{
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string curr;
        letCom(result,curr,digits,0);
        return result;
    }

    void letCom(vector<string> &result,string &curr,string &digits,int index){
        if(index==digits.size()){
            result.push_back(curr);
            return;
        }
        string str=keys[digits[index]-'0'];
        for(auto ch:str){
            curr.push_back(ch);
            letCom(result,curr,digits,index+1);
            curr.pop_back();
        }        
    }
};

int main(){
    Solution obj;
    vector<string> result=obj.letterCombinations("79");

    for(auto i:result){
        cout<<'{';
        cout<<i;
        cout<<'}'<<endl;
    }
    return 0;
}