//LC 2095
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
    ListNode* deleteMiddleBrute(ListNode *head){
        if(head==nullptr || head->next==nullptr){
            delete head;   //delete on nullptr does not give error
            return nullptr;
        }

        ListNode *temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }

        temp=head;
        cnt=cnt/2;
        while(cnt){
            cnt--;
            if(cnt==0){
                ListNode *del=temp->next;
                temp->next=temp->next->next;
                delete del;
                break;
            }
            temp=temp->next;
        }
        return head;
    }

    ListNode* deleteMiddleOptimal(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            delete head;   //delete on nullptr does not give error
            return nullptr;
        }

        ListNode *fast=head;
        ListNode *slow=head;
        fast=fast->next->next;   //start fast one step ahead
        // ListNode *prev=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            // prev=slow;
            slow=slow->next;
        }
        // prev->next=slow->next;
        // delete slow;
        ListNode *del=slow->next;
        slow->next=slow->next->next;
        delete del;
        return head;
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
    vector<int> arr={9,9,3,8,4,5};   
    
    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ll=obj.deleteMiddleBrute(ll);
    printLL(ll);
    cout<<endl;

    ll=obj.deleteMiddleOptimal(ll);
    printLL(ll);
    cout<<endl;

    return 0;
}