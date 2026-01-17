#include<iostream>
#include<vector>
#include<map>

using namespace std;

int subarray_xor_k_brute(vector<int> nums,int t){
    int c=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int xr=0;
            for(int k=i;k<=j;k++){
                xr=xr^nums[k]; 
            }
            if(xr==t) c++;
        }
    }
    return c;
}

int subarray_xor_k_better(vector<int> nums,int k){
    int c=0;
    for(int i=0;i<nums.size();i++){
        int xr=0;
        for(int j=i;j<nums.size();j++){
            xr=xr^nums[j];
            if(xr==k) c++;
        }
    }
    return c;
}

int subarray_xor_k_optimal(vector<int> nums,int k){
    map<int, int> mpp;
    mpp[0] = 1;
    int xr = 0, cnt = 0;
    for(int i = 0; i < nums.size(); i++) {
        xr^= nums[i];
        int rem = xr ^ k;
        cnt += mpp[rem];      //  if(mpp.find(remove) != mpp.end()) {
                                 //     cnt += mpp[remove];
                                 // }
        mpp[xr] += 1;
    }
    return cnt;
}

int main(){
    vector<int> arr={2,-3,4,-4,1,-2,2,3,1,3,4,5,-3,-4,8,-4};
    int k=3;
    cout<<subarray_xor_k_brute(arr,k)<<endl;
    cout<<subarray_xor_k_better(arr,k)<<endl;
    cout<<subarray_xor_k_optimal(arr,k)<<endl;
    return 0;
}