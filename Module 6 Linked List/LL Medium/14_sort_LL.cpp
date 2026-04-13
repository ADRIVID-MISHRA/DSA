//LC 148
#include<iostream>
#include<vector>
#include<algorithm>

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
    ListNode* sortListBrute(ListNode* head) {
        ListNode *temp=head;
        vector<int> arr;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        temp=head;
        int i=0;
        while(temp!=nullptr){
            temp->val=arr[i++];
            temp=temp->next;
        }
        return head;
    }

    //Merge Sort
    ListNode* middleNode(ListNode* head) {    //give previous to middle node in case of even nodes
        ListNode *fast=head->next;   //start fast one place early ,,,,middle stops one place eary in even LL
        ListNode *slow=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *mergedList=new ListNode(-1);   //dummy Node
        ListNode *newTemp=mergedList;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                newTemp->next=list1;
                newTemp=newTemp->next;
                list1=list1->next;
            }else{
                newTemp->next=list2;
                newTemp=newTemp->next;
                list2=list2->next;
            }
        }

        newTemp->next=(list1==nullptr)?list2:list1;

        ListNode *dummy=mergedList;
        mergedList=mergedList->next;
        delete dummy;
        return mergedList;
    }

    ListNode *sortListMergeSort(ListNode *head){
        if(head==nullptr || head->next==nullptr) return head;

        ListNode *middle=middleNode(head);
        ListNode *left=head;
        ListNode *right=middle->next;
        middle->next=nullptr;

        left=sortListMergeSort(left);
        right=sortListMergeSort(right);
        return mergeTwoLists(left,right);
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
    ListNode *ans;
    ans=obj.sortListBrute(ll);
    printLL(ans);
    cout<<endl;

    return 0;
}