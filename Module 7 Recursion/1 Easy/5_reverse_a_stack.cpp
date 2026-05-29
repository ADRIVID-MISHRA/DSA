#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &st,int topElement){
    if(st.empty()){
        st.push(topElement);
        return;
    }

    int top=st.top();
    st.pop();
    insertAtBottom(st,topElement);
    st.push(top);
}

void reverseStack(stack<int> &st){
    if(st.empty()) return;

    int topElement=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,topElement);
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    stack<int> st;

    st.push(7);
    st.push(2);
    st.push(43);
    st.push(21);
    st.push(18);

    printStack(st);
    cout<<endl;

    reverseStack(st);

    printStack(st);

    
    return 0;
}