//LC 2220
#include<iostream>

using namespace std;

int minBitFlips(int start, int goal) {
    int ans=start^goal;
    // return __builtin_popcount(ans);

    int count=0;
    while(ans!=0){
        count++;
        ans=ans&(ans-1);
    }
    return count;
}

int main(){
    cout<<minBitFlips(10,7);
    return 0;
}