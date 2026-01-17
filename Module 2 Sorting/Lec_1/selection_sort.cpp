#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int arr[]={23,24,21,145,6,33215,65462322,2,234};
    int n=size(arr);
    for(int i=0;i<=n-2;i++){
        int min_index=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        // swap(arr[i],arr[min_index]);
        int temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }

    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}