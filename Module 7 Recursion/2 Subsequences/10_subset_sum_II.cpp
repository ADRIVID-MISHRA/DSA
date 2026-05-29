//LC 906
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        sub(nums,result,curr,0);
        return result;
    }

    void sub(vector<int> &nums,vector<vector<int>> &result,vector<int> &curr,int index){
        result.push_back(curr);
        // if(index==nums.size()){   //not needed as base case already handelled by for loop
        //     return;
        // }

        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;

            curr.push_back(nums[i]);
            sub(nums,result,curr,i+1);
            curr.pop_back();
        }
    }
};

int main(){
    vector<int> nums={2,2,1};
    Solution obj;
    vector<vector<int>> result=obj.subsetsWithDup(nums);

    for(auto i:result){
        cout<<'{';
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'}'<<endl;
    }
    return 0;
}