#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> unionBrute(vector<int> arr1, vector<int> arr2){
    set<int> temp;
    for(int it:arr1){
        temp.insert(it);
    }
    for(int it:arr2){
        temp.insert(it);
    }
    vector<int> ret;
    for(int it:temp){
        ret.push_back(it);
    }
    return ret;
}

vector<int> unionOptimal(vector<int> arr1,vector<int> arr2){
    // int i=0,j=0;
    // vector<int> union_arr;
    // while(i<arr1.size() && j<arr2.size()){
    //     if(!union_arr.empty() && arr1[i]==union_arr.back()){
    //         i++;
    //         continue;
    //     }
    //     if(!union_arr.empty() && arr2[j]==union_arr.back()){
    //         j++;
    //         continue;
    //     }
    //     if(arr1[i]<arr2[j]){
    //         union_arr.push_back(arr1[i]);
    //         i++;
    //         continue;
    //     }
    //     if(arr1[i]>arr2[j]){
    //         union_arr.push_back(arr2[j]);
    //         j++;
    //         continue;
    //     }
    //     if(arr1[i]==arr2[j]){
    //         union_arr.push_back(arr2[j]);
    //         j++;
    //         i++;
    //     }
    // }
    // while(i < arr1.size()){
    //     if(union_arr.empty() || arr1[i] != union_arr.back())
    //         union_arr.push_back(arr1[i]);
    //     i++;
    // }

    // while(j < arr2.size()){
    //     if(union_arr.empty() || arr2[j] != union_arr.back())
    //         union_arr.push_back(arr2[j]);
    //     j++;
    // }
    // return union_arr;





    int n=arr1.size(),m=arr2.size();
    int i = 0, j = 0; // pointers
    vector < int > Union; // Uninon vector
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]){ // Case 1 and 2
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
        i++;
        } 
        else{ // case 3
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n){ // IF any element left in arr1
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m){ // If any elements left in arr2
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}

int main(){
    vector<int> arr1={3,3,4,4,4,5,6,7,32,32,54};
    vector<int> arr2={2,2,3,4,5,6,54,66};
    
    vector<int> brute=unionBrute(arr1,arr2);
    for(int it:brute){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> optimal=unionOptimal(arr1,arr2);
    for(int it:optimal){
        cout<<it<<" ";
    }
    return 0;
}