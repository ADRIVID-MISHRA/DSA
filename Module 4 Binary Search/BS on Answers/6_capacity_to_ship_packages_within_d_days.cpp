#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

bool isPossible(vector<int> &weights, int days, int capacity){
    int load=0,countDays=1;  //start from day 1
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>capacity){ 
            countDays++;    //ship next day if not possible today
            load=weights[i];
        }else{
            load+=weights[i];   //add package to todays ship
        }
        if(countDays>days) return false;  //avoid un-necessary countings
    }
    return countDays<=days;
}

int shipWithinDaysBS(vector<int>& weights, int days) {
    int low=*max_element(weights.begin(),weights.end());  //max element in array
    int high=accumulate(weights.begin(),weights.end(),0); //sum of all elements in array
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(weights,days,mid)) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int shipWithinDaysLS(vector<int>& weights, int days) {
    int maxi=*max_element(weights.begin(),weights.end());  //max element in array
    int sum=accumulate(weights.begin(),weights.end(),0); //sum of all elements in array
    for(int i=maxi;i<sum;i++){
        if(isPossible(weights,days,i)) return i;
    }
    return -1;
}

int main(){
    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    cout<<shipWithinDaysLS(weights,days)<<endl;
    cout<<shipWithinDaysBS(weights,days);
    return 0;
}