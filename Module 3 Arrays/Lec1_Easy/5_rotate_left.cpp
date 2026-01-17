#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateLeft(vector<int> & arr){
    auto temp=arr[0];
    for(int i=1;i<arr.size();i++){
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;
}

void rotateLeftByD(vector<int> &arr,int D){
    D=D%arr.size();
    vector<int> tempArr;
    for(int i=0;i<D;i++){
        tempArr.push_back(arr[i]);
    }
    for(int i=D;i<arr.size();i++){
        arr[i-D]=arr[i];
    }
    // int j=0;
    for(int i=arr.size()-D;i<arr.size();i++){
        arr[i]=tempArr[i-(arr.size()-D)];

        // ++j;
    }

}

void rotateLeftByD_optimal(vector<int> & arr,int d){
    d=d%arr.size();
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());
}

int main(){
    vector<int> arr={345,2,31,37,65,54,565,46};
    rotateLeft(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    int D=3;
    rotateLeftByD(arr,D);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    rotateLeftByD_optimal(arr,D);
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}