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
    Node *removeDuplicates(Node *head){
        if(head==nullptr) return head;

        // Node *temp=head->next;
        // while(temp!=nullptr){
        //     Node *next=temp->next;
        //     Node *prev=temp->prev;
        //     if(prev->data==temp->data){
        //         prev->next=next;
        //         if(next!=nullptr) next->prev=prev;
        //         delete temp;
        //     }
        //     temp=next;
        // }
        // return head;

        Node *temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            Node *nextNode=temp->next;
            while(nextNode!=nullptr && nextNode->data==temp->data){  //keep deleting nodes as you go
                Node *del=nextNode;
                nextNode=nextNode->next;
                delete del;
            }
            temp->next=nextNode;   //temp is the last distinct element and nextNode is the new distinct element
            if(nextNode!=nullptr) nextNode->prev=temp;    //change links
            temp=temp->next;   
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
    vector<int> nums={1,1,1,1,1,1,1,3,4,5,5,5,5,5,5,6,6,7,8,9,9};
    Node *head=arrayToDLL(nums);
    printDLL(head);
    cout<<endl;

    Sollution obj;
    head=obj.removeDuplicates(head);
    printDLL(head);

    return 0;
}