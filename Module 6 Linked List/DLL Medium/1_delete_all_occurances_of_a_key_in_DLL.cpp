#include<iostream>
#include<vector>

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

class Sollution{
public:
    Node *deleteAllKey(Node *head,int key){
        Node *temp=head;
        while(temp!=nullptr){
            if(temp->data==key){
                Node *next=temp->next;
                Node *prev=temp->prev;
                
                if(prev!=nullptr){    //not head
                    prev->next=next;
                }else{       //head
                    head=next;
                }
                if(next!=nullptr){     //not tail
                    next->prev=prev;
                }
                delete temp;
                temp=next;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};

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
    vector<int> nums={10,10,10,34,35,10,34,10,10,10,10,45,34,12,10,6,5,7,6,10,43,10,10};
    int key=10;
    Node *head=arrayToDLL(nums);
    printDLL(head);
    cout<<endl;

    Sollution obj;
    head=obj.deleteAllKey(head,key);
    printDLL(head);

    return 0;
}