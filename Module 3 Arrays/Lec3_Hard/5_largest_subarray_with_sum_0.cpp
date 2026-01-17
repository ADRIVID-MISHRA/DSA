#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int largest_subarray_brute(vector<int> nums){
    int largest =0;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum=sum+nums[j];
            if(sum==0){
                largest=max(largest,(j-i+1));
            }
        }
    }
    return largest;
}

int largest_subarray_optimal(vector<int> nums){
    int largest=0,prefix_sum=0;
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        prefix_sum+=nums[i];
        if(prefix_sum==0){
            largest=i+1;
        }
        if(mpp.find(prefix_sum)!=mpp.end()){
            largest=max(largest,i-mpp[prefix_sum]);
        }else{
            mpp[prefix_sum]=i;
        }
    }
    return largest;
}

int main(){
    vector<int> arr={1,-1,3,2,-2,-8,1,7,10,23};
    cout<<largest_subarray_brute(arr)<<endl;
    cout<<largest_subarray_optimal(arr);
    return 0;
}