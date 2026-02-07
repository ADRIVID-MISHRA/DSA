#include<iostream>
#include<vector> 

using namespace std;

// int cnt=0; 

int countInversionsBrute(vector<int> nums){
    int count=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]>nums[j]){
                count++;
            }
        }
    }
    return count;
}

// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp; // temporary array
//     int left = low;      // starting index of left half of arr
//     int right = mid + 1;   // starting index of right half of arr

//     //storing elements in the temporary array in a sorted manner//

//     while (left <= mid && right <= high) {
//         //left is smaller
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         //right is smaller
//         else {
//             cnt+=(mid-left+1);
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     // if elements on the left half are still left //

//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     //  if elements on the right half are still left //
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     // transfering all elements from temporary to arr //
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
// }

// void mergeSort(vector<int> &arr, int low, int high) {
//     if (low >= high) return;
//     int mid = (low + high) / 2 ;
//     mergeSort(arr, low, mid);  // left half
//     mergeSort(arr, mid + 1, high); // right half
//     merge(arr, low, mid, high);  // merging sorted halves
// }

// int countInversionsOptimal(vector<int> nums){
//     mergeSort(nums,0,nums.size()-1);
//     return cnt;
    
// }

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//
    int cnt=0;
    while (left <= mid && right <= high) {
        //left is smaller
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        //right is smaller
        else {
            cnt+=(mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
    }
    

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int count=0;
    if (low >= high) return count;
    int mid = (low + high) / 2 ;
    count+=mergeSort(arr, low, mid);  // left half
    count+=mergeSort(arr, mid + 1, high); // right half
    count+=merge(arr, low, mid, high);  // merging sorted halves
    return count;
}

int countInversionsOptimal(vector<int> nums){
    return mergeSort(nums,0,nums.size()-1);
}

int main(){
    vector<int> arr={5,3,2,4,1};

    cout<<countInversionsBrute(arr)<<endl;

    cout<<countInversionsOptimal(arr)<<endl;
    return 0;
}