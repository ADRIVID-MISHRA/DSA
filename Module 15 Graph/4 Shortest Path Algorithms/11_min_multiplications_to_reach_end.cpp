#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    int MOD=100000;
public:
    int minMul(int start,int end,vector<int> &arr){
        if(start==end) return 0;

        vector<int> dist(100000,INT_MAX);  //nodes 0 to 99999
        queue<pair<int,int>> q; //steps,node(newStart)

        dist[start]=0;
        q.push({0,start});

        while(!q.empty()){
            int d=q.front().first;
            int node=q.front().second;
            q.pop();

            for(int it:arr){
                int newNode=(node*it)%MOD;
                if(newNode==end) return d+1;
                if(dist[newNode]==INT_MAX){  //not yet visited and not in the queue 
                    dist[newNode]=d+1;             //can also write (d+1 < dist[newNode])
                    q.push({d+1,newNode});
                }
            }
        }
        return -1;
    }
};

int main(){
    int start=3,end=84;
    vector<int> arr={2,5,7};
    
    Solution obj;
    cout<<obj.minMul(start,end,arr);

    return 0;
}