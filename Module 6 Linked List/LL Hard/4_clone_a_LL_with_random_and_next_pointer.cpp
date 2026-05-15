//LC 138

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomListBrute(Node* head) {
        unordered_map<Node *,Node *> mpp;
        Node *temp=head;

        while(temp!=nullptr){
            Node *newNode=new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }

        //connect next and random pointers
        temp=head;
        while(temp!=nullptr){
            Node *copyNode=mpp[temp];    //(key: nullptr, value: nullptr) created here,, so it does not throw an error
            copyNode->next=mpp[temp->next];
            copyNode->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }

    Node* copyRandomListOptimal(Node* head) {
        Node *temp=head;
        while(temp!=nullptr){
            Node *newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;

            temp=temp->next->next;
        }

        temp=head;
        while(temp!=nullptr){
            Node *copyNode=temp->next;
            if(temp->random) copyNode->random=temp->random->next;
            else copyNode->random=nullptr;

            temp=temp->next->next;
        }

        temp=head;
        Node *restLL=new Node(-1);
        Node *newHead=restLL;
        while(temp!=nullptr){
            restLL->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            restLL=restLL->next;
        }
        // restLL->next=nullptr;
        Node *del=newHead;
        newHead=newHead->next;
        delete del;
        return newHead;
    }
};

// Utility functions
Node *convertArrToLinkedList(vector<int> &arr){
    Node *head=new Node(arr[0]);
    Node *mover=head;

    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover->random=mover;
        mover=temp;
    }
    mover->random=mover;
    return head;
}

void printLL(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<"Value: "<<temp->val<<" Temp: "<<temp<<" Next: "<<temp->next<<" Random: "<<temp->random<<endl;
        temp=temp->next;
    }
}

int main(){
    //make LL first
    vector<int> arr={9,9,3,8,4,5,3,4};   

    Node *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    Node *bruteLL=obj.copyRandomListBrute(ll);
    printLL(bruteLL);

    cout<<endl<<endl;
    Node *optimalLL=obj.copyRandomListOptimal(ll);
    printLL(optimalLL);

    return 0;
}