#include<iostream>
#include<vector>

using namespace std;

double kthElementOfSortedArraysBrute(vector<int>& nums1, vector<int>& nums2,int k) {
    vector<int> arr;
    // arr.insert(arr.end(),nums1.begin(),nums1.end());
    // arr.insert(arr.end(),nums2.begin(),nums2.end());
    // sort(arr.begin(),arr.end());
    int i=0,j=0;
    int n1=nums1.size(),n2=nums2.size();
    while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            arr.push_back(nums1[i++]);
        }else{
            arr.push_back(nums2[j++]);
        }
    }
    while(i<n1){
        arr.push_back(nums1[i++]);
    }
    while(j<n2){
        arr.push_back(nums2[j++]);
    }

    return arr[k-1];
}

double kthElementOfSortedArraysBetter(vector<int>& nums1, vector<int>& nums2,int k) {
    int i=0,j=0;
    int n1=nums1.size(),n2=nums2.size();
    int count=0;
    int kthIndex=k-1;
    while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            if(count==kthIndex) return nums1[i]; 
            count++;
            i++;
        }else{
            if(count==kthIndex) return nums2[j];
            count++;
            j++;    
        }
    }
    while(i<n1){
        if(count==kthIndex) return nums1[i]; 
        count++;
        i++;
    }
    while(j<n2){
        if(count==kthIndex) return nums2[j];
        count++;
        j++;     
    }
    return -1;
}

double kthElementOfSortedArraysOptimal(vector<int>& nums1, vector<int>& nums2,int k) {
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    if(n1>n2) return kthElementOfSortedArraysOptimal(nums2,nums1,k);   //RUN BS only on the smaller array
    int partition=k;
    int low=max(k-n2,0),high=min(k,n1);
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=partition-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];
        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];

        if(l1<=r2 && l2<=r1){   //found answer
            return max(l1,l2);
        }
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;   // l2>r1
    }
    return -1;
}

int main(){
    vector<int> nums1={1,2,5,8,13,45};
    vector<int> nums2={3,56,455,788};
    int k=4;
    cout<<kthElementOfSortedArraysBrute(nums1,nums2,k)<<endl;
    cout<<kthElementOfSortedArraysBetter(nums1,nums2,k)<<endl;
    cout<<kthElementOfSortedArraysOptimal(nums1,nums2,k);

    return 0;
}