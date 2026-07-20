#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
public:
    //constructor
    DisjointSet(int n){   //supports both 1-based indexing(1 to n nodes) and 0-based indexing(0 to n nodes)
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){   //finds ultimate parents
        if(node==parent[node]) return node;

        return parent[node]=findParent(parent[node]);  //path compression
    }

    void unionByRank(int u,int v){
        int pu=findParent(u);  //find the ultimate parents
        int pv=findParent(v);

        if(pu==pv) return;   //already in the same component

        if(rank[pv]<rank[pu]) parent[pv]=pu;
        else if(rank[pu]<rank[pv]) parent[pu]=pv;
        else{   //connect in any of the ways
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size(); //nodes from 0 to n-1
        DisjointSet ds(n-1);
        unordered_map<string,int> mpp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mpp.find(email)!=mpp.end()){  //already existing in the map
                    ds.unionByRank(mpp[email],i);
                }else{
                    mpp[email]=i;
                }
            }
        }

        vector<vector<string>> mergedMails(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=ds.findParent(it.second);  //get the ultimate parent of the node
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<mergedMails.size();i++){
            if(mergedMails[i].size()==0) continue;
            
            sort(mergedMails[i].begin(),mergedMails[i].end());  //emails should be sorted in answer
            vector<string> temp;
            temp.push_back(accounts[i][0]);  //push the name
            for(auto it:mergedMails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


int main(){
    int n=5; // Number of accounts

    // {Name, Email1, Email2, ...}
    vector<vector<string>> accounts={
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"},
        {"Mary","mary@mail.com","mary_new@mail.com"}
    };

    Solution obj;
    vector<vector<string>> ans=obj.accountsMerge(accounts);

    cout<<"Merged Accounts:"<<endl;

    for(auto account:ans){
        for(auto str:account){
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}