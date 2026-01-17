#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

void leaders_brute(vector<int> arr){
    vector<int> res;
    for(int i=0;i<arr.size();i++){
        bool isLeader=true;
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]<arr[j]){
                isLeader=false;
                break;
            }
        }
        if(isLeader){
            res.push_back(arr[i]);
        }
    }
    for(auto it:res){
        cout<<it<<" ";
    }
}

void leaders_optimal(vector<int> arr){
    int maxi=numeric_limits<int>::min();
    vector<int> res;
    // res.push_back(maxi);
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]>maxi){
            maxi=arr[i];
            res.push_back(maxi);
        }
    }
    reverse(res.begin(),res.end());
    for(int it:res){
        cout<<it<<" ";
    }
}

int main(){
    vector<int> arr={34,55,21,56,7,54,44,5};
    leaders_brute(arr);
    cout<<endl;
    leaders_optimal(arr);
    return 0;
}