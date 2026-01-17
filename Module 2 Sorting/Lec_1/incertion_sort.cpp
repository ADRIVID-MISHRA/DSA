#include<iostream>

using namespace std;

int main(){
    int arr[]={23,24,2,4,234,234,23,423,4,45,3453};
    int n=size(arr);
    for(int i=1;i<=n-1;i++){
        int j=i;
        while(arr[j]<arr[j-1] && j>0){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}