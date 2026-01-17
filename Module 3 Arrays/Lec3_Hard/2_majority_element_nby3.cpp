#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<limits>
using namespace std;

vector<int> majority_element_brute(vector<int> nums){
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        // if(result.size()==2) break;
        // if(find(result.begin(),result.end(),nums[i])!=result.end()) continue;
        // c=0;
        // for(int j=i;j<nums.size();j++){
        //     if(nums[i]==nums[j]){
        //         c++;
        //     }
        // }
        // if(c>nums.size()/3) result.push_back(nums[i]);

        if(result.size()==0 || result[0]!=nums[i]){
            int c=0;
            for(int j=i;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    c++;
                }
            }
            if(c>nums.size()/3) result.push_back(nums[i]);

        }
        if(result.size()==2) break;
    }
    return result;
}

vector<int> majority_element_better(vector<int> nums){
    vector<int> result;
    map<int,int> mpp;
    int min_count=nums.size()/3+1;
    for(auto it:nums){
        mpp[it]++;
        if(mpp[it]==min_count){  //so that it only gets added once
            result.push_back(it);
        }
    }
    return result;
}


vector<int> majority_element_optimal(vector<int> nums){
    vector<int> result;
    int el1=numeric_limits<int>::min();
    int el2=numeric_limits<int>::min();
    int c1=0,c2=0;
    for(int i=0;i<nums.size();i++){
        if(c1==0 && el2!=nums[i]){
            c1++;
            el1=nums[i];
        }
        else if(c2==0 && el1!=nums[i]){
            c2++;
            el2=nums[i];
        }
        else if(nums[i]==el1){
            c1++;
        }
        else if(nums[i]==el2){
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }

    c1 = 0;
    c2 = 0;
    for (auto it : nums) {
        if (it == el1)
            c1++;
        else if (it == el2)
            c2++;
    }
    if(c1>nums.size()/3){
        result.push_back(el1);
    }
    if(c2>nums.size()/3){
        result.push_back(el2);
    }
    return result;
}

int main(){
    vector<int> arr={2,3,3,4,3,3,3,2,3};
    vector<int> ans;
    ans=majority_element_brute(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

    ans=majority_element_better(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

    ans=majority_element_optimal(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}