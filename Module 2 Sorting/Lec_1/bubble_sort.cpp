#include<iostream>

using namespace std;

int main(){
    int arr[]={39,23,12,7657,45,646,3,34,234};
    int n=size(arr);

    for(int i=0;i<=n-1;i++){
        int count=0; 
        for(int j=0;j<=n-2-i;j++){   
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                count++;  
            }
        }
        if(count==0) break;
    }
        
    for(auto i:arr){
        cout<<i<<" ";
    }
        
    return 0;
}