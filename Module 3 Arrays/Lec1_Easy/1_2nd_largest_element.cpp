#include<iostream>
#include<algorithm>
#include<limits>

using namespace std;

int main(){
    int arr[]={234,1234,12,4,234,12,23,4,234,23,4,234,12,4,1234};
    //Brute
    int n=size(arr);
    sort(arr,arr+n);
    int second_largest=arr[n-2];
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=arr[n-1]){
            second_largest=arr[i];
            break;
        }
    }
    cout<<"2nd Largest: "<< second_largest<<endl;

    int ar[]={234,1234,12,4,234,12,23,4,234,23,4,234,12,4,1234};
    int largest=ar[0];
    for(int i:ar){
        if(i>largest) largest=i;
    }
    second_largest=numeric_limits<int>::min();
    for(int i=0;i<n;i++){
        if(ar[i]>second_largest && ar[i]!=largest){
            second_largest=ar[i];
        }
    }
    cout<<"2nd Largest: "<< second_largest<<endl;
    
    
    int a[]={234,1234,12,4,234,12,23,4,234,23,4,234,12,4,1234,700};
    largest=a[0];
    second_largest=numeric_limits<int>::min();
    for(auto it:a){
        if(it>largest){
            second_largest=largest;           //no need for if(second_largest!=largest)
            largest=it;
        }
        else if(it<largest && it>second_largest){
            second_largest=it;
        }
    }
    cout<<"Largest: "<<largest<<endl<<"2nd Largest: "<< second_largest<<endl;
    
    return 0;
}