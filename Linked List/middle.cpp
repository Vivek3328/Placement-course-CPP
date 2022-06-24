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

void middle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    cout<<"Middle Element:"<<" "<<slow->data<<endl;
}


int main(int argc, char const *argv[])
{
    Node*head=takeInput();

    middle(head);

    
    
    
    return 0;
}
