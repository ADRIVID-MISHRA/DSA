#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp=node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete temp;
    }
};

void printLL(ListNode *head){
    ListNode *temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    ListNode *head = new ListNode(4);
    head->next=new ListNode(5);
    head->next->next=new ListNode(1);
    head->next->next->next=new ListNode(9);
    printLL(head);
    cout<<endl;

    Solution obj;
    obj.deleteNode(head->next);
    printLL(head);

    return 0;
}