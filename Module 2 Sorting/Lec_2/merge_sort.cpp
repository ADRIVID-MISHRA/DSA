#include<iostream>

using namespace std;



void merge(int arr[],int low,int mid, int high){
    int temp[20]={0};
    int z=0;
    int i=low;
    int j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[z]=arr[i];
            i++;
            z++;
        }else{
            temp[z]=arr[j];
            j++;
            z++;
        }
    }

    while(i<=mid){
        temp[z]=arr[i];
        z++;
        i++;
    }

    while(j<=high){
        temp[z]=arr[j];
        z++;
        j++;
    }
    for(int x=low;x<=high;x++){
        arr[x]=temp[x-low];
    }
}

void merge_sort(int arr[],int low, int high){
    if(high<=low) return;
    int mid=(high+low)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

int main(){
    int arr[]={39,23,12,7657,45,646,3,34,234};
    int n=size(arr);

    merge_sort(arr,0,n-1);

    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp; // temporary array
//     int left = low;      // starting index of left half of arr
//     int right = mid + 1;   // starting index of right half of arr

//     //storing elements in the temporary array in a sorted manner//

//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
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

// void mergeSort(vector<int> &arr, int low, int high) {
//     if (low >= high) return;
//     int mid = (low + high) / 2 ;
//     mergeSort(arr, low, mid);  // left half
//     mergeSort(arr, mid + 1, high); // right half
//     merge(arr, low, mid, high);  // merging sorted halves
// }

// int main() {

//     vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
//     int n = 7;

//     cout << "Before Sorting Array: " << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " "  ;
//     }
//     cout << endl;
//     mergeSort(arr, 0, n - 1);
//     cout << "After Sorting Array: " << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " "  ;
//     }
//     cout << endl;
//     return 0 ;
// }