//continuation of previous problem, this only returns true or false
#include<iostream>
#include<vector>

using namespace std;

bool subsequencesSumK(vector<int> &nums,vector<int> &curr,int currSum,int k,int index){
    if(index==nums.size()){
        if(currSum==k) return true;
        return false;
    }
    
    //Don't take
    if(subsequencesSumK(nums,curr,currSum,k,index+1)) return true;

    //take
    curr.push_back(nums[index]);
    if(subsequencesSumK(nums,curr,currSum+nums[index],k,index+1)) return true;
    curr.pop_back();
    return false;
}

int main(){
    int k=3;
    vector<int> nums={9,2,5,4};
    vector<int> curr;
    cout<<boolalpha<<subsequencesSumK(nums,curr,0,k,0);
    return 0;
}