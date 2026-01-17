#include<iostream>
#include<vector>
#include<map>

using namespace std;

int subarray_sum_k_brute(vector<int> nums,int t){
    int c=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+nums[k]; 
            }
            if(sum==t) c++;
        }
    }
    return c;
}

int subarray_sum_k_better(vector<int> nums,int k){
    int c=0;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum=sum+nums[j];
            if(sum==k) c++;
        }
    }
    return c;
}

int subarray_sum_k_optimal(vector<int> nums,int k){
    // int prefix_sum=0,count=0;
    // map<int,int> mpp;
    // for(int i=0;i<nums.size();i++){
    //     if(mpp.find(prefix_sum)==mpp.end()){
    //         mpp[prefix_sum]=1;
    //     }else{
    //         mpp[prefix_sum]++;
    //     }
    //     prefix_sum+=nums[i];
    //     if(mpp.find(prefix_sum-k)!=mpp.end()){
    //         count+=mpp[prefix_sum-k];
    //     }
    // }
    // return count;

    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i = 0; i < nums.size(); i++) {
        preSum += nums[i];
        int remove = preSum - k;
        cnt += mpp[remove];      //  if(mpp.find(remove) != mpp.end()) {
                                 //     cnt += mpp[remove];
                                 // }
        mpp[preSum] += 1;
    }
    return cnt;
}

int main(){
    vector<int> arr={2,-3,4,-4,1,-2,2,3,1,3,4,5,-3,-4,8,-4};
    int k=3;
    cout<<subarray_sum_k_brute(arr,k)<<endl;
    cout<<subarray_sum_k_better(arr,k)<<endl;
    cout<<subarray_sum_k_optimal(arr,k)<<endl;
    return 0;
}