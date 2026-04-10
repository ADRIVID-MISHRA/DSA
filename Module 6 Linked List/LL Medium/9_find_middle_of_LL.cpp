//LC 876
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
    ListNode* middleNodeBrute(ListNode* head) {
        int cnt=0;
        ListNode *temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        cnt=cnt/2+1;   //location of middle node
        temp=head;
        while(cnt>1){
            temp=temp->next;
            cnt--;
        }
        return temp;
    }

    ListNode* middleNodeTortoiseHare(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
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
    vector<int> arr={9,9,3,8,4,5};   //8 is middle
    
    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ListNode *ans;
    ans=obj.middleNodeBrute(ll);
    cout<<ans->val<<endl;

    ans=obj.middleNodeTortoiseHare(ll);
    cout<<ans->val;

    return 0;
}