#include<iostream>
#include<vector>
#include<limits>

using namespace std;
int mini=numeric_limits<int>::min()+rand();

void setrow(vector<vector<int>> &matrix, int i){
    for(int j=0;j<matrix[0].size();j++){
        if(matrix[i][j]!=0) matrix[i][j]=mini;
    }
}
void setcoloumn(vector<vector<int>> &matrix, int j){
    for(int i=0;i<matrix.size();i++){
        if(matrix[i][j]!=0) matrix[i][j]=mini;
    }
}

vector<vector<int>> set_zero_brute(vector<vector<int>> matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                setrow(matrix,i);
                setcoloumn(matrix,j);
            }
        }
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==mini){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}

void print_matrix(vector<vector<int>> nums){
    for(auto it:nums){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> set_zero_better(vector<vector<int>> nums){
    int n=nums.size();
    int m=nums[0].size();             // n x m matrix
    vector<int> row(n,0);
    vector<int> coloumn(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==0){
                row[i]=1;
                coloumn[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || coloumn[j]==1){
                nums[i][j]=0;
            }
        }
    }
    return nums;
}

vector<vector<int>> set_zero_optimal(vector<vector<int>> nums){
    int n=nums.size();
    int m=nums[0].size(); 
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==0){
                // mark the i-th row
                nums[i][0]=0;
                // mark the j-th coloumn
                if(j!=0){
                    nums[0][j]=0;
                }else{
                    col0=0;
                }
            }
        }
    }
    //update inner first
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(nums[i][0]==0 || nums[0][j]==0){
                nums[i][j]=0;
            }
        }
    }
    //mark the row zero if needed
    if(nums[0][0]==0){
        for(int j=0;j<m;j++){
            nums[0][j]=0;
        }
    }
    //mark the coloumn zero if needed
    if(col0==0){
        for(int i=0;i<n;i++){
            nums[i][0]=0;
        }
    }
    return nums;
}

int main(){
    vector<vector<int>> arr={
        {23,98,12,34},
        {98,12,34,55},
        {34,0,23,74}
    };
    vector<vector<int>> ans1= set_zero_brute(arr);
    print_matrix(ans1);
    cout<<endl;
    vector<vector<int>> ans2= set_zero_better(arr);
    print_matrix(ans2);
    cout<<endl;
    vector<vector<int>> ans3= set_zero_optimal(arr);
    print_matrix(ans3);

    return 0;
}