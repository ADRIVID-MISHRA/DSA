#include<iostream>

using namespace std;

int main(){
    int arr[]={3,2,5,5,8};
    int hash[9]={0};

    for(auto i:arr){
        hash[i]++;
    }

    int q;
    cout<<"Enter number of searches: ";
    cin>>q;
    while(q--){
        int tem;
        cout<<"number to search: ";
        cin>>tem;
        cout<<hash[tem]<<endl;
    }

    return 0;
}