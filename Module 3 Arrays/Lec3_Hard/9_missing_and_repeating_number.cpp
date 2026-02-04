#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> num_brute(vector<int> nums){
    int n=nums.size();
    int missing=-1,repeating=-1;
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i==nums[j]) count++;
        }
        if(count==2) repeating=i;
        if(count==0) missing=i;
        if(missing!=-1 && repeating!=-1) break;
    }
    return {repeating,missing};
}

vector<int> num_better(vector<int> nums){
    // unordered_map<int,int> mpp;
    vector<int> mpp(nums.size()+1,0);
    int missing=-1,repeating=-1;
    for(auto it:nums){
        mpp[it]++;
    }
    for(int i=1;i<=nums.size();i++){
        if(mpp[i]==2){
            repeating=i;
        }else if(mpp[i]==0){
            missing=i;
        }
        if(repeating!=-1 && missing!=-1) break;
    }
    return {repeating,missing};
}

int main(){
    vector<int> arr={1,8,3,4,4,5,6,2};
    vector<int> ans= num_brute(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans= num_better(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}