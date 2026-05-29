//LC 216
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        comSum(result,curr,k,n,1);  //1 is the start of the for loop of the next loop  
        return result;
    }
    
    void comSum(vector<vector<int>> &result,vector<int> &curr,int k,int n,int start){
        if(k==0 && n==0){
            result.push_back(curr);
            return;
        }
        if(k==0) return;

        for(int i=start;i<=9;i++){
            if(i>n) break;

            curr.push_back(i);
            comSum(result,curr,k-1,n-i,i+1);
            curr.pop_back();
        }
    }
};

int main(){
    int k=2,n=5;
    Solution obj;
    vector<vector<int>> result=obj.combinationSum3(k,n);

    for(auto i:result){
        cout<<'{';
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'}'<<endl;
    }
    return 0;
}