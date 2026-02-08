#include<iostream>
#include<vector>

using namespace std;

int maxProductSubArrayBrute(vector<int> &nums){
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        int product=1;
        for(int j=i;j<nums.size();j++){
            product*=nums[j];
            maxi=max(maxi,product);
        }
    }
    return maxi;
}

int maxProductSubArrayOptimal(vector<int> &nums){
    int maxi=INT_MIN;
    int prefix=1,suffix=1;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix*=nums[i];
        suffix*=nums[n-1-i];
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;
}
int main(){
    vector<int> arr={2,3,-2,4};

    cout<<maxProductSubArrayBrute(arr)<<endl;
    cout<<maxProductSubArrayOptimal(arr);
    return 0;
}