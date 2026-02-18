#include<iostream>
#include<cmath>

using namespace std;

int nthRootLS(int target,int root){
    for(int i=1;i<=target;i++){
        int power=pow(i,root);
        if(power==target) return i;
        else if(power>target) return -1;
    }
    return -1;
}

int nthRootBS(int target,int root){
    int low=1;
    int high=target;
    while(low<=high){
        int mid=(low+high)/2;
        int power=pow(mid,root);
        if(power==target){
            return mid;
        }
        else if(power>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int target=27;
    int root=3;
    cout<<nthRootLS(target,root)<<endl;
    cout<<nthRootBS(target,root);
    return 0;
}