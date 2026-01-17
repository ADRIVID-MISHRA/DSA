#include<iostream>
#include<map>

using namespace std;

int main(){
    int arr[]={23,1,45,1000003000,23,1,1,1,3};

    map<int,int> mpp;
    for(int i=0;i<size(arr);i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        cout<<it.first<<" -->> "<<it.second<<endl;
    }

    int q;
    cout<<"enter number of searches: ";
    cin>>q;

    while(q--){
        int temp;
        cout<<"Enter search: ";
        cin>>temp;

        cout<<mpp[temp]<<endl;
    }




    return 0;
}