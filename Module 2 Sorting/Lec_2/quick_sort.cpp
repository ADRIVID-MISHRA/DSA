// #include<iostream>
// #include<algorithm>

// using namespace std;

// int partition(int arr[], int low, int high){
//     int i=low;
//     int j=high;
//     int pivot=arr[low];
//     while(i<j){
//         while(pivot>=arr[i] && i<=high-1){
//             i++;
//         }
//         while(pivot<arr[j] && j>=low+1){
//             j--;
//         }
//         if(i<j) swap(arr[j],arr[i]);
//     }
//     swap(arr[low],arr[j]);
//     return j;
// }

// void quickSort(int arr[],int low, int high){
//     if(low>=high) return;

//     int pivot= partition(arr, low, high);
//     quickSort(arr, low, pivot-1);
//     quickSort(arr,pivot+1,high);

// }

// int main(){
//     int arr[]={9, 4, 7, 6, 3, 1, 5};
//     int n=size(arr);

//     quickSort(arr,0,n-1);

//     for(auto it:arr){
//         cout<<it<<" ";
//     }
//     return 0;
// }

// in Descending order- quick sort

#include<iostream>
#include<algorithm>

using namespace std;

int partition(int arr[], int low, int high){
    int i=low;
    int j=high;
    int pivot=arr[low];
    while(i<j){
        while(pivot<=arr[i] && i<=high-1){
            i++;
        }
        while(pivot>arr[j] && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[j],arr[i]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[],int low, int high){
    if(low>=high) return;

    int pivot= partition(arr, low, high);
    quickSort(arr, low, pivot-1);
    quickSort(arr,pivot+1,high);

}

int main(){
    int arr[]={9, 4, 7, 6, 3, 1, 5};
    int n=size(arr);

    quickSort(arr,0,n-1);

    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}