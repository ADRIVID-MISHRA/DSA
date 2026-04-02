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

//Deletions
Node *deleteHead(Node *head){
    if(head==nullptr) return head;
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    
    Node *temp=head;
    head=head->next;
    head->prev=nullptr;
    delete temp;
    return head;
}

Node *deleteTail(Node *head){
    if(head==nullptr) return head;

    if(head->next==nullptr){
        delete head;
        return nullptr;
    }

    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node *previous=temp->prev;
    previous->next=nullptr;
    delete temp;
    return head;
}

Node *deleteKthElement(Node *head,int k){
    if(head==nullptr) return head;

    Node *temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    Node *prevNode=temp->prev;
    Node *nextNode=temp->next;
    
    if(prevNode==nullptr && nextNode==nullptr){  //single element DLL
        delete temp;
        return nullptr;
    }
    else if(prevNode==nullptr){    //k==1
        return deleteHead(head);
    }
    else if(nextNode==nullptr){    //k==n
        return deleteTail(head);
    }
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    delete temp;
    return head;
}

Node *deleteElement(Node *head,int element){
    if(head==nullptr) return head;

    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==element){
            break;
        }
        temp=temp->next;
    }
    Node *prevNode=temp->prev;
    Node *nextNode=temp->next;
    
    if(prevNode==nullptr && nextNode==nullptr){  //single element DLL
        delete temp;
        return nullptr;
    }
    else if(prevNode==nullptr){    //k==1
        return deleteHead(head);
    }
    else if(nextNode==nullptr){    //k==n
        return deleteTail(head);
    }
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    delete temp;
    return head;
}

void deleteNode(Node *node){
    Node *prevNode=node->prev;
    Node *nextNode=node->next;

    if(nextNode==nullptr){  //tail
        prevNode->next=nullptr;
        delete node;
        return;
    }

    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    delete node;
    return;
}

//insertions
Node *insertBeforeHead(Node *head,int val){
    Node *newHead=new Node(val,head,nullptr);
    if(head!=nullptr) head->prev=newHead;
    return newHead;
}

Node *insertBeforeTail(Node *head,int val){
    if(head==nullptr){
        return new Node(val);
    }
    if(head->next==nullptr){
        return insertBeforeHead(head,val);  
    }

    Node *tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    Node *previous=tail->prev;
    Node *newNode=new Node(val,tail,previous);
    previous->next=newNode;
    tail->prev=newNode;

    return head;
}

Node *insertBeforeKthElement(Node *head,int val,int k){
    if(k==1) return insertBeforeHead(head,val);

    Node *temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    } 
    
    Node *previous=temp->prev;
    Node *newNode=new Node(val,temp,previous);
    previous->next=newNode;
    temp->prev=newNode;

    return head;
}

void insertBeforeNode(Node *node,int val){
    Node *previous=node->prev;

    Node *newNode=new Node(val,node,previous);
    previous->next=newNode;
    node->prev=newNode;
    return;
}

Node *insertTail(Node *head,int val){
    if(head==nullptr) return new Node(val);

    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node *newNode=new Node(val,nullptr,temp);
    temp->next=newNode;

    return head;
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
    vector<int> nums={34,35,345,325,246,526,54,725,64,42,23,534,6,27,56837,56,46,25,62,6,2};
    Node *head=arrayToDLL(nums);
    printDLL(head);
    cout<<endl;

    //Deletions
    head=deleteHead(head);
    printDLL(head);
    cout<<endl;

    head=deleteTail(head);
    printDLL(head);
    cout<<endl;

    head=deleteKthElement(head,3);
    printDLL(head);
    cout<<endl;

    head=deleteElement(head,54);
    printDLL(head);
    cout<<endl;

    deleteNode(head->next->next->next);
    printDLL(head);
    cout<<endl;

    // insertions
    head=insertBeforeHead(head,69);
    printDLL(head);
    cout<<endl;

    head=insertBeforeTail(head,69);
    printDLL(head);
    cout<<endl;

    head=insertBeforeKthElement(head,69,4);
    printDLL(head);
    cout<<endl;

    insertBeforeNode(head->next->next->next,78);
    printDLL(head);
    cout<<endl;

    head=insertTail(head,8888);
    printDLL(head);
    cout<<endl;

    return 0;
}