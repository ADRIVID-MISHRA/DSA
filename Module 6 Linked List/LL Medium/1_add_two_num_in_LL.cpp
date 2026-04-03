//LC 2
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *temp1=l1, *temp2=l2;
        ListNode *newList=new ListNode(-1);   //dummy node
        ListNode *ans=newList;
        while(temp1!=nullptr || temp2!=nullptr){
            int sum=carry;
            if(temp1) sum+=temp1->val;
            if(temp2) sum+=temp2->val;
            newList->next=new ListNode(sum%10);
            carry=sum/10;

            newList=newList->next;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }

        if(carry!=0){
            newList->next=new ListNode(carry);
        }     
        ListNode *temp=ans;  //delete dummy node
        ans=ans->next; 
        delete temp;
        return ans;
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
    vector<int> arr1={3,4,9,9,9,3,4,9};
    vector<int> arr2={7,4,6,8,3,9,9,9,9,9,9,9,9};
    
    ListNode *l1=convertArrToLinkedList(arr1);
    printLL(l1);
    cout<<endl;

    ListNode *l2=convertArrToLinkedList(arr2);
    printLL(l2);
    cout<<endl;

    Solution obj;
    ListNode *sumNode=obj.addTwoNumbers(l1,l2);
    printLL(sumNode);

    return 0;
}