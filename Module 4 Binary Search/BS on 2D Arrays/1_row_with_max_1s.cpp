#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int rowWithMaxOnesBrute(vector<vector<int>> &mat){
    int max=0,maxIndex=-1;   //return -1 if no row has even a single 1
    for(int i=0;i<mat.size();i++){
        int count=0;
        for(int j=0;j<mat[i].size();j++){
            count+=mat[i][j];
        }
        if(count>max){    //not >= as we want lowest index if two rows have max no of 1's
            max=count;
            maxIndex=i;
        }
    }
    return maxIndex;
}

int rowWithMaxOnesBS(vector<vector<int>> &mat){
    int maxCount=0,maxIndex=-1;
    for(int i=0;i<mat.size();i++){
        int count=mat[i].size()-(lower_bound(mat[i].begin(),mat[i].end(),1) - mat[i].begin()); 
        if(count>maxCount){   
            maxCount=count;
            maxIndex=i;
        }
    }
    return maxIndex;
}

int main(){
    vector<vector<int>> mat={
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1}
    };
    cout<<rowWithMaxOnesBrute(mat)<<endl;
    cout<<rowWithMaxOnesBS(mat);
    return 0;
}