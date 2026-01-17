#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int max_subarray_brute(vector<int> &nums){
    int maxSum=numeric_limits<int>::min();
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int sum=0;
            for(int z=i;z<=j;z++){
                sum=sum+nums[z];
            }
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

int max_subarray_better(vector<int> &nums){
    int maxSum=numeric_limits<int>::min();
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum=sum+nums[j];
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

int max_subarray_optimal(vector<int> &nums){
    int maxSum=numeric_limits<int>::min();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0){
                sum=0;
            }
        }
        return maxSum;
}

vector<pair<int,int>> max_subarray_optimal_modified(vector<int> &nums){
    int maxSum=numeric_limits<int>::min();
    vector<pair<int,int>> arr;
    int sum=0,start=0,arrStart,arrEnd;
    for(int i=0;i<nums.size();i++){
        if(sum==0){
            start=i;
        }
        sum=sum+nums[i];
        if(maxSum<sum){
            maxSum=sum;
            arrStart=start,arrEnd=i;
            arr.clear();
            arr.push_back({arrStart,arrEnd});
        }
        else if(sum == maxSum){
            arr.push_back({start, i});
        }
        
        if(sum<0){
            sum=0;
        }
    }
    return arr;
}

int main(){
    vector<int> nums={3, -2, 5, -1, 2, -2, 3, -1, 4, -3, -2, 5, -5, 3, -1, 3};

    cout<<max_subarray_brute(nums)<<endl;
    cout<<max_subarray_better(nums)<<endl;
    cout<<max_subarray_optimal(nums)<<endl;
    vector<pair<int,int>> arr =max_subarray_optimal_modified(nums);
    for(auto it:arr){
        for(int i=it.first;i<=it.second;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}