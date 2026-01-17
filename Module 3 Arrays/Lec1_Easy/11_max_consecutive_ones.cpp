#include<iostream>
#include<vector>
// #include<algorithm>

using namespace std;

int maxConsecutiveOnes(vector<int> nums){
    int maxi=0,count=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==1){
            count++;
            maxi=max(maxi,count);
        }
        if(nums[i]!=1){
            count=0;
        }
    }
    return maxi;
}

int main(){
    vector<int> arr={1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,1,1,0,1,1,1,1};

    int optimal=maxConsecutiveOnes(arr);
    cout<<optimal<<endl;
    return 0;
}