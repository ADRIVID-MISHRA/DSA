#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

bool isPossible(vector<int> books,int student,int maxPages){
    int pages=0,countStudent=1;
    for(int i=0;i<books.size();i++){
        if(pages+books[i]>maxPages){
            pages=books[i];
            countStudent++;
        }else{
            pages+=books[i];
        }
        if(countStudent>student) return false;
    }
    // return student==countStudent; //LS only
    return student>=countStudent; //LS+BS
}

int bookAllocationLS(vector<int> books,int student){
    int maxi=*max_element(books.begin(),books.end());
    if(student>books.size()) return -1;
    int sum=accumulate(books.begin(),books.end(),0);
    for(int i=maxi;i<=sum;i++){
        if(isPossible(books,student,i)) return i;
    }
    return -1;
}

int bookAllocationBS(vector<int> books,int student){
    if(student>books.size()) return -1;
    int low=*max_element(books.begin(),books.end());
    int high=accumulate(books.begin(),books.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(books,student,mid)) high=mid-1;
        else low=mid+1;
    }
    return low;
}
int main(){
    vector<int> arr={25,46,28,49,24};
    int students=4;
    cout<<bookAllocationLS(arr,students)<<endl;
    cout<<bookAllocationBS(arr,students);
    return 0;
}