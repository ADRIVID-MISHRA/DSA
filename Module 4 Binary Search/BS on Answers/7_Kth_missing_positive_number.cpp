#include<iostream>
#include<vector>

using namespace std;

int findKthPositiveLS(vector<int>& arr, int k) {
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=k) k++;
        else break;
    }
    return k;
}

int findKthPositiveBS(vector<int>& arr, int k) {
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if((arr[mid]-(mid+1))<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low+k;
}

int main(){
    vector<int> arr={2,3,4,7,11};
    int k=5;
    cout<<findKthPositiveLS(arr,k)<<endl;
    cout<<findKthPositiveBS(arr,k);
    return 0;
}