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
    ListNode *addOneIterative(ListNode* head) {
        // ListNode *newHead=reverseList(head);
        // ListNode *storeNewHead=newHead;
        
        // while(newHead!=nullptr){
        //     if(newHead->val==9){
        //         newHead->val=0;
        //         if(newHead->next==nullptr){
        //             newHead->next=new ListNode(1);
        //             break;
        //         }
        //     }else{
        //         newHead->val=newHead->val+1;
        //         break;
        //     }
        //     newHead=newHead->next;
        // }
        // return reverseList(storeNewHead);
        head=reverseList(head);
        int carry=1;    //adding one to LL

        ListNode *temp=head;
        while(temp!=nullptr){
            int newVal=carry+temp->val;
            carry=newVal/10;
            temp->val=newVal%10;
            if(carry==0) break;

            temp=temp->next;
        }
        head=reverseList(head);
        if(carry){
            head=new ListNode(carry,head);
        }
        return head;
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

    ListNode *addOneRecursive(ListNode *head){
        int carry=helper(head);

        if(carry){
            ListNode *newHead=new ListNode(1,head);
            head=newHead;
        }
        return head;
    }

    int helper(ListNode *temp){
        if(temp==nullptr){
            return 1;
        }

        int carry=helper(temp->next);
        temp->val+=carry;
        if(temp->val<10) return 0;
        temp->val=0;
        return 1;
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
    ll=obj.addOneIterative(ll);
    printLL(ll);
    cout<<endl;

    ll=obj.addOneRecursive(ll);
    printLL(ll);

    return 0;
}