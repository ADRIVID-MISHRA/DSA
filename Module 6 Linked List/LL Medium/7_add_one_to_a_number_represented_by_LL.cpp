//LC 234
#include<iostream>
#include<vector>

using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addOne(ListNode* head) {
        ListNode *newHead=reverseList(head);
        ListNode *storeNewHead=newHead;
        
        while(newHead!=nullptr){
            if(newHead->val==9){
                newHead->val=0;
                if(newHead->next==nullptr){
                    newHead->next=new ListNode(1);
                    break;
                }
            }else{
                newHead->val=newHead->val+1;
                break;
            }
            newHead=newHead->next;
        }
        return reverseList(storeNewHead);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *temp=head;
        ListNode *prev=nullptr;

        while(temp!=nullptr){
            ListNode *front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
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
    vector<int> arr={9,9};
    
    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ll=obj.addOne(ll);
    printLL(ll);

    return 0;
}