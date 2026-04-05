//LC 206
#include<iostream>
#include<vector>
#include<stack>

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
    ListNode* reverseListBrute(ListNode* head) {
        stack<int> st;
        ListNode *temp=head;
        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }

    ListNode* reverseListOptimal(ListNode* head) {
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

    ListNode *reverseListRecursive(ListNode *head){
        if(head==nullptr || head->next==nullptr) return head;

        ListNode *newHead=reverseListRecursive(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
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
    vector<int> arr={1,0,0,3,4,9,9,9,3,4,9};
    
    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ll=obj.reverseListBrute(ll);
    printLL(ll);
    cout<<endl;

    ll=obj.reverseListOptimal(ll);
    printLL(ll);
    cout<<endl;
    
    ll=obj.reverseListRecursive(ll);
    printLL(ll);
    cout<<endl;

    return 0;
}