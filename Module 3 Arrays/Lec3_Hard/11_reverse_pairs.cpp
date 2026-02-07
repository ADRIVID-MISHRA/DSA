#include<iostream>
#include<vector> 

using namespace std;

int reversePairsBrute(vector<int> nums){
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]>2*nums[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

//with global variable

// int count =0;
// void merge(vector<int>& arr, int low, int mid, int high) {
//     vector<int> temp;    // temporary array
//     int left = low;      // starting index of left half of arr
//     int right = mid + 1; // starting index of right half of arr
//     // storing elements in the temporary array in a sorted manner//
//     while (left <= mid && right <= high) {
//         // left is smaller
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         // right is smaller
//         else {
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
// void countPairs(vector<int> &nums,int low, int mid,int high){
//     int right=mid+1;
//     for(int i=low;i<=mid;i++){
//         while(right<=high && nums[i]> (long long)2*nums[right]){
//             right++;
//         }
//         count=count+(right - (mid+1));
//     }
// }
// void mergeSort(vector<int>& arr, int low, int high) {
//     if (low >= high) return;
//     int mid = (low + high) / 2;
//     mergeSort(arr, low, mid);      // left half
//     mergeSort(arr, mid + 1, high); // right half
//     countPairs(arr, low, mid, high);
//     merge(arr, low, mid, high);    // merging sorted halves
// }

// int reversePairsOptimal(vector<int>& nums) {
//     mergeSort(nums,0,nums.size()-1);
//     return count;
// }


//without global variable
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr
    // storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) {
        // left is smaller
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else {
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
}
int countPairs(vector<int> &nums,int low, int mid,int high){
    int count=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && nums[i]> (long long)2*nums[right]){
            right++;
        }
        count=count+(right - (mid+1));
    }
    return count;
}
int mergeSort(vector<int>& arr, int low, int high) {
    int count=0;
    if (low >= high) return count;
    int mid = (low + high) / 2;
    count+=mergeSort(arr, low, mid);      // left half
    count +=mergeSort(arr, mid + 1, high); // right half
    count +=countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);    // merging sorted halves
    return count;
}
int reversePairsOptimal(vector<int>& nums) {
    int count=0;
    count=mergeSort(nums,0,nums.size()-1);
    return count;
}

int main(){
    vector<int> arr={5,3,2,4,1};
    cout<<reversePairsBrute(arr)<<endl;

    cout<<reversePairsOptimal(arr)<<endl;
    return 0;
}