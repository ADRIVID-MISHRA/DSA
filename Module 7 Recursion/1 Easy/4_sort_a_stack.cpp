//ONLY do it recursively
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void insertInPosition(stack<int> &st,int topElement){
    if(st.empty() || st.top()<=topElement){
        st.push(topElement);
        return;
    }
    int top=st.top();
    st.pop();
    insertInPosition(st,topElement);
    st.push(top);
}

void sortStack(stack<int> &st){
    if(st.empty()) return;
    int topElement=st.top();
    st.pop();
    sortStack(st);
    insertInPosition(st,topElement);
}

int main(){
    stack<int> st;

    st.push(7);
    st.push(2);
    st.push(43);
    st.push(21);
    st.push(18);

    sortStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}