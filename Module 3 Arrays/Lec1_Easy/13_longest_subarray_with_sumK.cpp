#include<iostream>
#include<vector>
#include<map>

using namespace std;

int longest_subarray_brute(vector<int> &arr,int k){
    int count=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum=sum+arr[j];
            // if(k<sum){
            //     break;     //remove this if: works for zeros and negetive now
            // }
            if(k==sum){
                count=max(count,(j-i+1));
            }
        }
    }
    return count;
}

int longest_subarray_better(vector<int> &arr, int k){   //optimal for negetives+ zero, better for only posetives
    map<int,int> preSumMap;
    int prefixSum=0;
    int max_length=0;
    for(int i=0;i<arr.size();i++){
        prefixSum=prefixSum+arr[i];
        if(prefixSum==k){
            max_length=max(max_length,i+1);
        }
        int rem=prefixSum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            max_length=max(max_length,i-preSumMap[rem]);
        }
        if(preSumMap.find(prefixSum)==preSumMap.end()){
            preSumMap[prefixSum]=i;
        }
    }

    return max_length;
}

int longest_subarray_optimal(vector<int> &arr, int k){
    int left=0,right=0;
    int sum=arr[0];
    int max_len=0;
    while(right<arr.size()){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            max_len=max(max_len,right-left+1);
        }
        right++;
        if(right<arr.size()){
            sum=sum+arr[right];
        }
    }
    return max_len;
}

int main(){
    vector<int> arr={23,45,2,3,21,4,5,2,4,1,11,1,1,3,5,4,3,5,5};
    int k=4;
    int x=longest_subarray_brute(arr,k);
    cout<<x<<endl;

    int y=longest_subarray_better(arr,k);
    cout<<y<<endl;

    int z=longest_subarray_optimal(arr,k);
    cout<<z<<endl;
    return 0;
}