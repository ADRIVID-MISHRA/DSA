#include<iostream>
#include<vector>

using namespace std;

int missingBrute(vector<int> nums){
    int n=nums.size();
    for(int i=0;i<=n;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(nums[j]==i){
                flag++;
                break;
            }
        }
        if(flag==0) return i;
    }
    return -1;
}

int missingBetter(vector<int> nums){
    int n=nums.size();
    vector<int> hash(n+1,0);
    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }
    for(int i=0;i<=n;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;
}

int missingOptimalSum(vector<int> nums){
    int n=nums.size();
    int sum=n*(n+1)/2;
    for(auto it:nums){
        sum=sum-it;
    }
    return sum;
}

int missingOptimalXOR(vector<int> nums){
    int XOR1=0;
    int XOR2=0; 
    for(int i=0;i<nums.size();i++){
        XOR1=XOR1^i;
        XOR2=XOR2^nums[i];
    }
    XOR1=XOR1^nums[nums.size()-1];

    return XOR1^XOR2;
}

int main(){
    vector<int> arr={0,1,2,3,4,6,7,8,9,10,11};
    
    int brute=missingBrute(arr);
    cout<<"Missing num: "<<brute<<endl;

    int better=missingBetter(arr);
    cout<<"Missing num: "<<better<<endl;

    int optimal1=missingOptimalSum(arr);
    cout<<"Missing num: "<<optimal1<<endl;

    int optimal2=missingOptimalXOR(arr);
    cout<<"Missing num: "<<optimal2<<endl;
    return 0;
}