#include<iostream>
#include<vector>

using namespace std;

vector<int> intersectionBrute(vector<int> arr1,vector<int> arr2){
    vector<int> ret;
    // int visited[arr2.size()]={0};
    vector<int> visited(arr2.size(), 0);
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            if(visited[j]!=1 && arr1[i]==arr2[j]){
                ret.push_back(arr1[i]);
                visited[j]=1;
                break;
            }
            if(arr1[i]<arr2[j]){
                break;
            }
        }
    }
    return ret;
}

vector<int> intersectionOptimal(vector<int> arr1,vector<int> arr2){
    int i=0,j=0;
    vector<int> ret;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            ret.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ret;
}

int main(){
    vector<int> arr1={3,3,4,4,4,5,6,7,32,32,54};
    vector<int> arr2={2,2,3,4,4,5,6,54,66};
    
    vector<int> brute=intersectionBrute(arr1,arr2);
    for(int it:brute){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> optimal=intersectionOptimal(arr1,arr2);
    for(int it:optimal){
        cout<<it<<" ";
    }
    return 0;
}