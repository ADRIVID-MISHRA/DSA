#include<iostream>
#include<unordered_map>

using namespace std;

class Sollution{
    public:
    int atMostKDistinct(string s,int k){
        unordered_map<char,int> mpp;
        int count=0;
        int i=0;

        for(int j=0;j<s.size();j++){
            mpp[s[j]]++;

            while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0) mpp.erase(s[i]);
                i++;
            }

            count+=j-i+1;
        }
        return count;
    }
    
    int countSubstring(string s,int k){
        return atMostKDistinct(s,k)-atMostKDistinct(s,k-1);
    }
};

int main(){
    string s="pqpqs";
    int k=2;
    Sollution obj;
    cout<<obj.countSubstring(s,k);
    return 0;
}