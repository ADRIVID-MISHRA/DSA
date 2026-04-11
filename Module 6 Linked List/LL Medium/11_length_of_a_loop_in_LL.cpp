//NO LC
#include<iostream>
#include<vector>
#include<unordered_map>

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
    int lengthOfLoopHashing(ListNode *head){
        int pos=1;
        unordered_map<ListNode *,int> mpp;
        
        ListNode *temp=head;
        while(temp!=nullptr){
            if(mpp.find(temp)!=mpp.end()){
                return pos-mpp[temp];
            }
            mpp[temp]=pos++;
            temp=temp->next;
        }
        return 0;
    }

    int lengthOfLoopTortoiseHare(ListNode *head){
        ListNode *fast=head;
        ListNode *slow=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                int cnt=1;
                fast=fast->next;
                while(fast!=slow){
                    fast=fast->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
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
    vector<int> arr={9,9,3,8,4,5};   //5 is pointing to 3  so lenth of loop is 4
    
    ListNode *ll=convertArrToLinkedList(arr);
    printLL(ll);
    ll->next->next->next->next->next->next=ll->next->next;
    cout<<endl;

    Solution obj;
    cout<<obj.lengthOfLoopHashing(ll)<<endl;
    cout<<obj.lengthOfLoopTortoiseHare(ll);

    return 0;
}