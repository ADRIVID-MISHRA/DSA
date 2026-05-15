#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() : val(0), next(nullptr), child(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), child(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next), child(nullptr) {}
    ListNode(int x, ListNode *next,ListNode *child) : val(x),next(next), child(child) {}
};

class Solution {
public:
    ListNode *flattenLLBrute(ListNode *head){
        vector<int> nums;
        ListNode *parent=head;
        while(parent!=nullptr){
            ListNode *child=parent;
            while(child!=nullptr){
                nums.push_back(child->val);
                child=child->child;
            }
            parent=parent->next;
        }
        if(nums.empty()) return nullptr;
        sort(nums.begin(),nums.end());
        
        //build the Vertical Linked List
        ListNode *newLL=new ListNode(nums[0]);
        ListNode *temp=newLL;
        for(int i=1;i<nums.size();i++){
            temp->child=new ListNode(nums[i]);
            temp=temp->child;
        }
        return newLL;
    }


    // optimal approach (recursive flatten + iterative merge)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *mergedList=new ListNode(-1);   //dummy Node
        ListNode *newTemp=mergedList;
        // list1->next=nullptr;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                newTemp->child=list1;
                newTemp=newTemp->child;
                list1=list1->child;
            }else{
                newTemp->child=list2;
                newTemp=newTemp->child;
                list2=list2->child;
            }
            newTemp->next=nullptr;
        }

        newTemp->child=(list1==nullptr)?list2:list1;

        ListNode *dummy=mergedList;
        mergedList=mergedList->child;
        delete dummy;
        return mergedList;
    }

    ListNode *flattenLLOptimal(ListNode *head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode *mergedHead=flattenLLOptimal(head->next);
        return mergeTwoLists(head,mergedHead);
    }
};

// Utility functions

//my initial implemnetation
// ListNode *convertArrToLinkedList(vector<int> &arr){
//     ListNode *head=new ListNode(arr[0]);
//     ListNode *mover=head;
//     vector<int> nest={0,2,4,3,1};
//     int r=0;
//     int i=1;

//     while(i<arr.size()){
//         ListNode *temp=mover;
//         // mover->next=new ListNode(arr[i++]);
//         for(int j=0;j<nest[r] && i<arr.size();j++){
//             ListNode *newNode=new ListNode(arr[i++]);
//             temp->child=newNode;
//             temp=temp->child;
//         }
//         r++;
//         // mover->next=newNode
//         mover->next=new ListNode(arr[i++]);
//         mover=mover->next;
//     }
//     return head;
// }

ListNode* buildList(vector<vector<int>>& data) {

    if(data.empty()) return nullptr;

    ListNode* head = nullptr;
    ListNode* prev = nullptr;

    for(auto &row : data){

        ListNode* mainNode = new ListNode(row[0]);

        if(!head){
            head = mainNode;
        }
        else{
            prev->next = mainNode;
        }

        prev = mainNode;

        ListNode* childMover = mainNode;

        for(int i=1; i<row.size(); i++){

            childMover->child = new ListNode(row[i]);
            childMover = childMover->child;
        }
    }

    return head;
}

void printLL(ListNode *head){
    ListNode *temp=head;
    while(temp!=nullptr){
        ListNode *child=temp;
        while(child!=nullptr){
            cout<<child->val<<" ";
            child=child->child;
        }  
        temp=temp->next; 
        cout<<endl;
    }
}

int main(){
    //make LL first
    vector<vector<int>> arr={
        {3,4,5},
        {1,2,7,8,9},
        {6,10,15},
        {11},
        {13,14}
    };   

    ListNode *ll=buildList(arr);
    printLL(ll);
    cout<<endl;

    Solution obj;
    ListNode *bruteLL=obj.flattenLLBrute(ll);
    printLL(bruteLL);
    cout<<endl<<endl;

    ListNode *optimalLL=obj.flattenLLOptimal(ll);
    printLL(optimalLL);
    return 0;
}