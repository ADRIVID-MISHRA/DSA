#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    string findOrder(vector<string> &dict,int N,int K){
        vector<vector<int>> adj(K);    //nodes from 0 to K-1
        vector<int> indegree(K);
        for(int i=0;i<N-1;i++){
            string s1=dict[i];    //Get the pairs
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            bool flag=false;
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');   //edge from s1[j]->s2[j]
                    indegree[s2[ptr]-'a']++;
                    flag=true;
                    break;      //only need the first inequality between both the strings
                }
            }
            if(!flag && s1.size()>s2.size()) return ""; //incorrect dictionary
        }

        //Run topo sort
        queue<int> q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0) q.push(i);
        }

        string order;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(static_cast<char>('a'+node));

            for(int neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        if(order.size()==K) return order;   //Cyclic dependency check
        return "";
    }
};

int main(){
    int N=5,K=4;
    vector<string> dict={"baa","abcd","abca","cab","cad"};
    Solution obj;
    string ans=obj.findOrder(dict,N,K);
    cout<<ans;
    return 0;
}