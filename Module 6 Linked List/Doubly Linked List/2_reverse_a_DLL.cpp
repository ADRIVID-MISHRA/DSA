#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data,Node *next=nullptr,Node *prev=nullptr){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};
//reversal functions
Node *reverseDataUsingStack(Node *head){
    Node *temp=head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=nullptr){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

Node *reverseDLL(Node *head){
    if(head==nullptr || head->next==nullptr) return head;  //single element or no element
    Node *currentNode=head;
    Node *prevNode=nullptr; //previous to unreversed DLL

    while(currentNode!=nullptr){
        prevNode=currentNode->prev;
        currentNode->prev=currentNode->next;
        currentNode->next=prevNode;
        
        currentNode=currentNode->prev;
    }
    return prevNode->prev;
}

//utility functions
Node *arrayToDLL(vector<int> &nums){
    Node *head=new Node(nums[0]);
    Node *previous=head;
    for(int i=1;i<nums.size();i++){
        Node *temp=new Node(nums[i],nullptr,previous);
        previous->next=temp;
        previous=temp;
    }
    return head;
}

void printDLL(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    vector<int> nums={34,35,345,325,246};
    Node *head=arrayToDLL(nums);
    printDLL(head);
    cout<<endl;

    head=reverseDataUsingStack(head);
    printDLL(head);
    cout<<endl;

    head=reverseDLL(head);
    printDLL(head);
    cout<<endl;
    return 0;
}