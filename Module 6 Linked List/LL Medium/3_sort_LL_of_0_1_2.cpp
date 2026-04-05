//NO LC
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
    ListNode* sort012(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode *l0=new ListNode(-1);
        ListNode *head0=l0;
        ListNode *l1=new ListNode(-1);
        ListNode *head1=l1;
        ListNode *l2=new ListNode(-1);
        ListNode *head2=l2;

        ListNode *temp=head;
        
        while(temp!=nullptr){
            if(temp->val==0){
                l0->next=temp;
                l0=l0->next;
            }
            else if(temp->val==1){
                l1->next=temp;
                l1=l1->next;
            }
            else{
                l2->next=temp;
                l2=l2->next;
            }
            temp=temp->next;
        }
        l0->next=(l1->next)?head1->next:head2->next;
        l1->next=head2->next;
        l2->next=nullptr;

        ListNode *newHead=head0->next;
        delete head0;
        delete head1;
        delete head2;
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
    vector<int> arr={1,0,0,2,2,1,2,0,2,1,0,2,1,1,0};
    
    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ListNode *sortedList=obj.sort012(ll);
    printLL(sortedList);

    return 0;
}