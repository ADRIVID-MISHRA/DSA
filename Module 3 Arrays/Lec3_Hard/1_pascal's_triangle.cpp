#include<iostream>
#include<vector>

using namespace std;

long long nCr(int n,int r){
    long long result=1;
    for(int i=0;i<r;i++){
        result=result*(n-i);
        result=result/(i+1);
    }
    return result;
}

vector<vector<int>> pascal_tringle_brute(int numRows) {
    vector<vector<int>> arr;
    for(int i=1;i<=numRows;i++){
        vector<int> temp;
        for(int j=1;j<=i;j++){
            temp.push_back(nCr(i-1,j-1));
        }
        arr.emplace_back(temp);
    }
    return arr;
}

vector<int> generate_rows(int n){
    vector<int> ans;
    int res=1;
    ans.push_back(res);
    for(int i=1;i<n;i++){
        res=res*(n-i)/i;
        ans.push_back(res);
    }
    return ans;
}

vector<vector<int>> pascal_trianglr_optimal(int n){
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        ans.emplace_back(generate_rows(i));
    }
    return ans;
}

int main(){
    int row=5,column=4;
    cout<<"Element at that row and column: "<<nCr(row-1,column-1);   

    int n=6;
    cout<<endl<<"n th row brute: ";
    for(int c=1;c<=n;c++){
        cout<<nCr(n-1,c-1)<<" ";
    }

    cout<<endl<<"n th row optimal: ";
    vector<int> arr=generate_rows(n);
    for(auto i:arr){
        cout<<i<<" ";
    }

    // n=6;
    // int res=1;
    // cout<<res<<" ";
    // for(int i=1;i<n;i++){
    //     res=res*(n-i)/i;
    //     cout<<res<<" ";
    // }

    cout<<endl<<endl;
    vector<vector<int>> pas= pascal_tringle_brute(6);
    for(auto i:pas){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    pas=pascal_trianglr_optimal(6);
    for(auto i:pas){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}