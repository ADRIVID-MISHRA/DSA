//LC 126
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return {};
        st.erase(beginWord);

        queue<vector<string>> q;  //word sequence
        q.push({beginWord});
        bool found=false;

        while(!q.empty()){
            int size=q.size();
            vector<string> toDelete;
            for(int i=0;i<size;i++){
                vector<string> sequence=q.front();
                q.pop();
                string word=sequence.back();

                for(int i=0;i<word.size();i++){
                    char original=word[i];
                    for(char ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(st.find(word)!=st.end()){
                            if(word==endWord) found=true;
                            sequence.push_back(word);
                            q.push(sequence);
                            sequence.pop_back();
                            toDelete.push_back(word);
                        }
                    }
                    word[i]=original;   //restore the original word
                }
            }
            for(auto it:toDelete){
                st.erase(it);
            }
            if(found) break;
        }
        vector<vector<string>> ans;
        while(!q.empty()){
            if(q.front().back()==endWord) ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};

//Leetcode more optimal solution
class LeetCode{
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string startWord;
    void dfs(string word,vector<string> &seq){
        if(word==startWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mpp[word];
        int wordSize=word.size();
        for(int i=0;i<wordSize;i++){
                char original=word[i];                
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(mpp.find(word)!=mpp.end() && mpp[word]==steps-1){
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();;
                    }
                }
                word[i]=original;
            }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return {};
        st.erase(beginWord);

        startWord=beginWord;
        queue<string> q;
        q.push(beginWord);
        mpp[beginWord]=1;

        int wordSize=beginWord.size();
        bool found=false;
        while(!q.empty()){
            string word=q.front();
            int steps=mpp[word];
            q.pop();

            for(int i=0;i<wordSize;i++){
                char original=word[i];                
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        mpp[word]=steps+1;
                        st.erase(word);
                        if(word==endWord) found=true;
                    }
                }
                word[i]=original;
            }
            if(found) break;
        }

        if(mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};

int main(){
    string beginWord="hit";
    string endWord="cog";
    vector<string> wordList ={"hot","dot","dog","lot","log","cog"};

    Solution obj1;
    vector<vector<string>> result1=obj1.findLadders(beginWord,endWord,wordList);
    for(auto it:result1){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    LeetCode obj2;
    vector<vector<string>> result2=obj2.findLadders(beginWord,endWord,wordList);
    for(auto it:result2){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}