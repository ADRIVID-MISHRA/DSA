#include<iostream>
#include<vector>

using namespace std;

void printSubsequencesSumK(vector<int> &nums,vector<int> &curr,int currSum,int k,int index){
    if(index==nums.size()){
        if(currSum==k){
            for(auto it:curr){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    //Don't take
    printSubsequencesSumK(nums,curr,currSum,k,index+1);

    //Take
    curr.push_back(nums[index]);
    printSubsequencesSumK(nums,curr,currSum+nums[index],k,index+1);
    curr.pop_back();
}

int main(){
    int k=3;
    vector<int> nums={3,2,5,1,4};
    vector<int> curr;
    printSubsequencesSumK(nums,curr,0,k,0);
    return 0;
}