#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void floydWarshall(vector<vector<int>> &cost){   //pass the adj matrix
        int n=cost.size(); //adj matrix are always square matrix

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][via]!=INT_MAX && cost[via][j]!=INT_MAX){
                        cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                    }
                }
            }
        }

        //negetive cycle check
        for(int i=0;i<n;i++){
            if(cost[i][i]!=0) cost={{-1}};
        }
    }
};

int main(){
    int inf=1e9;
    vector<vector<int>> cost={
        {0,2,inf,inf},
        {1,0,3,inf},
        {inf,inf,0,inf},
        {3,5,4,0}
    };

    Solution obj;
    obj.floydWarshall(cost);

    for(auto it:cost){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}