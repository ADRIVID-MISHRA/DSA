#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool bouquetPossible(vector<int> &bloomDay,int currentDay,int m,int k){
    int adjacent=0,boukets=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=currentDay){
            adjacent++;
        }else{
            boukets+=adjacent/k;
            adjacent=0;
        }
    }
    boukets+=adjacent/k;
    if(boukets>=m) return true;
    else return false; 
}

int minDaysBS(vector<int>& bloomDay, int m, int k) {
    if((long long)m*k>bloomDay.size()) return -1;
    int high=*max_element(bloomDay.begin(),bloomDay.end());
    int low=*min_element(bloomDay.begin(),bloomDay.end());
    while(low<=high){
        int mid=(low+high)/2;
        if(bouquetPossible(bloomDay,mid,m,k)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int minDaysLS(vector<int>& bloomDay, int m, int k) {
    if((long long)m*k>bloomDay.size()) return -1;
    int max=*max_element(bloomDay.begin(),bloomDay.end());
    int min=*min_element(bloomDay.begin(),bloomDay.end());
    for(int i=min;i<=max;i++){
        if(bouquetPossible(bloomDay,i,m,k)) return i;
    }
    return -1;
}

int main(){
    vector<int> bloomDay={1,10,3,10,2};
    int m=3;
    int k=1;
    cout<<minDaysLS(bloomDay,m,k)<<endl;
    cout<<minDaysBS(bloomDay,m,k);
    return 0;
}