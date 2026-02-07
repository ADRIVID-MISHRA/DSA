#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> num_brute(vector<int> nums){
    int n=nums.size();
    int missing=-1,repeating=-1;
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i==nums[j]) count++;
        }
        if(count==2) repeating=i;
        if(count==0) missing=i;
        if(missing!=-1 && repeating!=-1) break;
    }
    return {repeating,missing};
}

vector<int> num_better(vector<int> nums){
    // unordered_map<int,int> mpp;
    vector<int> mpp(nums.size()+1,0);
    int missing=-1,repeating=-1;
    for(auto it:nums){
        mpp[it]++;
    }
    for(int i=1;i<=nums.size();i++){
        if(mpp[i]==2){
            repeating=i;
        }else if(mpp[i]==0){
            missing=i;
        }
        if(repeating!=-1 && missing!=-1) break;
    }
    return {repeating,missing};
}


vector<int> num_optimal_one(vector<int> nums){
    int n=nums.size();
    long long S=0,SN,S2=0,SN2;
    SN=( n*(n+1) )/ 2;
    SN2=(n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++){
        S=S+nums[i];
        S2=S2+(long long)nums[i]*(long long)nums[i];
    }
    //x-y
    long long val1=S-SN;

    //(x+y)*(x-y)
    long long val2=S2-SN2;
    //x+y
    val2=val2/val1;

    long long x=(val1+val2)/2;
    long long y=val2-x;
    return {(int)x,(int)y};
}

vector<int> num_optimal_two(vector<int> nums){
    int n=nums.size();
    int xr=0;
    //find xor
    for(int i=0;i<n;i++){
        xr^=nums[i];
        xr^=(i+1);
    }
    //find bitNo
    int bitNo=0;
    while(1){
        if((xr & (1<<bitNo)) != 0) break;
        bitNo++;
    }

    // dividing and xor-ing based on bitset
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++){
        //part of 1 club
        if((nums[i]&(1<<bitNo))==0){
            one^=nums[i];
        }
        //part of 0 club
        else{
            zero^=nums[i];
        }
    }

    for(int i=1;i<=n;i++){
        //part of 1 club
        if((i&(1<<bitNo))==0){
            one^=i;
        }
        //part of 0 club
        else{
            zero^=i;
        }
    }

    //count which is which
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i]==one) count++;
    }
    if(count==0){   //one is missing zero is repeating
        return {zero,one};
    }else{          //zero is missing one is repeating
        return {one,zero};
    }
    
}

int main(){
    vector<int> arr={1,8,3,4,4,5,6,2};
    vector<int> ans= num_brute(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans= num_better(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans= num_optimal_one(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans= num_optimal_two(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}