#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//LS APPROACH BELOW
long long countHours(vector<int> &piles,int k){
    long long count=0;
    for(int i=0;i<piles.size();i++){
        count+=ceil((double)piles[i]/k);
    }
    return count;
}
    
int minEatingSpeedLS(vector<int>& piles, int h) {
    int maxi=*max_element(piles.begin(),piles.end());
    for(int i=1;i<=maxi;i++){
        long long hours=countHours(piles,i);
        if(hours<=h){
            return i;
        }
    }
    return -1;
}

//BS APPROACH BELOW
bool isPossible(vector<int> &piles,int k,int h){
    int count=0;
    for(int i=0;i<piles.size();i++){
        count+=ceil((double)piles[i]/k);
        if(count>h) return false;
    }
    return true;
}

int minEatingSpeedBS(vector<int>& piles, int h) {
    int maxi=*max_element(piles.begin(),piles.end());
    int low=1,high=maxi;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(piles,mid,h)) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    vector<int> piles = {3,6,7,11};
    int h=8;
    cout<<minEatingSpeedLS(piles,h)<<endl;
    cout<<minEatingSpeedBS(piles,h);
    return 0;
}