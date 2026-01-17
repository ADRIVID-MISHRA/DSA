#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateRight(vector<int> & arr){
    int temp=arr[arr.size()-1];
    for(int i=arr.size()-1;i>=1;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}

void rotateRightByD(vector<int> &arr,int D){
    D=D%arr.size();
    vector<int> tempArr;
    for(int i=arr.size()-D;i<arr.size();i++){
        tempArr.push_back(arr[i]);
    }
    for(int i=arr.size()-1;i>=D;i--){
        arr[i]=arr[i-D];
    }
    for(int i=0;i<D;i++){
        arr[i]=tempArr[i];
    }

}

void rotateRightByD_optimal(vector<int> & arr,int d){
    d=d%arr.size();
    reverse(arr.end()-d,arr.end());
    reverse(arr.begin(),arr.end()-d);
    reverse(arr.begin(),arr.end());
}

int main(){
    vector<int> arr={345,2,31,37,65,54,565,46};
    rotateRight(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    int D=3;
    rotateRightByD(arr,D);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    rotateRightByD_optimal(arr,D);
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}