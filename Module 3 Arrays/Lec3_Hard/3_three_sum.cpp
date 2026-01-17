#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

vector<vector<int>> three_sum_brute(vector<int> nums){
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(),st.end());;
}

vector<vector<int>> three_sum_better(vector<int> nums){
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        set<int> hashSet;
        for(int j=i+1;j<n;j++){
            int rem=0-(nums[i]+nums[j]);
            if(hashSet.find(rem)!=hashSet.end()){
                vector<int> temp={nums[i],nums[j],rem};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    return vector<vector<int>>(st.begin(),st.end());
}

vector<vector<int>> three_sum_optimal(vector<int> nums){
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i]==nums[i-1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0) {
                k--;
            } else if (sum < 0) {
                j++;
            } else{
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                k--;
                j++;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans; 
}

int main(){
    vector<int> nums={-1,0,1,2,1,-4};
    vector<vector<int>> ans;
    ans=three_sum_brute(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    ans=three_sum_better(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    ans=three_sum_optimal(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}