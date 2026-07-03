//LC 127
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        st.erase(beginWord);

        queue<pair<string,int>> q;  //word , sequence length
        q.push({beginWord,1});

        while(!q.empty()){
            string word=q.front().first;
            int dist=q.front().second;
            q.pop();

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        if(word==endWord) return dist+1;
                        q.push({word,dist+1});
                        st.erase(word);
                    }
                }
                word[i]=original;   //restore the original word
            }
        }
        return 0;
    }
};

int main(){
    string beginWord="hit";
    string endWord="cog";
    vector<string> wordList ={"hot","dot","dog","lot","log","cog"};
    Solution obj;
    cout<<obj.ladderLength(beginWord,endWord,wordList);
    return 0;
}