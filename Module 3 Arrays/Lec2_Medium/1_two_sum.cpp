#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<vector<int>> two_sum_brute(vector<int> &nums, int target){
    // vector<int> res;
    vector<vector<int>> res;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                // res.push_back(i);
                // res.push_back(j);
                // return res;
                res.push_back({i,j});
            }
        }
    }
    return res;
}

vector<int> two_sum_better(vector<int> &nums, int target){
    map<int,int> mpp;
    // vector<int> res;
    // for(int i=0;i<nums.size();i++){
    //     mpp[nums[i]]=i;
    // }
    for(int i=0;i<nums.size();i++){
        int rem=target-nums[i];
        if(mpp.find(rem)!=mpp.end()){
            // res.push_back(i);
            // res.push_back(mpp[rem]);
            // return res;
            return {i,mpp[rem]};
        }
        mpp[nums[i]]=i;
    }
    return {0,0};
}

bool two_sum_optimal(vector<int> &nums,int target){
    sort(nums.begin(),nums.end());
    int left =0;
    int right=nums.size()-1;

    while(left<right){
        if(nums[right]+nums[left]==target){
            // return {nums[right],nums[left]};
            return true;
        }
        else if(nums[right]+nums[left]>target){
            right--;
        }
        // if(nums[right]+nums[left]<target){
        //     left++;
        // }
        else{
            left++;
        }
    }
    return false;
}

int main(){
    vector<int> arr={34,54,12,44,6,2,4,5,1};
    int target=6;
    vector<vector<int>> result=two_sum_brute(arr,target);   //modified to return all the pairs
    if (result.empty()) {
        cout << "No pairs found.\n";
    }
    for(auto i:result){
        cout<<i[0]<<" "<<i[1]<<endl;
    }

    vector<int> res=two_sum_better(arr,target);
    for(auto i:res){
        cout<<i<<" ";
    }

    bool ress=two_sum_optimal(arr,target);
    cout<<endl<<ress;
    
    return 0;
}