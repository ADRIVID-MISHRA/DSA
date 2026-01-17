#include<iostream>
#include<vector>

using namespace std;

vector<int> rearrange_array_brute(vector<int> nums){
    vector<int> pos,neg;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]<0) neg.push_back(nums[i]);
        else pos.push_back(nums[i]);
    }
    // nums.clear();
    // int count1=0,count2=0;
    // for(int i=0;i<n;i++){
    //     if(i%2==0) nums.push_back(pos[count1++]);
    //     else nums.push_back(neg[count2++]);
    // }

    for(int i=0;i<n/2;i++){
        nums[i*2]=pos[i];
        nums[i*2+1]=neg[i];
    }
    return nums;
}


vector<int> rearrange_array_optimal(vector<int> nums) {
    int count1=0,count2=1;
    vector<int> res(nums.size());
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){ 
            res[count2]=nums[i]; 
            count2+=2; 
        }else{ 
            res[count1]=nums[i]; 
            count1+=2; 
        }
    }
    return res;
}

vector<int> rearrange_array_brute_modified(vector<int> nums){   //for unequal no of pos,neg
    vector<int> pos,neg;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]<0) neg.push_back(nums[i]);
        else pos.push_back(nums[i]);
    }
    for(int i=0;i<min(pos.size(),neg.size());i++){
        nums[i*2]=pos[i];
        nums[i*2+1]=neg[i];
    }
    if(pos.size()>neg.size()){
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            nums[index]=pos[i];
            index++;
        }
    }else{
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            nums[index]=neg[i];
            index++;
        }
    }
    return nums;
}

int main(){
    vector<int> arr1={-2,-3,-6,1,4,-9,2,3};
    vector<int> res1=rearrange_array_brute(arr1);
    for(auto it:res1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> res2=rearrange_array_optimal(arr1);
    for(auto it:res2){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> arr2={-2,-3,-6,1,4,-9,2,3,-9,-1,-2,4};
    vector<int> res3=rearrange_array_brute_modified(arr2);
    for(auto it:res3){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}