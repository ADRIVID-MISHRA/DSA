#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;
                int largest=INT_MIN;
                int smallest=INT_MAX;
                for(auto it:mpp){
                    largest=max(largest,it.second);
                    smallest=min(smallest,it.second);
                }
                count+=largest-smallest;
            }
        }
        return count;
    }
};

int main(){
    string s="fjnbqrzhwnkvvnlnoisixgkeujkcwtufnxpwumvokdkuwpzhzqwjtbnpjuxflgaccgkeryaapjokfpaygmdjbfuswtdzdpnnivvzrfurhjiajjsrgyhremlyptqejdyoiwhxjxmkeucllmazclxfpikywdphdjbhoogypiyidotlqdfwymmypektnsiidhwtfyuwvxtnuqvlwuoqxdsfbogoluuinlczwejngcedfxofwnenxshosyitsqxcafbpvvhwimwvuqddrdhepiiynrxhmzomlmmgsdjavsehdewtbwtnhlfprhnw";
    Solution obj;
    cout<<obj.beautySum(s);
    return 0;
}