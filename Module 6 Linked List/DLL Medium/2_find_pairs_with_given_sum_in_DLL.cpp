#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data,Node *next=nullptr,Node *prev=nullptr){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};

class Sollution{
public:
    vector<pair<int,int>> findPairsBrute(Node *head,int sum){
        vector<pair<int,int>> ans;
        Node *temp1=head;
        while(temp1!=nullptr){
            Node *temp2=temp1->next;    //start one step ahead
            while(temp2!=nullptr && temp1->data+temp2->data<=sum){   //additional optimaization
                if(temp1->data+temp2->data==sum){
                    ans.push_back({temp1->data,temp2->data});
                }
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        return ans;
    }

    vector<pair<int,int>> findPairsOptimal(Node *head,int sum){
        vector<pair<int,int>> ans;
        if(head==nullptr) return ans;

        Node *tempi=head;
        Node *tempj=head;
        while(tempj->next!=nullptr) tempj=tempj->next;   //go to tail

        while(tempi->data < tempj->data){   //distinct, sorted values
            int currentSum=tempi->data+tempj->data;
            if(currentSum==sum){
                ans.push_back({tempi->data,tempj->data});
                tempi=tempi->next;
                tempj=tempj->prev;
            }
            else if(currentSum<sum){   
                tempi=tempi->next;
            }
            else{
                tempj=tempj->prev;
            }
        }
        return ans;
    }
};

//utility functions
Node *arrayToDLL(vector<int> &nums){
    Node *head=new Node(nums[0]);
    Node *previous=head;
    for(int i=1;i<nums.size();i++){
        Node *temp=new Node(nums[i],nullptr,previous);
        previous->next=temp;
        previous=temp;
    }
    return head;
}

void printDLL(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void printPair(vector<pair<int,int>> nums){
    for(auto pair:nums){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    cout<<endl;
}

int main(){
    vector<int> nums={1,2,3,4,9};
    int sum=5;
    Node *head=arrayToDLL(nums);
    printDLL(head);
    cout<<endl;

    Sollution obj;
    vector<pair<int,int>> ans=obj.findPairsBrute(head,sum);
    printPair(ans);

    ans=obj.findPairsOptimal(head,sum);
    printPair(ans);

    return 0;
}