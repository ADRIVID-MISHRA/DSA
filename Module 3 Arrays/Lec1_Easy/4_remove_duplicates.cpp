#include<iostream>
#include<set>
#include<vector>

using namespace std;

int removeDuplicates(int arr[],int n){
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int x=0;
    for(auto it:st){
        arr[x]=it;
        x++;
    }
    return x;
}

int removeDuplicatesOptimal(vector<int>& arr){
    int j=1,i=0;
    for( ;j<=arr.size()-1;j++){
        if(arr[j]!=arr[i]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;

}
int main(){
    int arr[]={1,1,1,1,1,1,1,3,3,3,3,3,4,4,4,33};
    int n = removeDuplicates(arr,size(arr));   //no of unique elements = n
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    vector<int> ar={1,2,2,2,2,2,2,3,3,3,3,3,4,4,4,33};
    int x= removeDuplicatesOptimal(ar);
    for(int i=0;i<x;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}