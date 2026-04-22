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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *prevNode=nullptr;
        while(temp!=nullptr){
            ListNode *kthNode=findkthNode(temp,k);
            if(kthNode==nullptr){     //if there are no more k elements left
                if(prevNode) prevNode->next=temp;    //check in case prevNode is null in case if the total length of LL is shorter than k
                break;
            }

            ListNode *nextNode=kthNode->next;
            kthNode->next=nullptr;
            ListNode *newHead=reverse(temp);    //new head is kth node
            if(temp==head){
                head=newHead;     //1st group
            }else{
                prevNode->next=newHead;    //any other group, connect previous group to current groups head
            }
            prevNode=temp;     //store prev groups last element for later linking
            temp=nextNode;
        }
        return head;
    }

    ListNode *findkthNode(ListNode *temp,int k){
        while(temp!=nullptr && k>1){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head) {
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
    vector<int> arr={9,9,3,8,4,5};   
    int k=2;

    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ll=obj.reverseKGroup(ll,k);
    printLL(ll);

    return 0;
}