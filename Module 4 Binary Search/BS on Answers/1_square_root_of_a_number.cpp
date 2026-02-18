#include<iostream>

using namespace std;

int squareRootLS(int target){
    int root=1;
    for(int i=1;i<=target;i++){    //<= as target may 1
        if(i*i<=target){
            root=i;
        }else{
            break;
        }
    }
    return root;
}

int squareRootBS(int target){
    int low=1;
    int high=target;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid<=target){   //trim ledt
            low=mid+1;
        }else{      //trim right
            high=mid-1;
        }
    }
    return high;
}

int main(){
    int target=28;
    cout<<squareRootLS(target)<<endl;
    cout<<squareRootBS(target);
    return 0;
}