#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int val,Node *nxt=nullptr){
        data=val;
        next=nxt;
    }
};

Node *convertArrToLinkedList(vector<int> &arr){
    Node *head=new Node(arr[0]);
    Node *mover=head;

    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void printLL(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int lengthOfLL(Node *head){
    Node *temp=head;
    int count=0;
    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }
    return count;
}

bool searchLL(Node *head,int val){
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data == val) return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    vector<int> arr={23,44,22,12,45};
    Node *head=convertArrToLinkedList(arr);
    cout<<head->data<<"  "<<head->next->data<<endl;

    printLL(head); 
    cout<<endl<<lengthOfLL(head)<<endl;
    cout<<boolalpha<<searchLL(head,4);
    return 0;
}