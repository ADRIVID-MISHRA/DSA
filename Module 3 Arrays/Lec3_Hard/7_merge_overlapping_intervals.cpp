#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

vector<vector<int>> merge_brute(vector<vector<int>> intervals){
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<intervals.size();i++){
        int start=intervals[i][0];
        int end=intervals[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<intervals.size();j++){
            if(intervals[j][0]<=end){
                end=max(end,intervals[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

vector<vector<int>> merge_optimal(vector<vector<int>> intervals){
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    for(int i=0;i<intervals.size();i++){
        if(ans.empty() || ans.back()[1]<intervals[i][0]){
            ans.push_back(intervals[i]);
        }else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr={{1,2},{2,4},{2,6},{8,9},{9,11},{15,18},{16,17}};
    vector<vector<int>> ans =merge_brute(arr);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    vector<vector<int>> ans2 =merge_optimal(arr);
    for(auto it:ans2){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}