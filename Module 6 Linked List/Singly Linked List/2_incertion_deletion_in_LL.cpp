#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val,Node *nxt=nullptr){
        data=val;
        next= nxt;
    }
};

//Deletion functions
Node *deleteHead(Node *head){
    if(head==nullptr) return head;
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head){
    if(head==nullptr || head->next==nullptr) return nullptr;

    Node *temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

Node *deleteKthPosition(Node *head,int k){
    if(head==nullptr) return head;
    if(k==1){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node *temp=head,*prev=nullptr;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            // return head;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node *deleteElement(Node *head,int element){
    if(head==nullptr) return head;
    if(head->data==element){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node *temp=head,*prev=nullptr;
    while(temp!=nullptr){
        if(temp->data==element){
            prev->next=prev->next->next;
            delete temp;
            // return head;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//Incertion functions
Node *insertHead(Node *head,int val){
    return new Node(val,head);
    // Node *temp=new Node(val,head);
    // temp->next=head;
    // return temp;
}

Node *insertTail(Node *head,int val){
    if(head==nullptr){
        return new Node(val);
    }
    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=new Node(val);
    return head;
}

Node *insertAtKthPosition(Node *head,int val,int k){
    if(k==1) return new Node(val,head);

    if(head==nullptr) return nullptr;
   
    Node *temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k-1){
            temp->next=new Node(val,temp->next);
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node *insertBeforeElement(Node *head,int val,int element){
    if(head==nullptr) return head;
    if(head->data==element) return new Node(val,head);

    Node *temp=head;
    while(temp->next != nullptr){
        if(temp->next->data==element){
            temp->next=new Node(val,temp->next);
            break;
        }
        temp=temp->next;
    }
    return head;
}

// Utility functions
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

int main(){
    //make LL first
    vector<int> arr={23,44,22,12,45};
    Node *head=convertArrToLinkedList(arr);
    printLL(head);
    cout<<endl;

    //Deletion
    head=deleteHead(head);
    printLL(head);
    cout<<endl;

    head=deleteTail(head);
    printLL(head);
    cout<<endl;
    
    head=deleteKthPosition(head,2);
    printLL(head);
    cout<<endl;

    head=deleteElement(head,44);
    printLL(head);
    cout<<endl;

    //incertion
    head=insertHead(head,1);
    printLL(head);
    cout<<endl;

    head=insertTail(head,2);
    printLL(head);
    cout<<endl;

    head=insertAtKthPosition(head,69,4);
    printLL(head);
    cout<<endl;

    head=insertBeforeElement(head,60,69);
    printLL(head);
    cout<<endl;
    return 0;
}