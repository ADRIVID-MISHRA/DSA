#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

void merge_brute(vector<int> &nums1, vector<int> &nums2){
    vector<int> ans;
    int m=nums1.size(),n=nums2.size();
    int i=0,j=0;
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            ans.push_back(nums1[i++]);
        }else{
            ans.push_back(nums2[j++]);
        }
    }
    while(i<m){
        ans.push_back(nums1[i++]);
    }
    while(j<n){
        ans.push_back(nums2[j++]);
    }
    
    for(int i=0;i<m+n;i++){
        if(i<m){
            nums1[i]=ans[i];
        }else{
            nums2[i-m]=ans[i];    
        }
    }
    // for(int i=m;i<n;i++){
    //     nums2[i-m]=ans[i];
    // }
}

void merge_optimal_one(vector<int> &nums1, vector<int> &nums2){
    int m=nums1.size(),n=nums2.size();
    int i=m-1;
    int j=0;
    while(i>=0 && j<n){
        if(nums1[i]>nums2[j]){
            swap(nums1[i--],nums2[j++]);
        }else{
            break;
        }
    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
}

void merge_optimal_two(vector<int> &nums1, vector<int> &nums2){
    int m=nums1.size();
    int n=nums2.size();
    int gap=static_cast<int>(ceil(static_cast<double>(m+n)/2));
    do{
        int i=0;
        int j=gap;
        if()

    }while(gap!=1);
}

int main(){
    vector<int> arr1={23,45,66,78,123};
    vector<int> arr2={32,33,45,67,73,89,90};
    merge_brute(arr1,arr2);

    for(auto i:arr1){
        cout<<i<<" ";
    }
    cout<<"|| ";
    for(auto i:arr2){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> arr3={23,45,66,78,123};
    vector<int> arr4={32,33,45,67,73,89,90};
    merge_optimal_one(arr3,arr4);

    for(auto i:arr3){
        cout<<i<<" ";
    }
    cout<<"|| ";
    for(auto i:arr4){
        cout<<i<<" ";
    }
    cout<<endl;
    
    vector<int> arr5={23,45,66,78,123};
    vector<int> arr6={32,33,45,67,73,89,90};
    merge_optimal_two(arr5,arr6);

    for(auto i:arr5){
        cout<<i<<" ";
    }
    cout<<"|| ";
    for(auto i:arr6){
        cout<<i<<" ";
    }
    return 0;
}