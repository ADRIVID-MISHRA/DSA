#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int coun=0;

void fun(){
    if(coun>=10){
        return;
    }
    cout<<"1 ";
    coun++;
    fun();
}

void print_name_n_times(int i,int n){
    if(i>n){
        return;
    }
    cout<<"adri"<<endl;
    print_name_n_times(i+1,n);
}

void print_from_1_to_n(int i,int n){
    if(i>n) return;
    cout<<i<<" ";
    print_from_1_to_n(i+1,n);
}

void print_from_n_to_1(int i,int n){
    if(n<i){
        return;
    }
    cout<<n<<" ";
    print_from_n_to_1(i,n-1);
}

void print_from_1_to_n_backtracking(int i,int n){
    if(i<1) return;
    print_from_1_to_n_backtracking(i-1,n);
    cout<<i<<" ";
}

void print_from_n_to_1_backtracking(int i,int n){
    if(i>n){
        return;
    }
    print_from_n_to_1_backtracking(i+1,n);
    cout<<i<<" ";
} 

void sum_of_first_n_numbers_parametarized(int i,int sum){
    if(i<1){
        cout<<"Sum: "<<sum<<endl;
        return;
    }
    sum_of_first_n_numbers_parametarized(i-1,sum+i);
}

int sum_of_first_n_numbers_functional(int n){
    if(n==1) return 1;
    else{
        return n+sum_of_first_n_numbers_functional(n-1);
    }
}

int factorial_functional(int n){
    if(n==0)
        return 1;
    return n*factorial_functional(n-1);
}

void reverse_array_1(int arr[],int f,int l){
    if(f>=l)return;
    swap(arr[f],arr[l]);

    reverse_array_1(arr,f+1,l-1);
}

void reverse_array_2(int arr[],int f,int n){
    if(f>=n/2) return;

    swap(arr[f],arr[n-f-1]);
    reverse_array_2(arr,f+1,n);
}

bool is_palindrome(string &s,int i,int n){
    if(i>=n/2){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return is_palindrome(s,i+1,n);

}
 
int fibonacci(int n){
    if(n<=1) return n;

    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    fun();
    cout<<endl;
    int n=5;
    print_name_n_times(1,n);
    cout<<endl;
    print_from_1_to_n(1,n);
    cout<<endl;
    print_from_n_to_1(1,n);
    cout<<endl;
    
    print_from_1_to_n_backtracking(n,n);
    cout<<endl;
    print_from_n_to_1_backtracking(1,n);
    cout<<endl;

    sum_of_first_n_numbers_parametarized(n,0);

    cout<<sum_of_first_n_numbers_functional(n)<<endl;

    cout<<factorial_functional(n);
    cout<<endl;

    int arr[]={8,2,4,3,5};
    reverse_array_1(arr,0,size(arr)-1);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    int arr2[]={1,2,9,3,4};
    reverse_array_2(arr2,0,size(arr2));
    for(auto i:arr2){
        cout<<i<<" ";
    }
    
    cout<<endl;
    string s="MADAM";
    cout<<boolalpha<<is_palindrome(s,0,s.size())<<endl;
    
    cout<<fibonacci(6)<<endl;
    for(int i=0;i<100;i++){
        cout<<fibonacci(i)<<" ";
    }
    return 0;
}