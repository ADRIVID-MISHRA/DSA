#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    int arr[]={1293,343,343,223,343};

    unordered_map<int,int> mpp;
    for(int i=0;i<size(arr);i++){
        mpp[arr[i]]++;
    }

    pair<int,int> max={0,0},min={size(arr),size(arr)};
    for(auto it:mpp){
        if(it.second>max.second){
            max={it.first,it.second};
        }
        if(it.second<min.second){
            min={it.first,it.second};
        }
    }
    cout<<"MAX: "<<max.first<<"->"<<max.second<<endl;
    cout<<"MIN: "<<min.first<<"->"<<min.second;


    return 0;
}