#include<iostream>
#include<vector>

using namespace std;

void genRec(string &curr,vector<string> &ans,int index,int n){
    if(index>=n){
        ans.push_back(curr);
        return;
    }  
    curr.push_back('0');
    genRec(curr,ans,index+1,n);
    curr.pop_back();

    if(curr.empty() || curr.back()!='1'){
        curr.push_back('1');
        genRec(curr,ans,index+1,n);
        curr.pop_back();
    }
}

vector<string> generateStrings(int n){
    string curr="";
    vector<string> ans;
    genRec(curr,ans,0,n);
    return ans;
}

int main(){
    int n=3; 
    vector<string> ans;
    ans=generateStrings(n);

    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}