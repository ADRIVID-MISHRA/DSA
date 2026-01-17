#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

vector<vector<int>> four_sum_brute(vector<int> nums,int target){
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(),st.end());
}

vector<vector<int>> four_sum_better(vector<int> nums,int target){
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long> hashSet;
            for(int k=j+1;k<n;k++){
                long long rem=nums[i]+nums[j];
                rem+=nums[k];
                // rem=target-(nums[i]+nums[j]+nums[k]);
                rem=target-rem;
                if(hashSet.find(rem)!=hashSet.end()){
                    vector<int> temp={nums[i],nums[j],nums[k],static_cast<int>(rem)};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }
    return vector<vector<int>>(st.begin(),st.end());
}

vector<vector<int>> four_sum_optimal(vector<int> nums,int target){
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if (j!=i+1 && nums[j]==nums[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i] + nums[j]; 
                sum+= nums[k];
                sum+=nums[l];
                if (sum > target) {
                    l--;
                } else if (sum < target) {
                    k++;
                } else{
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    l--;
                    k++;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums={1,0,-1,0,-2,2};
    vector<vector<int>> ans;
    int target=0;
    ans=four_sum_brute(nums,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    ans=four_sum_better(nums,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    ans=four_sum_optimal(nums,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}