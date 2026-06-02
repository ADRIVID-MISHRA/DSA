//LC 78 (also has a recursive approach done in recursion)
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    for(int i=0;i<(1<<nums.size());i++){
        vector<int> temp;
        for(int j=0;j<nums.size();j++){
            if(i&(1<<j)) temp.push_back(nums[j]);   //check if jth bit is set in i
        }
        result.push_back(temp);
    }
    return result;
}

int main(){
    vector<int> input={1,2,3};
    vector<vector<int>> result=subsets(input);
    for(auto it:result){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}