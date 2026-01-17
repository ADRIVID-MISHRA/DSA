#include<iostream>
#include<vector>

using namespace std;

void moveZeroBrute(vector<int> &nums){
    vector<int> temp;
    for(auto it:nums){
        if(it!=0){
            temp.push_back(it);
        }
    }
    
    for(int i=0;i<temp.size();i++){
        nums[i]=temp[i];
    }

    for(int i=temp.size();i<nums.size();i++){
        nums[i]=0;
    }
        
}

void moveZeroOptimal(vector<int> &nums){
    int i=0,j=1;
    for(j;j<nums.size();j++){
        if(nums[i]==0 && nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
            continue;
        }
        if(nums[i]!=0){
            i++;
        }
    }

    //striver's approach-Best
    // int j = -1;
    // //place the pointer j:
    // for (int i = 0; i < n; i++) {
    //     if (a[i] == 0) {
    //         j = i;
    //         break;
    //     }
    // }

    // //no non-zero elements:
    // if (j == -1) return a;

    // //Move the pointers i and j
    // //and swap accordingly:
    // for (int i = j + 1; i < n; i++) {
    //     if (a[i] != 0) {
    //         swap(a[i], a[j]);
    //         j++;
    //     }
    // }
}

int main(){
    vector<int> arr={223,3,0,98,35,0,0,395,0,355,0};
    moveZeroBrute(arr);
    for(int it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> arr2={223,0,3,98,35,0,0,395,0,355,0,32};
    moveZeroOptimal(arr2);
    for(int it:arr2){
        cout<<it<<" ";
    }
    return 0;
}