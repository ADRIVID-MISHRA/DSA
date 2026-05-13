#include<iostream>
#include<vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // if(head==nullptr) return head;
        // ListNode *temp=head;
        // k=k%len(head);
        // if(k==0) return head;
        // while(k!=0){
        //     temp=temp->next;
        //     k--;
        // }
        // ListNode *newTail=head;
        // while(temp->next!=nullptr){
        //     temp=temp->next;
        //     newTail=newTail->next;
        // }

        // ListNode *newHead=newTail->next;
        // newTail->next=nullptr;
        // temp->next=head;
        // head=newHead;
        // return head;
        ListNode *currentTail=head;
        if(head==nullptr || head->next==nullptr) return head;
        int len=1;
        while(currentTail->next!=nullptr){    //find length and current tail of linked list
            len++;
            currentTail=currentTail->next;
        }
        k=k%len;
        if(k==0) return head;
        k=len-k;
        ListNode *newTail=head;
        while(--k){
            newTail=newTail->next;
        }

        currentTail->next=head;
        head=newTail->next;
        newTail->next=nullptr;

        return head;
    }

    // int lenghOftLL(ListNode *head){
    //     ListNode *temp=head;
    //     int cnt=0;
    //     while(temp!=nullptr){
    //         cnt++;
    //         temp=temp->next;
    //     }
    //     return cnt;
    // }
};

// Utility functions
ListNode *convertArrToLinkedList(vector<int> &arr){
    ListNode *head=new ListNode(arr[0]);
    ListNode *mover=head;

    for(int i=1;i<arr.size();i++){
        ListNode *temp=new ListNode(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void printLL(ListNode *head){
    ListNode *temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    //make LL first
    vector<int> arr={9,9,3,8,4,5};   
    int k=2;

    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ll=obj.rotateRight(ll,k);
    printLL(ll);

    return 0;
}