//Continuation of previous problem
#include<iostream>
#include<vector>

using namespace std;

int countSubsequences(vector<int> &nums,int currSum,int index,int k){
    if(index==nums.size()){
        if(currSum==k){
            return 1;
        }else{
            return 0;
        }
    }

    int count=0;
    //Dont's take
    count+=countSubsequences(nums,currSum,index+1,k);
    
    //Take
    count+=countSubsequences(nums,currSum+nums[index],index+1,k);

    return count;
    
}

int main(){
    vector<int> nums={4, 2, 10, 5, 1, 3};
    int k=5;
    cout<<countSubsequences(nums,0,0,k);
    return 0;
}