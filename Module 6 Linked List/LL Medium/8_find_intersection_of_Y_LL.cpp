//LC 160
#include<iostream>
#include<vector>
#include<unordered_map>
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
    ListNode *findIntersectionBrute(ListNode* head1,ListNode *head2) {
        unordered_map<ListNode *,int> mpp;

        ListNode *temp1=head1;
        ListNode *temp2=head2;

        while(temp1!=nullptr){
            mpp[temp1]++;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            if(mpp.find(temp2)!=mpp.end()) return temp2;
            temp2=temp2->next;
        }        
        return nullptr;
    }

    ListNode *findIntersectionBetter(ListNode *headA, ListNode *headB) {
        ListNode *a=headA;
        ListNode *b=headB;
        int n1=0,n2=0;

        while(a!=nullptr){
            n1++;
            a=a->next;
        }
        while(b!=nullptr){
            n2++;
            b=b->next;
        }
        
        if(n1>=n2){   //length of a>length of b
            return commonNode(headA,headB,n1-n2);
        }else{      //length of b>lenght of a
            return commonNode(headB,headA,n2-n1);
        }
    }

    ListNode *commonNode(ListNode *headA,ListNode *headB,int diff){   //a is larger LL and b is smaller LL
        ListNode *a=headA;
        ListNode *b=headB;
        
        while(diff){
            a=a->next;
            diff--;
        }
        // while(a!=nullptr && b!=nullptr){
        //     if(a==b) return a;
        //     a=a->next;
        //     b=b->next;
        // }
        // return nullptr;
        while(a!=b){
            a=a->next;
            b=b->next;
        }
        return a;
    }

    ListNode *findIntersectionOptimal(ListNode *headA, ListNode *headB) {
        ListNode *a=headA;
        ListNode *b=headB;

        while(a!=b){
            a=a->next;
            b=b->next;

            if(a==b) return a;

            if(a==nullptr) a=headB;
            if(b==nullptr) b=headA;
        }
        return a;
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
    vector<int> arr1={3,2};
    vector<int> arr2={9,9,4,6,567,8,9};
    
    ListNode *ll1=convertArrToLinkedList(arr1);
    ListNode *ll2=convertArrToLinkedList(arr2);
    ll1->next->next=ll2->next->next->next;    //intersecting at 6
    printLL(ll1);
    cout<<endl;
    printLL(ll2);
    cout<<endl;

    Solution obj;
    ListNode *ans=nullptr;
    ans=obj.findIntersectionBrute(ll1,ll2);
    cout<<ans->val;
    cout<<endl;

    ans=obj.findIntersectionBetter(ll1,ll2);
    cout<<ans->val;
    cout<<endl;

    ans=obj.findIntersectionOptimal(ll1,ll2);
    cout<<ans->val;
    cout<<endl;

    return 0;
}