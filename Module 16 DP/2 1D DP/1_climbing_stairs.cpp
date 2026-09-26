//LC 70
#include<iostream>

using namespace std;

int climbStairs(int n) {
    //n+1 th fibonacci
    // int prev2=0;  
    // int prev1=1;
    // for(int i=2;i<=n+1;i++){
    //     int curr=prev1+prev2;
    //     prev2=prev1;
    //     prev1=curr;
    // }
    // return prev1;

    //change starting parameters prev1 and prev2
    int prev2=1;
    int prev1=1;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    int n=4;

    cout<<climbStairs(n);
}