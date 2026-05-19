#include<iostream>
#include<vector>

using namespace std;

void powerSet(string &s,int index,string &curr,vector<string> &set){
    if(index>=s.size()){
        set.push_back(curr);
        return;
    }
    powerSet(s,index+1,curr,set);   //the order in which we call the recursive functions decides-
                                    //the order in which thy are updated in the set
    curr.push_back(s[index]);
    powerSet(s,index+1,curr,set);
    curr.pop_back();
}

int main(){
    string s="abc";
    string curr;
    vector<string> result;
    powerSet(s,0,curr,result);

    for(auto it:result){
        if(it=="") cout<<"{}"<<" ";
        else cout<<it<<" ";
    }
    cout<<endl<<"Size of set: "<<result.size();
    return 0;
}