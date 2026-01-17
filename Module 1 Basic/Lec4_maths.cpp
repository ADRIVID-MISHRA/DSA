#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int count_digits(int n){
    size_t count=0;
    // while(n!=0){
    //     n/=10;
    //     ++count;
    // }
    count= int(log10(n)+1);
    return count;
}

bool armstrong(int n){
    int di=count_digits(n);
    int ld,sum=0,k=n;
    while(n!=0){
        ld=n%10;
        sum=sum+pow(ld,di);
        n/=10;
    }
    if(sum==k){
        return true;
    }else{
        return false;
    }
}

void all_divisors(int n){
    // for(int i=1;i<=n;i++){
    //     if(n%i==0){
    //         cout<<i<<" ";
    //     }
    // }
    vector<int> li;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            // cout<<i<<" ";
            li.emplace_back(i);
            if(n/i!=i){
                // cout<<(n/i)<<" ";
                li.emplace_back(n/i);
            }
        }
    }
    sort(li.begin(),li.end());
    for(auto it :li){
        cout<<it<<" ";
    }
}

string is_prime(int n){
    int c=0;
    // for(int i=1;i<=n;i++){
    //     if(n%i==0){
    //         c++;
    //     }
    // }
    for(int i=1; i*i<=n;i++){
        if(n%i==0){
            c++;
            if(n/i!=i)c++;
        }
    }
    if(c==2){
        return "Yes";
    }else{
        return "NO";
    }
}

void gcd(int n1,int n2){
    for(int i=min(n1,n2);i>=1;i--){
        if(n1%i==0 && n2%i==0){
            cout<<i;
            break;
        }
    }
}

void gcd_equilateral(int a,int b){
    // if(a==0){
    //     cout<<b;
    // }
    // if(b==0){
    //     cout<<a;
    // }recursive method

    while(a!=0 && b!=0){
        if(a>=b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a==0){
        cout<<b;
    }else{
        cout<<a;
    }
    


    // static int gcd(int a, int b) {
    //     while (b != 0) {
    //         int temp = b;
    //         b = a % b;
    //         a = temp;
    //     }
    //     return a;  // When b becomes 0, a is the GCD
    // }
}

int main(){
    int n=11;

    cout<<"Number of digits: "<<count_digits(n)<<endl;
    cout<<"reverse of num in leetcode 7"<<endl;
    cout<<"palindrome in leetcode 9"<<endl;
    cout<<"Armstrong number: "<<armstrong(n)<<endl;
    cout<<"All dividors of number: ";
    all_divisors(n);
    cout<<endl;
    cout<<"Is it prime number: "<<is_prime(n)<<endl;
    gcd(20,40);
    cout<<endl;
    gcd_equilateral(12,9);

    return 0;
}