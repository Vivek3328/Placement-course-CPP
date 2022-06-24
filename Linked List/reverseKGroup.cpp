#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

Node* takeInput()
{
    int data;
    cout<<"Enter Data:"<<" ";
    cin>>data;

    Node* head=NULL;
    Node* tail=NULL;

    while (data!=-1)
    {
        Node* newNode=new Node(data);

        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cout<<"Enter Data:"<<" ";
        cin>>data;
    }
    return head;
}

void print(Node* head)
{
    if(head==NULL)
    {
        return;
    }

    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

Node* reverseKGroup(Node* head, int k)
{
   
    Node* curr = head;
    Node* prev = NULL;
    Node* nextptr;
    int count=0;

    while(curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
   if(nextptr!=NULL)
   {
       head->next=reverseKGroup(nextptr,k);
   }
   head=prev;
   return head;
}

int main(int argc, char const *argv[])
{
    Node*head=takeInput();

    Node*rev=reverseKGroup(head,2);

    print(rev);
    
    return 0;
}
