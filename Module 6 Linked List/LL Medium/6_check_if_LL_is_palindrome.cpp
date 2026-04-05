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
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode *secondHalf=reverseList(slow->next);  //always the case, both in case of even and odd
        ListNode *firstHalf=head;

        ListNode *newHead=secondHalf;  //store reversed head for reversing again at the end
        while(secondHalf!=nullptr){
            if(firstHalf->val!=secondHalf->val) return false;
            secondHalf=secondHalf->next;
            firstHalf=firstHalf->next;
        }
        reverseList(newHead);
        return true;
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
    vector<int> arr={1,0,0,3,4,4,3,0,0,1};
    
    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    cout<<boolalpha<<obj.isPalindrome(ll);

    return 0;
}