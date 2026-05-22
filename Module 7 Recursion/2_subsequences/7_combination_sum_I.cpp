//LC 39
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        comSum(candidates,curr,result,0,target);
        return result;
    }

    void comSum(vector<int> &candidates,vector<int> &curr, vector<vector<int>> &result,int index,int target){
        if(index==candidates.size()){
            if(target==0){
                result.push_back(curr);
            }
            return;
        }

        //Take and stay in the same index //only if it is able to form a valid combination
        if(candidates[index]<=target){
            curr.push_back(candidates[index]);
            comSum(candidates,curr,result,index,target-candidates[index]);
            curr.pop_back();
        }

        //Don't take and proceed to the next
        comSum(candidates,curr,result,index+1,target);
    }
};

int main(){
    vector<int> candidates={2,3,1,4};
    int target=6;
    Solution obj;
    vector<vector<int>> result=obj.combinationSum(candidates,target);

    for(auto i:result){
        cout<<'{';
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'}'<<endl;
    }
    return 0;
}