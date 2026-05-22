//LC 40
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        comSum(candidates,result,curr,target,0);
        return result;
    }

    void comSum(vector<int> &candidates,vector<vector<int>> &result,vector<int> &curr,int target,int index){
        if(target==0){
            result.push_back(curr);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(candidates[i]>target) break;   //as candidates are sorted, it will not satisfy the conditions going forward
            if(i!=index && candidates[i]==candidates[i-1]) continue;      //avoid already picked elements
            //take  
            curr.push_back(candidates[i]);
            comSum(candidates,result,curr,target-candidates[i],i+1);
            curr.pop_back();
        }
    }
};

int main(){
    vector<int> candidates={1,1,1,2,2};
    int target=4;
    Solution obj;
    vector<vector<int>> result=obj.combinationSum2(candidates,target);

    for(auto i:result){
        cout<<'{';
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'}'<<endl;
    }
    return 0;
}