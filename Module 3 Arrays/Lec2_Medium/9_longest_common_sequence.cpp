#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<unordered_set>

using namespace std;

int lcs_brute(vector<int> arr){
    int longest=1;
    for(int i=0;i<arr.size();i++){
        int x=arr[i];
        int maxi=1;
        while(find(arr.begin(),arr.end(),x+1)!=arr.end()){
            x+=1;
            maxi++;
        }
        longest=max(longest,maxi);
    }
    return longest;
}

int lcs_better(vector<int> nums){
    if(nums.empty())return 0;
    sort(nums.begin(),nums.end());
    int current=nums[0];
    int maxi=1,length=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==current){
            continue;
        }
        if(nums[i]==current+1){
            maxi=maxi+1;
            current++;
        }else{
            current=nums[i];
            maxi=1;
        }
        length=max(maxi,length);
    }
    // length=max(maxi,length);
    return length;
}

int lcs_optimal(vector<int> nums){
    if(nums.empty())return 0;
    unordered_set<int> st;
    int longest=1;
    for(auto it:nums){
        st.insert(it);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){     //it is first element
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                cnt++;
                x++;
            }        
            longest=max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> arr={102,1,4,2,101,3,1,2,3,4,1,8,6,2,4,5,7,10,4,543,35,3454,224432};
    cout<<lcs_brute(arr)<<endl;
    cout<<lcs_better(arr)<<endl;
    cout<<lcs_optimal(arr)<<endl;

    return 0;
}