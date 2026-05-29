#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void subsetSum(vector<int> &nums,vector<int> &result,int sum,int index){
    if(index==nums.size()){
        result.push_back(sum);
        return;
    }

    //not take
    subsetSum(nums,result,sum,index+1);

    //take
    subsetSum(nums,result,sum+nums[index],index+1);
}

int main(){
    vector<int> nums={3,1,2};
    vector<int> result;
    subsetSum(nums,result,0,0);

    sort(result.begin(),result.end());
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}