#include<iostream>
#include<vector>
#include<limits>
#include<map>

using namespace std;

int appearOnceBrute(vector<int> nums){
    for(int i=0;i<nums.size();i++){
        int count=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count==1){
            return nums[i];
        }
    }
    return -1;
}


int appearOnceBetter1(vector<int> nums){     //Does not qork in case of negetive numbers
    int maxi=numeric_limits<int>::min();
    for(auto it:nums){
        maxi=max(it,maxi);
    }

    vector<int> hash(maxi+1,0);

    for(auto it:nums){
        hash[it]++;
    }

    for(int i=0;i<hash.size();i++){
        if(hash[i]==1){
            return i;
        }
    }
    return -1;
}

int appearOnceBetter2(vector<int> nums){
    map<int,int> mpp;
    for(auto it:nums){
        mpp[it]++;
    }

    for(auto it:mpp){
        if(it.second==1){
            return it.first;
        }
    }

    return -1;
}

int appearOnceOptimal(vector<int> nums){
    int XOR=0;
    for(int i=0;i<nums.size();i++){
        XOR=XOR^nums[i];
    }
    return XOR;
}

int main(){
    vector<int> arr={1,1,2,2,3,3,4,5,5,6,6};
    int brute=appearOnceBrute(arr);
    cout<<brute<<endl;

    int better1=appearOnceBetter1(arr);
    cout<<better1<<endl;
    
    int better2=appearOnceBetter2(arr);
    cout<<better2<<endl;
    
    int optimal=appearOnceOptimal(arr);
    cout<<optimal<<endl;
    return 0;
}