#include<iostream>
#include<algorithm>
//#include<bits/stdc++.h>

using namespace std;

void pattern1(int n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<n;j++){
            cout<<" * ";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<i+1;j++){
            cout<<" * ";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(size_t i{};i<n;i++){
        for(size_t j{1};j<=i+1;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<i+1;j++){
            cout<<i+1;
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<n-i;j++){
            cout<<" * ";
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<n-i;j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<n-i-1;j++){
            cout<<" ";
        }
        for(size_t j{};j<(2*i+1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern8(int n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<i;j++){
            cout<<" ";
        }
        for(size_t j{};j<(2*(n-i)-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern9(int n){
    pattern7(n);
    pattern8(n);
}

void pattern10(int n){
    for(size_t i{};i<(2*n-1);i++){
        if(i<n){
            for(size_t j{};j<=i;j++){
                cout<<" * ";
            }
        }else{
            for(size_t j{};j<2*n-i-1;j++){
                cout<<" * ";
            }
        }
        cout<<endl;
    }
}

void pattern11(int n){
    bool val=true;
    for(size_t i{};i<n;i++){
        if(i%2==0){
            val=false;
        }else{
            val=true;
        }
        for(size_t j{};j<=i;j++){
            cout<<val;
            val=!val;
        }
        cout<<endl;
    }
}

void pattern12(int n){
    for(size_t i{};i<n-1;i++){
        size_t j=0;
        for(j;j<=i;j++){
            cout<<j+1;
        }
        for(size_t k{};k<2*(n-2)-2*i;k++){
            cout<<" ";
        }
        for(size_t k=j;k>0;k--){
            cout<<k;
        }

        cout<<endl;
    }
}

void pattern13(int n){
    int count=1;
    for(size_t i=0; i<n;i++){
        for(size_t j=0;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

void pattern14(int n){
    char prin ='A';
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<=i;j++){
            cout<<static_cast<char>(prin+j);
        }
        cout<<"\n";
    }
}

void pattern15(int n){
    for(size_t i{0};i<n;i++){
        for(char ita{'A'}; ita<('A'-i+n);ita++){
            cout<<ita;
        }
        cout<<endl;
    }
}

void pattern16(int n){
    char ch='A';
    for(size_t i{};i<n;i++){
        for(size_t j{};j<=i;j++){
            cout<<static_cast<char>(ch+i);
        }
        cout<<endl;
    }
}

void pattern17(int n){
    
    char ch='A';
    for(size_t i{};i<n;i++){
        for(size_t k{};k<n-1-i;k++){
            cout<<" ";
        }
        size_t j=0;
        for( ;j<=i;j++){
            cout<<static_cast<char>(ch+j);
        }
        char n='A'+j-2;
        for(size_t l{};l<i;l++){
            cout<<static_cast<char>(n-l);
        }
        cout<<endl;
    }
}

// void pattern17(int N)
// {
    
//       // Outer loop for the number of rows.
//       for(int i=0;i<N;i++){
          
//           // for printing the spaces.
//           for(int j=0;j<N-i-1;j++){
//               cout<<" ";
//           }
          
//           // for printing the characters.
//           char ch = 'A';
//           int breakpoint = (2*i+1)/2;
//           for(int j=1;j<=2*i+1;j++){
              
//               cout<<ch;
//               if(j <= breakpoint) ch++;
//               else ch--;
//           }
          
//           // for printing the spaces again after characters.
//           for(int j=0;j<N-i-1;j++){
//               cout<<" ";
//           }
          
//           // As soon as the letters for each iteration are printed, we move to the
//           // next row and give a line break otherwise all letters
//           // would get printed in 1 line.
//           cout<<endl;
          
//       }
// }

void pattern18(int n){
    for(size_t i=0;i<n;i++){
        for(char ch='E'-i;ch<='E';ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}

void pattern19(int n){
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n-i;j++){
            cout<<"*";
        }
        for(size_t j=0;j<2*i;j++){
            cout<<" ";
        }
        for(size_t j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<=i;j++){
            cout<<"*";
        }
        for(size_t j=0;j<2*n-2*(i+1);j++){
            cout<<" ";
        }
        for(size_t j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern20(int n){
    int stars=0;
    int spaces=2*n;
    for(size_t i=0;i<2*n-1;i++){
        if(i>=n){
            spaces+=2;
            stars=stars-1;
            //stars=2*n-i-1;
        }else{
            stars=i+1;
            spaces-=2;
        }

        for(size_t j=0;j<stars;j++){
            cout<<"*";
        }   
        for(size_t j=0; j<spaces;j++){
            cout<<" ";
        }
        for(size_t j=0;j<stars;j++){
            cout<<"*";
        }   
        cout<<endl;

    }
}

void pattern21(int n){
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            if(i==0 || i==(n-1) || j==0 || j==(n-1)){
                cout<<" *";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}

void pattern22(int n){
    int top,bottom,left,right;
    for(size_t i=0;i<2*n-1;i++){
        for(size_t j=0;j<2*n-1;j++){
            top=i;
            bottom=(2*n-2)-i;  //min distances from the side
            left=j;
            right=(2*n-2)-j;
            cout<< n-min(min(top,bottom),min(left,right));
        }
        cout<<endl;
    }
}

void pattern_extra(int n){
    for(int i=0;i<n;i++){
        for(char j='A'+n-1-i;j<='A'+n-1;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
int main(){
    int number;
    cout<<"Enter number: ";
    cin>>number;

    cout<<"--------------------"<<endl<<"pattern 1:"<<endl;
    pattern1(number);
    cout<<"--------------------"<<endl<<"pattern 2:"<<endl;
    pattern2(number);
    cout<<"--------------------"<<endl<<"pattern 3:"<<endl;
    pattern3(number);
    cout<<"--------------------"<<endl<<"pattern 4:"<<endl;
    pattern4(number);
    cout<<"--------------------"<<endl<<"pattern 5:"<<endl;
    pattern5(number);
    cout<<"--------------------"<<endl<<"pattern 6:"<<endl;
    pattern6(number);
    cout<<"--------------------"<<endl<<"pattern 7:"<<endl;
    pattern7(number);
    cout<<"--------------------"<<endl<<"pattern 8:"<<endl;
    pattern8(number);
    cout<<"--------------------"<<endl<<"pattern 9:"<<endl;
    pattern9(number);
    cout<<"--------------------"<<endl<<"pattern 10:"<<endl;
    pattern10(number);
    cout<<"--------------------"<<endl<<"pattern 11:"<<endl;
    pattern11(number);
    cout<<"--------------------"<<endl<<"pattern 12:"<<endl;
    pattern12(number);
    cout<<"--------------------"<<endl<<"pattern 13:"<<endl;
    pattern13(number);
    cout<<"--------------------"<<endl<<"pattern 14:"<<endl;
    pattern14(number);
    cout<<"--------------------"<<endl<<"pattern 15:"<<endl;
    pattern15(number);
    cout<<"--------------------"<<endl<<"pattern 16:"<<endl;
    pattern16(number);
    cout<<"--------------------"<<endl<<"pattern 17:"<<endl;
    pattern17(number);
    cout<<"--------------------"<<endl<<"pattern 18:"<<endl;
    pattern18(number);
    cout<<"--------------------"<<endl<<"pattern 19:"<<endl;
    pattern19(number);
    cout<<"--------------------"<<endl<<"pattern 20:"<<endl;
    pattern20(number);
    cout<<"--------------------"<<endl<<"pattern 21:"<<endl;
    pattern21(number);
    cout<<"--------------------"<<endl<<"pattern 22:"<<endl;
    pattern22(number);
    cout<<"--------------------"<<endl;
    pattern_extra(number);
    return 0;
}