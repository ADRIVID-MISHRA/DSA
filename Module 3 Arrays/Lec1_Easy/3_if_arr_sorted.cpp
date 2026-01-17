#include<iostream>

using namespace std;

bool isSorted(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        if(arr[i]>=arr[i+1]) return false;
    }

    return true;
}

int main(){
    int arr1[]={1,2,3,4,5,6,7,8};
    int arr2[]={4,2,2,34,7,53,23};

    cout<<boolalpha;
    cout<<isSorted(arr1,size(arr1))<<endl;
    cout<<isSorted(arr2,size(arr2))<<endl;
    return 0;
}