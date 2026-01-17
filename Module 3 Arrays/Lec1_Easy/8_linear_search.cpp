#include<iostream>
#include<vector>

using namespace std;

int index_of_num(vector<int> arr,int num){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}

vector<int> all_index_of_num(vector<int> arr,int num){
    vector<int> temp;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num){
            temp.push_back(i);
        }
    }
    return temp;
}


int main(){
    vector<int> arr={223,3,0,98,35,0,0,395,0,355,35,0};
    int num;
    cout<<"Enter search: ";
    cin>>num;
    int x=index_of_num(arr,num);
    cout<<x<<endl;
    vector<int> y=all_index_of_num(arr,num);
    for(auto it:y){
        cout<<it<<" ";
    }
    return 0;
}