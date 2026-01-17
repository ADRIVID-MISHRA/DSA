#include<iostream>
// #include<string>

using namespace std;

int main(){
    string s="aaabbbhjj";

    int hash[26]={0};
    // int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
        // hash[s[i]]++;
    }

    for(char i='a';i<='z';i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:hash){
        cout<<i<<" ";
    }

    int q;
    cout<<endl<<"Enter number of searches: ";
    cin>>q;
    while(q--){
        char tem;
        cout<<"Character to search: ";
        cin>>tem;
        cout<<hash[tem-'a']<<endl;
        // cout<<hash[tem]<<endl;
    }
    return 0;
}