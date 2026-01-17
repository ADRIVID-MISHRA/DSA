#include<iostream>
#include<vector>

using namespace std;

int buy_sell_stocks(vector<int> &prices){
    int mini=prices[0],profit=0,maxProfit=0;
    for(int i=1;i<prices.size();i++){
        profit=prices[i]-mini;
        maxProfit=max(maxProfit,profit);
        mini=min(prices[i],mini);
    }
    return maxProfit;
}

int main(){
    vector<int> arr={3,4,5,2,8,7,9,2,1,4,9};
    cout<<buy_sell_stocks(arr);
    return 0;
}
