//LC 19
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
    ListNode* removeNthBrute(ListNode* head,int n) {
        ListNode *temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }

        if(cnt==n){
            ListNode *del=head;
            head=head->next;
            return head;
        }
        temp=head;
        int c=0;
        while(temp!=nullptr){
            c++;
            if(c==cnt-n) break;
            temp=temp->next;
        }
        ListNode *del=temp->next;
        temp->next=temp->next->next;
        delete del;
        return head;
    }
    ListNode* removeNthOptimal(ListNode* head,int n) {
        ListNode *fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            ListNode *del=head;
            head=head->next;
            delete del;
            return head;
        }
        ListNode *slow=head;
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
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
    vector<int> arr={1,0,0,3,4,9,9,9,3,4,9};
    
    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ListNode *sortedList=obj.removeNthBrute(ll,2);
    printLL(sortedList);
    cout<<endl;

    sortedList=obj.removeNthOptimal(ll,2);
    printLL(sortedList);

    return 0;
}